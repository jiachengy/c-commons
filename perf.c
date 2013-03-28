#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>
#include <assert.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ioctl.h>

#include <linux/unistd.h>
#include <linux/perf_event.h>


typedef struct perf {
	int counters;
	int *fd;
	struct perf_event_attr *attr;
} perf_t;

perf_t *perf_init(int counters, ...)
{
	int c;
	va_list arg_list;
	pid_t pid = getpid();
	perf_t *perf = (perf_t*)malloc(sizeof(perf_t));
	perf->counters = counters;
	perf->attr = (perf_event_attr*)malloc(counters *
	                    sizeof(struct perf_event_attr));
	perf->fd = (int*)malloc(counters * sizeof(int));
	va_start(arg_list, counters);
	for (c = 0 ; c != counters ; ++c) {
		perf->attr[c].config = va_arg(arg_list, int);
		perf->attr[c].type = PERF_TYPE_HARDWARE;
		perf->attr[c].disabled = 0;
		perf->attr[c].inherit = 1;
		perf->fd[c] = syscall(__NR_perf_event_open,
		                      &(perf->attr[c]),
		                      pid, -1, -1, 0);
		assert(perf->fd[c] >= 0);
	}
	va_end(arg_list);
	return perf;
}

void perf_destroy(perf_t *perf)
{
	int c;
	for (c = 0 ; c != perf->counters ; ++c)
		close(perf->fd[c]);
	free(perf->fd);
	free(perf->attr);
	free(perf);
}

uint64_t perf_counter(perf_t *perf, int config)
{
	int c;
	uint64_t val;
	for (c = 0 ; c != perf->counters ; ++c)
		if (config == perf->attr[c].config) break;
	assert(c != perf->counters);
	assert(read(perf->fd[c], &val, 8) == 8);
	return val;
}
