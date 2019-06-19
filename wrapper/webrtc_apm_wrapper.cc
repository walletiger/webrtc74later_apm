#include <malloc.h>
#include <iostream>
#include <list>

#include <common_types.h>
//#include <webrtc/modules/include/module_common_types.h>
#include <webrtc/modules/audio_processing/include/audio_processing.h>
#include <api/audio/audio_frame.h>

using namespace std; 
using namespace webrtc;

#include "webrtc_apm_wrapper.h"


typedef struct _ApmContext
{
    AudioProcessing        *h_apm;
    ApmConfig               config;
    int                     i_delay_ms;
    
    AudioFrame              *local_frame;
    AudioFrame              *remote_frame;    
}ApmContext;

APM_DLL_EXPORT HANDLE_APM apm_create(ApmConfig *cfg)
{
    ApmContext *ctx;
    AudioProcessing::Config apm_config;
    webrtc::Config extra_config;
    
    ctx = (ApmContext *)calloc(1, sizeof(ApmContext));

    if (!ctx)
        return NULL;

    ctx->config = *cfg;
    
    ctx->h_apm = AudioProcessingBuilder().Create();
    ctx->i_delay_ms = 50; // default 50ms 

    apm_config = ctx->h_apm->GetConfig();

    apm_config.high_pass_filter.enabled = true;
    apm_config.voice_detection.enabled = cfg->i_vad;
    
    //aec 
    if (cfg->i_aecm || cfg->i_aec){
        apm_config.echo_canceller.enabled = true;
        apm_config.residual_echo_detector.enabled = cfg->i_residual_echo_detector;
    
        if (cfg->i_aec){ // aec3 , enable aec2 to open use_legacy_aec
            apm_config.echo_canceller.mobile_mode = false;
            if (cfg->i_delay_agnostic_aec){
                extra_config.Set<webrtc::DelayAgnostic>(
                    new webrtc::DelayAgnostic(cfg->i_delay_agnostic_aec));
            }
            if (cfg->i_extended_filter_aec) {
                extra_config.Set<webrtc::ExtendedFilter>(
                  new webrtc::ExtendedFilter(cfg->i_extended_filter_aec));
            }
        }else {
            apm_config.echo_canceller.mobile_mode = true;
        }
    }

    //agc 
    if (cfg->i_agc || cfg->i_agc2){
        if (cfg->i_agc2){
            apm_config.gain_controller2.enabled = true;
            apm_config.gain_controller1.enabled = false;
        }else {
            apm_config.gain_controller2.enabled = false;
            apm_config.gain_controller1.enabled = true;
        }
    }

    ctx->h_apm->ApplyConfig(apm_config);
    ctx->h_apm->SetExtraOptions(extra_config);
    
   
    //ns     
    if (cfg->i_ns){
        NoiseSuppression* ns = ctx->h_apm->noise_suppression();
        ns->set_level((webrtc::NoiseSuppression::Level)cfg->i_ns_level);
        ns->Enable(true);
    }

    //agc 
    if (cfg->i_agc || cfg->i_agc2){
        if (cfg->i_agc_use_adaptive_digital){
            ctx->h_apm->gain_control()->set_mode(GainControl::Mode::kAdaptiveDigital);
        }else {
            ctx->h_apm->gain_control()->set_analog_level_limits(0, 255);
            ctx->h_apm->gain_control()->set_mode(GainControl::Mode::kAdaptiveAnalog);
        }
        if (cfg->i_agc){
            //ctx->h_apm->gain_control()->set_target_level_dbfs(agc_target_level);
            //ctx->h_apm->gain_control()->set_compression_gain_db(agc_max_gain);            
        }
        ctx->h_apm->gain_control()->enable_limiter(true);
        ctx->h_apm->gain_control()->Enable(true);
    }

    if (cfg->i_vad){
	    ctx->h_apm->voice_detection()->set_likelihood((VoiceDetection::Likelihood)cfg->i_vad_likelihood);
        ctx->h_apm->voice_detection()->Enable(true);
    }

    // init audio frames 
    {
        ctx->local_frame = new AudioFrame();
        
        ctx->local_frame->num_channels_ = cfg->i_channels;
        ctx->local_frame->sample_rate_hz_ = cfg->i_sample_rate;
        ctx->local_frame->samples_per_channel_ = (size_t)AudioProcessing::kChunkSizeMs * cfg->i_sample_rate /1000;
        ctx->local_frame->speech_type_ = AudioFrame::SpeechType::kNormalSpeech;
        ctx->local_frame->vad_activity_ = AudioFrame::VADActivity::kVadActive;

        ctx->remote_frame = new AudioFrame();
        
        ctx->remote_frame->num_channels_ = cfg->i_channels;
        ctx->remote_frame->sample_rate_hz_ = cfg->i_sample_rate;
        ctx->remote_frame->samples_per_channel_ = (size_t)AudioProcessing::kChunkSizeMs * cfg->i_sample_rate /1000;
        ctx->remote_frame->speech_type_ = AudioFrame::SpeechType::kNormalSpeech;
        ctx->remote_frame->vad_activity_ = AudioFrame::VADActivity::kVadActive;
    }

    ctx->h_apm->Initialize(cfg->i_sample_rate, cfg->i_sample_rate, cfg->i_sample_rate, 
        cfg->i_channels < 2 ? AudioProcessing::ChannelLayout::kMono : AudioProcessing::ChannelLayout::kStereo,
        cfg->i_channels < 2 ? AudioProcessing::ChannelLayout::kMono : AudioProcessing::ChannelLayout::kStereo,
        cfg->i_channels < 2 ? AudioProcessing::ChannelLayout::kMono : AudioProcessing::ChannelLayout::kStereo);

    return (HANDLE_APM *)ctx;
}

