#ifndef _PERF_H_
#define _PERF_H_


#include <stdint.h>
#include <linux/perf_event.h>

const int CYCLES = PERF_COUNT_HW_CPU_CYCLES;

const int INSTRUCTIONS = PERF_COUNT_HW_INSTRUCTIONS;

const int BRANCHES = PERF_COUNT_HW_BRANCH_INSTRUCTIONS;

const int BRANCH_MISSES = PERF_COUNT_HW_BRANCH_MISSES;

const int DTLB_READS = (PERF_COUNT_HW_CACHE_DTLB << 0) |
                       (PERF_COUNT_HW_CACHE_OP_READ << 8) |
                       (PERF_COUNT_HW_CACHE_RESULT_ACCESS << 16);

const int DTLB_WRITES = (PERF_COUNT_HW_CACHE_DTLB << 0) |
                        (PERF_COUNT_HW_CACHE_OP_WRITE << 8) |
                        (PERF_COUNT_HW_CACHE_RESULT_ACCESS << 16);

const int ITLB_READS = (PERF_COUNT_HW_CACHE_ITLB << 0) |
                       (PERF_COUNT_HW_CACHE_OP_READ << 8) |
                       (PERF_COUNT_HW_CACHE_RESULT_ACCESS << 16);

const int DTLB_READ_MISSES = (PERF_COUNT_HW_CACHE_DTLB << 0) |
                             (PERF_COUNT_HW_CACHE_OP_READ << 8) |
                             (PERF_COUNT_HW_CACHE_RESULT_MISS << 16);

const int DTLB_WRITE_MISSES = (PERF_COUNT_HW_CACHE_DTLB << 0) |
                              (PERF_COUNT_HW_CACHE_OP_WRITE << 8) |
                              (PERF_COUNT_HW_CACHE_RESULT_MISS << 16);

const int ITLB_READ_MISSES = (PERF_COUNT_HW_CACHE_ITLB << 0) |
                             (PERF_COUNT_HW_CACHE_OP_READ << 8) |
                             (PERF_COUNT_HW_CACHE_RESULT_MISS << 16);

const int L1D_READS = (PERF_COUNT_HW_CACHE_L1D << 0) |
                      (PERF_COUNT_HW_CACHE_OP_READ << 8) |
                      (PERF_COUNT_HW_CACHE_RESULT_ACCESS << 16);

const int L1D_WRITES = (PERF_COUNT_HW_CACHE_L1D << 0) |
                       (PERF_COUNT_HW_CACHE_OP_WRITE << 8) |
                       (PERF_COUNT_HW_CACHE_RESULT_ACCESS << 16);

const int L1D_PREFETCHES = (PERF_COUNT_HW_CACHE_L1D << 0) |
                           (PERF_COUNT_HW_CACHE_OP_PREFETCH << 8) |
                           (PERF_COUNT_HW_CACHE_RESULT_ACCESS << 16);

const int L1D_READ_MISSES = (PERF_COUNT_HW_CACHE_L1D << 0) |
                            (PERF_COUNT_HW_CACHE_OP_READ << 8) |
                            (PERF_COUNT_HW_CACHE_RESULT_MISS << 16);

const int L1D_WRITE_MISSES = (PERF_COUNT_HW_CACHE_L1D << 0) |
                             (PERF_COUNT_HW_CACHE_OP_WRITE << 8) |
                             (PERF_COUNT_HW_CACHE_RESULT_MISS << 16);

const int L1D_PREFETCH_MISSES = (PERF_COUNT_HW_CACHE_L1D << 0) |
                                (PERF_COUNT_HW_CACHE_OP_PREFETCH << 8) |
                                (PERF_COUNT_HW_CACHE_RESULT_MISS << 16);

const int L1I_READS = (PERF_COUNT_HW_CACHE_L1I << 0) |
                      (PERF_COUNT_HW_CACHE_OP_READ << 8) |
                      (PERF_COUNT_HW_CACHE_RESULT_ACCESS << 16);

const int L1I_READ_MISSES = (PERF_COUNT_HW_CACHE_L1I << 0) |
                            (PERF_COUNT_HW_CACHE_OP_READ << 8) |
                            (PERF_COUNT_HW_CACHE_RESULT_MISS << 16);

const int L3_READS = (PERF_COUNT_HW_CACHE_LL << 0) |
                     (PERF_COUNT_HW_CACHE_OP_READ << 8) |
                     (PERF_COUNT_HW_CACHE_RESULT_ACCESS << 16);

const int L3_WRITES = (PERF_COUNT_HW_CACHE_LL << 0) |
                      (PERF_COUNT_HW_CACHE_OP_WRITE << 8) |
                      (PERF_COUNT_HW_CACHE_RESULT_ACCESS << 16);

const int L3_PREFETCHES = (PERF_COUNT_HW_CACHE_LL << 0) |
                          (PERF_COUNT_HW_CACHE_OP_PREFETCH << 8) |
                          (PERF_COUNT_HW_CACHE_RESULT_ACCESS << 16);

const int L3_READ_MISSES = (PERF_COUNT_HW_CACHE_LL << 0) |
                           (PERF_COUNT_HW_CACHE_OP_READ << 8) |
                           (PERF_COUNT_HW_CACHE_RESULT_MISS << 16);

const int L3_WRITE_MISSES = (PERF_COUNT_HW_CACHE_LL << 0) |
                            (PERF_COUNT_HW_CACHE_OP_WRITE << 8) |
                            (PERF_COUNT_HW_CACHE_RESULT_MISS << 16);

const int L3_PREFETCH_MISSES = (PERF_COUNT_HW_CACHE_LL << 0) |
                               (PERF_COUNT_HW_CACHE_OP_PREFETCH << 8) |
                               (PERF_COUNT_HW_CACHE_RESULT_MISS << 16);

typedef struct perf perf_t;

perf_t *perf_init(int, ...);

void perf_destroy(perf_t*);

uint64_t perf_counter(perf_t*, int);


#endif
