#include <stdio.h>
#include <string.h>
#include "webrtc_apm_wrapper.h"

int main(int ac, char *av[])
{
	FILE *fp_far, *fp_near;
	short buf_near[2048], buf_far[2048], buf_out[2048];
	FILE *fp_out;
	int period_samples = 16000 * 10 / 1000;
	int ret;
	HANDLE_APM h_apm;
    ApmConfig cfg;
    int has_voice;


    if (ac !=4){
        printf("usage: %s near.pcm far.pcm out.pcm (all pcm in 16bit1ch format)\n", av[0]);
        return 0;
    }
    
    memset(&cfg, 0, sizeof(cfg));
    
    cfg.i_aec = 1;
    cfg.i_aecm = 0;
    cfg.i_extended_filter_aec = 1;
    cfg.i_delay_agnostic_aec = 1;
    cfg.i_residual_echo_detector = 1;
    
    cfg.i_agc2 = 1;
    cfg.i_agc_use_adaptive_digital = 1;

    cfg.i_ns = 1;
    cfg.i_ns_level = 2;

    cfg.i_vad = 1;
    cfg.i_vad_likelihood = 1;

    cfg.i_sample_rate = 16000;
    cfg.i_channels = 1;
    
    
	fp_far = fopen(av[2], "rb"); 
	if (!fp_far) 
		return 0; 

	fp_near = fopen(av[1], "rb");
	if (!fp_near)
		return 0;

	fp_out = fopen(av[3], "wb");
	if (!fp_out)
		return 0;

    h_apm = apm_create(&cfg);


	while(1){
		ret = fread(buf_near, sizeof(short), period_samples, fp_near);
		if (ret != period_samples)
			break;

		ret = fread(buf_far, sizeof(short), period_samples, fp_far);
		if (ret != period_samples)
			break;

	    apm_set_stream_delay_ms(h_apm, 60);
		apm_process_reverse_stream(h_apm, buf_far, buf_far, period_samples);
		apm_process_stream(h_apm, buf_out, buf_near, period_samples);

        has_voice = apm_stream_has_voice(h_apm);

        if (1){
            int level;
            apm_set_analog_cap_level_range(h_apm, 0, 255);
            level = apm_get_recommand_cap_level(h_apm);
            apm_set_current_cap_level(h_apm, level);
        }
		fwrite(buf_out, sizeof(short) , period_samples, fp_out);
	}

    apm_release(h_apm);
    
	fclose(fp_out);
	fclose(fp_near);
	fclose(fp_far); 

}



