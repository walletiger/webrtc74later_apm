noinst_LTLIBRARIES = librtc_base.la

noinst_HEADERS =arraysize.h \
				atomic_ops.h \
			    checks.h \
                constructor_magic.h \
				critical_section.h \
				deprecation.h \
				event.h \
				function_view.h \
				gtest_prod_util.h \
				ignore_wundef.h \
				logging.h \
				platform_file.h \
				platform_thread.h \
				platform_thread_types.h \
				protobuf_utils.h \
				race_checker.h \
				sanitizer.h \
				string_encode.h \
				string_utils.h \
				swap_queue.h \
				template_util.h \
				thread_annotations.h \
				thread_checker.h \
				time_utils.h \
				trace_event.h \
				type_traits.h \
				win32.h \
                compile_assert_c.h \
                numerics/safe_compare.h \
		numerics/safe_conversions.h \
                numerics/safe_conversions_impl.h \
		numerics/safe_minmax.h \
		numerics/moving_median_filter.h \
		numerics/percentile_filter.h \
                memory/aligned_array.h \
                memory/aligned_malloc.h \
                system/asm_defines.h  \
                system/file_wrapper.h \
		system/inline.h \
		system/ignore_warnings.h \
		system/warn_current_thread_is_deadlocked.h \
                synchronization/rw_lock_wrapper.h \
                synchronization/rw_lock_posix.h \
                synchronization/rw_lock_win.h \
                synchronization/yield_policy.h \
		strings/string_builder.h \
		string_to_number.h \
		system/rtc_export.h \
		ref_count.h \
		system/arch.h \
		system/unused.h \
		ref_counted_object.h \
		ref_counter.h \
		event_tracer.h \
		flags.h 





librtc_base_la_SOURCES =checks.cc \
						critical_section.cc \
						event.cc \
						logging.cc \
						platform_file.cc \
                        platform_thread.cc \
						platform_thread_types.cc \
						race_checker.cc \
						string_encode.cc \
						string_utils.cc \
						time_utils.cc  \
                        synchronization/rw_lock_wrapper.cc \
			synchronization/yield_policy.cc \
                        memory/aligned_malloc.cc \
                        system/file_wrapper.cc  \
		        strings/string_builder.cc \
			string_to_number.cc \
			event_tracer.cc \
			flags.cc 

if HAVE_WIN
librtc_base_la_SOURCES += synchronization/rw_lock_win.cc
endif  

if HAVE_POSIX
librtc_base_la_SOURCES += synchronization/rw_lock_posix.cc
endif

librtc_base_la_CXXFLAGS = $(AM_CXXFLAGS) $(COMMON_CXXFLAGS)

