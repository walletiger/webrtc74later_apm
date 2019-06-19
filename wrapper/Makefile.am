lib_LTLIBRARIES = libwebrtc_apm_wrapper.la

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = $(top_builddir)/webrtc-apm-wrapper.pc

wrapperincludedir = $(includedir)/
nobase_wrapperinclude_HEADERS = webrtc_apm_wrapper.h 

libwebrtc_apm_wrapper_la_SOURCES =  webrtc_apm_wrapper.h  webrtc_apm_wrapper.cc 

libwebrtc_apm_wrapper_la_CFLAGS = $(AM_CFLAGS) $(COMMON_CFLAGS) \
				       -DWEBRTC_APM_DEBUG_DUMP=0 

libwebrtc_apm_wrapper_la_CXXFLAGS = $(AM_CXXFLAGS) $(COMMON_CXXFLAGS) \
				       -DWEBRTC_APM_DEBUG_DUMP=0 

libwebrtc_apm_wrapper_la_LIBADD = $(top_builddir)/webrtc/modules/audio_processing/libwebrtc_audio_processing.la 
				       $(LIBWEBRTC_PRIVATEARCH) \
				       $(GNUSTL_LIBS)

libwebrtc_apm_wrapper_la_LDFLAGS = $(AM_LDFLAGS) $(COMMON_LDFLAGS) \
					-no-undefined \
					-version-info $(LIBWEBRTC_AUDIO_PROCESSING_VERSION_INFO)
