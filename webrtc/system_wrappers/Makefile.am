noinst_LTLIBRARIES = libsystem_wrappers.la

noinst_HEADERS =  include/event_wrapper.h 

libsystem_wrappers_la_SOURCES =	include/cpu_features_wrapper.h \
                include/clock.h \
                include/cpu_info.h \
                include/event_wrapper.h \
                include/field_trial.h \
                include/ntp_time.h \
				include/rtp_to_ntp_estimator.h \
				include/metrics.h \
				include/sleep.h \
				source/cpu_features.cc \
				source/event.cc \
				source/sleep.cc \
                source/clock.cc \
                source/cpu_info.cc \
                source/field_trial.cc \
                source/metrics.cc \
				source/rtp_to_ntp_estimator.cc 


if HAVE_X86
if !HAVE_WIN
libsystem_wrappers_la_SOURCES += source/cpu_features_linux.c
endif
endif


if HAVE_ANDROID
libsystem_wrappers_la_SOURCES += source/cpu_features_android.c
endif


libsystem_wrappers_la_CXXFLAGS = $(AM_CXXFLAGS) $(COMMON_CXXFLAGS)
libsystem_wrappers_la_CFLAGS = $(AM_CFLAGS) $(COMMON_CFLAGS)
