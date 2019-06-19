lib_LTLIBRARIES = libwebrtc_audio_processing.la


libwebrtc_audio_processing_la_SOURCES = include/audio_processing.cc \
					include/audio_processing.h \
					include/config.cc \
					include/config.h \
					include/aec_dump.h \
					include/aec_dump.cc \
					include/audio_frame_view.h \
					include/audio_generator_factory.h  \
					include/audio_generator_factory.cc \
					include/audio_generator.h \
					include/audio_processing_statistics.h \
					include/audio_processing_statistics.cc \
					include/gain_control.h \
                    audio_generator/file_audio_generator.h \
                    audio_generator/file_audio_generator.cc \
					aec/aec_common.h \
					aec/aec_core.cc \
					aec/aec_core.h \
					aec/aec_core_optimized_moethods.h \
					aec/aec_resampler.cc \
					aec/aec_resampler.h \
					aec/echo_cancellation.cc \
					aec/echo_cancellation.h \
					aec3/adaptive_fir_filter.cc \
					aec3/adaptive_fir_filter.h \
					aec3/aec3_common.cc \
					aec3/aec3_common.h \
					aec3/aec3_fft.cc \
					aec3/aec3_fft.h \
					aec3/aec_state.cc \
					aec3/aec_state.h \
					aec3/api_call_jitter_metrics.cc \
					aec3/api_call_jitter_metrics.h \
					aec3/block_delay_buffer.cc \
					aec3/block_delay_buffer.h \
					aec3/block_framer.cc \
					aec3/block_framer.h \
					aec3/block_processor.cc \
					aec3/block_processor.h \
					aec3/block_processor_metrics.cc \
					aec3/block_processor_metrics.h \
					aec3/cascaded_biquad_filter.cc \
					aec3/cascaded_biquad_filter.h \
					aec3/clockdrift_detector.cc \
					aec3/clockdrift_detector.h \
					aec3/comfort_noise_generator.cc \
					aec3/comfort_noise_generator.h \
					aec3/decimator.cc \
					aec3/decimator.h \
					aec3/delay_estimate.h \
					aec3/downsampled_render_buffer.cc \
					aec3/downsampled_render_buffer.h \
					aec3/echo_audibility.cc \
					aec3/echo_audibility.h \
					aec3/echo_canceller3.cc \
					aec3/echo_canceller3.h \
					aec3/echo_path_delay_estimator.cc \
					aec3/echo_path_delay_estimator.h \
					aec3/echo_path_variability.cc \
					aec3/echo_path_variability.h \
					aec3/echo_remover.cc \
					aec3/echo_remover.h \
					aec3/echo_remover_metrics.cc \
					aec3/echo_remover_metrics.h \
					aec3/erle_estimator.cc \
					aec3/erle_estimator.h \
					aec3/erl_estimator.cc \
					aec3/erl_estimator.h \
					aec3/fft_buffer.cc \
					aec3/fft_buffer.h \
					aec3/fft_data.h \
					aec3/filter_analyzer.cc \
					aec3/filter_analyzer.h \
					aec3/frame_blocker.cc \
					aec3/frame_blocker.h \
					aec3/fullband_erle_estimator.cc \
					aec3/fullband_erle_estimator.h \
					aec3/main_filter_update_gain.cc \
					aec3/main_filter_update_gain.h \
					aec3/matched_filter.cc \
					aec3/matched_filter.h \
					aec3/matched_filter_lag_aggregator.cc \
					aec3/matched_filter_lag_aggregator.h \
					aec3/matrix_buffer.cc \
					aec3/matrix_buffer.h \
					aec3/moving_average.cc \
					aec3/moving_average.h \
					aec3/render_buffer.cc \
					aec3/render_buffer.h \
					aec3/render_delay_buffer.cc \
					aec3/render_delay_buffer.h \
					aec3/render_delay_controller.cc \
					aec3/render_delay_controller.h \
					aec3/render_delay_controller_metrics.cc \
					aec3/render_delay_controller_metrics.h \
					aec3/render_reverb_model.cc \
					aec3/render_reverb_model.h \
					aec3/render_signal_analyzer.cc \
					aec3/render_signal_analyzer.h \
					aec3/residual_echo_estimator.cc \
					aec3/residual_echo_estimator.h \
					aec3/reverb_decay_estimator.cc \
					aec3/reverb_decay_estimator.h \
					aec3/reverb_frequency_response.cc \
					aec3/reverb_frequency_response.h \
					aec3/reverb_model.cc \
					aec3/reverb_model_estimator.cc \
					aec3/reverb_model_estimator.h \
					aec3/reverb_model_fallback.cc \
					aec3/reverb_model_fallback.h \
					aec3/reverb_model.h \
					aec3/shadow_filter_update_gain.cc \
					aec3/shadow_filter_update_gain.h \
					aec3/signal_dependent_erle_estimator.cc \
					aec3/signal_dependent_erle_estimator.h \
					aec3/stationarity_estimator.cc \
					aec3/stationarity_estimator.h \
					aec3/subband_erle_estimator.cc \
					aec3/subband_erle_estimator.h \
					aec3/subtractor.cc \
					aec3/subtractor.h \
					aec3/subtractor_output_analyzer.cc \
					aec3/subtractor_output_analyzer.h \
					aec3/subtractor_output.cc \
					aec3/subtractor_output.h \
					aec3/suppression_filter.cc \
					aec3/suppression_filter.h \
					aec3/suppression_gain.cc \
					aec3/suppression_gain.h \
					aec3/vector_buffer.cc \
					aec3/vector_buffer.h \
					aec3/vector_math.h \
					aecm/echo_control_mobile.cc \
					aecm/echo_control_mobile.h \
					aecm/aecm_core.cc \
					aecm/aecm_core.h \
					aecm/aecm_core_c.cc \
					aecm/aecm_defines.h \
					agc/legacy/analog_agc.c \
					agc/legacy/analog_agc.h \
					agc/legacy/digital_agc.c \
					agc/legacy/digital_agc.h \
					agc/legacy/gain_control.h \
					agc/agc.cc \
					agc/agc.h \
					agc/agc_manager_direct.cc \
					agc/agc_manager_direct.h \
					agc/gain_map_internal.h \
					agc/loudness_histogram.cc \
					agc/loudness_histogram.h \
					agc/utility.cc \
					agc/utility.h \
					echo_detector/circular_buffer.cc \
					echo_detector/circular_buffer.h \
					echo_detector/mean_variance_estimator.cc \
					echo_detector/mean_variance_estimator.h \
					echo_detector/moving_max.cc \
					echo_detector/moving_max.h \
					echo_detector/normalized_covariance_estimator.cc \
					echo_detector/normalized_covariance_estimator.h \
					logging/apm_data_dumper.cc \
					logging/apm_data_dumper.h \
					transient/common.h \
					transient/daubechies_8_wavelet_coeffs.h \
					transient/dyadic_decimator.h \
					transient/file_utils.h \
					transient/moving_moments.h \
					transient/transient_detector.h \
					transient/transient_suppressor.h \
					transient/wpd_node.h \
					transient/wpd_tree.h \
					transient/file_utils.cc \
					transient/moving_moments.cc \
					transient/transient_detector.cc \
					transient/transient_suppressor.cc \
					transient/wpd_node.cc \
					transient/wpd_tree.cc \
					utility/block_mean_calculator.cc \
					utility/block_mean_calculator.h \
					utility/delay_estimator.cc \
					utility/delay_estimator.h \
					utility/delay_estimator_internal.h \
					utility/delay_estimator_wrapper.cc \
					utility/delay_estimator_wrapper.h \
					utility/ooura_fft.cc \
					utility/ooura_fft.h \
					utility/ooura_fft_tables_common.h \
					utility/pffft_wrapper.cc \
					utility/pffft_wrapper.h \
					vad/common.h \
					vad/gmm.h \
					vad/noise_gmm_tables.h \
					vad/pitch_based_vad.h \
					vad/pitch_internal.h \
					vad/pole_zero_filter.h \
					vad/standalone_vad.h \
					vad/vad_audio_proc.h \
					vad/vad_audio_proc_internal.h \
					vad/vad_circular_buffer.h \
					vad/voice_activity_detector.h \
					vad/voice_gmm_tables.h \
					vad/gmm.cc \
					vad/pitch_based_vad.cc \
					vad/pitch_internal.cc \
					vad/pole_zero_filter.cc \
					vad/standalone_vad.cc \
					vad/vad_audio_proc.cc \
					vad/vad_circular_buffer.cc \
					vad/voice_activity_detector.cc \
					audio_buffer.cc \
					audio_buffer.h \
					audio_processing_impl.cc \
					audio_processing_impl.h \
					common.h \
					echo_cancellation_impl.cc \
					echo_cancellation_impl.h \
					echo_control_mobile_impl.cc \
					echo_control_mobile_impl.h \
					gain_control_config_proxy.h \
					gain_control_config_proxy.cc \
					gain_control_for_experimental_agc.cc \
					gain_control_for_experimental_agc.h \
					gain_control_impl.cc \
					gain_control_impl.h \
					gain_controller2.cc \
					gain_controller2.h \
					level_estimator_impl.cc \
					level_estimator_impl.h \
					low_cut_filter.cc \
					low_cut_filter.h \
					noise_suppression_impl.cc \
					noise_suppression_impl.h \
					noise_suppression_proxy.cc \
					noise_suppression_proxy.h \
					render_queue_item_verifier.h \
					residual_echo_detector.cc \
					residual_echo_detector.h \
					rms_level.cc \
					rms_level.h \
					splitting_filter.cc \
					splitting_filter.h \
					three_band_filter_bank.cc \
					three_band_filter_bank.h \
					typing_detection.cc \
					typing_detection.h \
					voice_detection_impl.cc \
					voice_detection_impl.h \
					agc2/adaptive_agc.cc \
					agc2/adaptive_agc.h \
					agc2/adaptive_digital_gain_applier.cc \
					agc2/adaptive_digital_gain_applier.h \
					agc2/adaptive_mode_level_estimator_agc.cc \
					agc2/adaptive_mode_level_estimator_agc.h \
					agc2/adaptive_mode_level_estimator.cc \
					agc2/adaptive_mode_level_estimator.h  \
					agc2/agc2_common.cc \
					agc2/agc2_common.h  \
					agc2/agc2_testing_common.cc \
					agc2/agc2_testing_common.h \
					agc2/biquad_filter.cc \
					agc2/biquad_filter.h \
					agc2/compute_interpolated_gain_curve.cc \
					agc2/compute_interpolated_gain_curve.h \
					agc2/down_sampler.cc \
					agc2/down_sampler.h \
					agc2/fixed_digital_level_estimator.cc \
					agc2/fixed_digital_level_estimator.h \
					agc2/gain_applier.cc \
					agc2/gain_applier.h \
					agc2/interpolated_gain_curve.cc \
					agc2/interpolated_gain_curve.h \
					agc2/limiter.cc \
					agc2/limiter_db_gain_curve.cc \
					agc2/limiter_db_gain_curve.h \
					agc2/limiter.h \
					agc2/noise_level_estimator.cc \
					agc2/noise_level_estimator.h \
					agc2/noise_spectrum_estimator.cc \
					agc2/noise_spectrum_estimator.h \
					agc2/saturation_protector.cc \
					agc2/saturation_protector.h \
					agc2/signal_classifier.cc \
					agc2/signal_classifier.h \
					agc2/vad_with_level.cc \
					agc2/vad_with_level.h \
					agc2/vector_float_frame.cc \
					agc2/vector_float_frame.h \
					agc2/rnn_vad/auto_correlation.cc \
					agc2/rnn_vad/auto_correlation.h \
					agc2/rnn_vad/common.h \
					agc2/rnn_vad/features_extraction.cc \
					agc2/rnn_vad/features_extraction.h \
					agc2/rnn_vad/lp_residual.cc \
					agc2/rnn_vad/lp_residual.h \
					agc2/rnn_vad/pitch_info.h \
					agc2/rnn_vad/pitch_search.cc \
					agc2/rnn_vad/pitch_search.h \
					agc2/rnn_vad/pitch_search_internal.cc \
					agc2/rnn_vad/pitch_search_internal.h \
					agc2/rnn_vad/ring_buffer.h \
					agc2/rnn_vad/rnn.cc \
					agc2/rnn_vad/rnn.h \
					agc2/rnn_vad/sequence_buffer.h \
					agc2/rnn_vad/spectral_features.cc \
					agc2/rnn_vad/spectral_features.h \
					agc2/rnn_vad/spectral_features_internal.cc \
					agc2/rnn_vad/spectral_features_internal.h \
					agc2/rnn_vad/symmetric_matrix_buffer.h


