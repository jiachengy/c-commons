c-commons
=========

- Peformance tools
  * perf.h perf.c
  * A library that uses Linux's perf_event to profile programs
  * Authored by Orestis
  * TODO: only work for basic hardware event. Cache behavior is not correct

  * perf_counter.h perf_counter.c
  * Performance library that uses Intel's Performance Counter Monitor
  * A shared library has to be built for Intel's PCM
  * The library path has to be added to LDPATH
  * Authored by Craig