APM_DLL_EXPORT void apm_set_stream_delay_ms(HANDLE_APM apm, int delay_ms)
{
    ApmContext *ctx;

    ctx = (ApmContext *)apm;

    ctx->i_delay_ms = delay_ms;
}


APM_DLL_EXPORT int apm_set_analog_cap_level_range(HANDLE_APM apm, int min, int max)
{
    ApmContext *ctx;

    ctx = (ApmContext *)apm;
    ctx->h_apm->gain_control()->set_analog_level_limits(min, max);

    return 0;
}

APM_DLL_EXPORT int apm_set_current_cap_level(HANDLE_APM apm, int level)
{
    ApmContext *ctx;

    ctx = (ApmContext *)apm;
    ctx->h_apm->gain_control()->set_stream_analog_level(level);

    return 0;
}

APM_DLL_EXPORT int apm_process_stream(HANDLE_APM apm, short *out_pcm, short *in_pcm, int n_samples_per_channel)
{
    ApmContext *ctx;
    ctx = (ApmContext *)apm;
	AudioFrame *p_frame;
    int i;
    
	p_frame = ctx->local_frame;

    i = 0;
	while (n_samples_per_channel > 0)
	{
		short *frame_data;
		frame_data = p_frame->mutable_data();
		memcpy(frame_data, in_pcm + i * p_frame->samples_per_channel_ * p_frame->num_channels_ , p_frame->samples_per_channel_ * sizeof(short) * p_frame->num_channels_);
        ctx->h_apm->set_stream_delay_ms(ctx->i_delay_ms);
        ctx->h_apm->ProcessStream(p_frame);

        if (out_pcm)
            memcpy(out_pcm + i * p_frame->samples_per_channel_ * p_frame->num_channels_, frame_data, p_frame->samples_per_channel_ * sizeof(short) * p_frame->num_channels_);

        n_samples_per_channel -= p_frame->samples_per_channel_;
	}
	return 0;

}

APM_DLL_EXPORT int apm_stream_has_voice(HANDLE_APM apm)
{
    ApmContext *ctx;

    ctx = (ApmContext *)apm;

    return ctx->h_apm->voice_detection()->stream_has_voice();
}


APM_DLL_EXPORT int apm_process_reverse_stream(HANDLE_APM apm, short *out_pcm, short *in_pcm, int n_samples_per_channel)
{
    ApmContext *ctx;
    ctx = (ApmContext *)apm;
	AudioFrame *p_frame;
    int i;
    
	p_frame = ctx->remote_frame;

    i = 0;
    
	while (n_samples_per_channel > 0)
	{
		short *frame_data;
		frame_data = p_frame->mutable_data();
		memcpy(frame_data, in_pcm + i * p_frame->samples_per_channel_ * p_frame->num_channels_ , p_frame->samples_per_channel_ * sizeof(short) * p_frame->num_channels_);
        ctx->h_apm->ProcessReverseStream(p_frame);

        if (out_pcm)
            memcpy(out_pcm + i * p_frame->samples_per_channel_ * p_frame->num_channels_, frame_data, p_frame->samples_per_channel_ * sizeof(short) * p_frame->num_channels_);
        
        n_samples_per_channel -= p_frame->samples_per_channel_;
	}

	return 0;

}


APM_DLL_EXPORT int apm_get_recommand_cap_level(HANDLE_APM apm)
{
    ApmContext *ctx;

    ctx = (ApmContext *)apm;
    
    return ctx->h_apm->gain_control()->stream_analog_level();

}

APM_DLL_EXPORT void apm_release(HANDLE_APM apm)
{
    ApmContext *ctx;

    ctx = (ApmContext *)apm;

    if (ctx->local_frame){
        delete ctx->local_frame;
    }

    if (ctx->remote_frame){
        delete ctx->remote_frame;
    }

    if (ctx->h_apm){
        delete ctx->h_apm;
        ctx->h_apm = NULL;
    }

    free(ctx);
    
}