if NS_FIXED
COMMON_CFLAGS += -DWEBRTC_NS_FIXED=1
COMMON_CXXFLAGS += -DWEBRTC_NS_FIXED=1
libwebrtc_audio_processing_la_SOURCES += \
					ns/include/noise_suppression_x.h \
					ns/noise_suppression_x.c \
					ns/nsx_defines.h \
					ns/nsx_core.c \
					ns/nsx_core.h \
					ns/nsx_core_c.c
if HAVE_NEON
libwebrtc_audio_processing_la_SOURCES += \
					ns/nsx_core_neon.c
endif
else
COMMON_CFLAGS += -DWEBRTC_NS_FLOAT=1
COMMON_CXXFLAGS += -DWEBRTC_NS_FLOAT=1
libwebrtc_audio_processing_la_SOURCES += \
					ns/include/noise_suppression.h \
					ns/noise_suppression.c \
					ns/defines.h \
					ns/ns_core.c \
					ns/ns_core.h \
					ns/windows_private.h
endif

if HAVE_X86
noinst_LTLIBRARIES = libwebrtc_audio_processing_privatearch.la
LIBWEBRTC_PRIVATEARCH=libwebrtc_audio_processing_privatearch.la
libwebrtc_audio_processing_privatearch_la_SOURCES = \
					aec/aec_core_sse2.cc \
					utility/ooura_fft_sse2.cc \
					utility/ooura_fft_tables_neon_sse2.h

