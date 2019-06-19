#ifndef __WEBRTC_APM_WRAPPER_H
#define __WEBRTC_APM_WRAPPER_H

#ifdef __cplusplus
extern "C"
{
#endif 

#ifdef _WIN32 
#define APM_DLL_EXPORT __declspec(dllexport)
#else 
#define APM_DLL_EXPORT
#endif 

typedef void * HANDLE_APM;

typedef struct _ApmConfig
{
    //aec config 
	int i_aecm;
    int i_aec; // aec3 , enable this aecm will be closed 
	int i_extended_filter_aec;
	int i_delay_agnostic_aec;
	int i_residual_echo_detector;

    // agc config 
    int i_agc;    
    int i_agc2; // enable agc2 will close agc 

    int i_agc_use_adaptive_digital; // digital or analog 
    
    //ns config 
	int i_ns;
    int i_ns_level; // 0 - 3 

    //vad
    int i_vad;
    int i_vad_likelihood; // 0 - 3

    // samples 
    
    int i_sample_rate;
    int i_channels;

}ApmConfig;


APM_DLL_EXPORT HANDLE_APM apm_create(ApmConfig *cfg);

/*call apm_set_stream_delay_ms before apm_process_stream for every frame*/
APM_DLL_EXPORT void apm_set_stream_delay_ms(HANDLE_APM apm, int delay_ms);

APM_DLL_EXPORT int apm_process_stream(HANDLE_APM apm, short *out_pcm, short *in_pcm, int n_samples_per_channel);

APM_DLL_EXPORT int apm_process_reverse_stream(HANDLE_APM apm, short *out_pcm, short *in_pcm, int n_samples_per_channel);

//call this after apm_process_stream
APM_DLL_EXPORT int apm_stream_has_voice(HANDLE_APM apm);


// analog agc mode , is user responsibility to control hardware level
APM_DLL_EXPORT int apm_set_analog_cap_level_range(HANDLE_APM apm, int min, int max);

// When an analog mode is set, this must be called prior to |ProcessStream()|
// to pass the current analog level from the audio HAL. Must be within the
// range provided to |set_analog_level_limits()|.
APM_DLL_EXPORT int apm_set_current_cap_level(HANDLE_APM apm, int level);

// When an analog mode is set, this should be called after |ProcessStream()|
// to obtain the recommended new analog level for the audio HAL. It is the
// users responsibility to apply this level.
APM_DLL_EXPORT int apm_get_recommand_cap_level(HANDLE_APM apm);

APM_DLL_EXPORT void apm_release(HANDLE_APM apm);



#ifdef __cplusplus
}
#endif 

#endif 