libwebrtc_audio_processing_privatearch_la_CFLAGS = $(AM_CFLAGS) $(COMMON_CFLAGS) -msse2
libwebrtc_audio_processing_privatearch_la_CXXFLAGS = $(AM_CXXFLAGS) $(COMMON_CXXFLAGS) -msse2
libwebrtc_audio_processing_privatearch_la_LDFLAGS = $(AM_LDFLAGS)
endif

if HAVE_NEON
libwebrtc_audio_processing_la_SOURCES += \
					aec/aec_core_neon.cc \
					aecm/aecm_core_neon.cc \
					utility/ooura_fft_neon.cc \
					utility/ooura_fft_tables_neon_sse2.h
endif

libwebrtc_audio_processing_la_CFLAGS = $(AM_CFLAGS) $(COMMON_CFLAGS) \
				       -DWEBRTC_APM_DEBUG_DUMP=0 \
				       -DWEBRTC_INTELLIGIBILITY_ENHANCER=1
libwebrtc_audio_processing_la_CXXFLAGS = $(AM_CXXFLAGS) $(COMMON_CXXFLAGS) \
				       -DWEBRTC_APM_DEBUG_DUMP=0 \
				       -DWEBRTC_INTELLIGIBILITY_ENHANCER=1

libwebrtc_audio_processing_la_LIBADD = $(top_builddir)/webrtc/base/libbase.la \
				       $(top_builddir)/webrtc/api/audio/libaudio_api.la \
				       $(top_builddir)/webrtc/api/units/libunits.la \
				       $(top_builddir)/webrtc/base/libbase.la \
				       $(top_builddir)/webrtc/rtc_base/librtc_base.la \
				       $(top_builddir)/webrtc/common_audio/libcommon_audio.la \
				       $(top_builddir)/webrtc/modules/audio_coding/libaudio_coding.la \
				       $(top_builddir)/webrtc/modules/third_party/fft/libfft.la \
				       $(top_builddir)/webrtc/third_party/pffft/libpffft.la \
                       $(top_builddir)/webrtc/system_wrappers/libsystem_wrappers.la \
				       $(top_builddir)/webrtc/third_party/rnnoise/librnnoise.la \
				       $(LIBWEBRTC_PRIVATEARCH) \
				       $(GNUSTL_LIBS)

ABSL_LIBS=$(top_builddir)/webrtc/third_party/_install/lib/libabsl_bad_optional_access.a

libwebrtc_audio_processing_la_LDFLAGS = $(AM_LDFLAGS) $(COMMON_LDFLAGS) \
                    $(ABSL_LIBS) \
					-no-undefined \
					-version-info $(LIBWEBRTC_AUDIO_PROCESSING_VERSION_INFO)

# FIXME: The MIPS optimisations need to be hooked up once we have the
# autotools conditionals in place
EXTRA_DIST = BUILD.gn \
	     aec/aec_core_mips.c \
	     aec/aec_rdft_neon.c \
	     aecm/aecm_core_mips.c \
	     ns/nsx_core_mips.c
