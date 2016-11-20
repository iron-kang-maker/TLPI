#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sched.h>
#include <sys/types.h>
#include <sys/syscall.h>

void *fun(void *arg)
{
	int id = (int) arg;
	int cnt = 10000;
	cpu_set_t get;

	CPU_ZERO(&get);

	printf("tid: %lu\n", syscall(__NR_gettid));
	if (pthread_getaffinity_np(pthread_self(), sizeof(get), &get) < 0)
		fprintf(stderr, "get thread affinity failed\n");

	if (CPU_ISSET(id, &get))
		printf("thread[%d](%d) in processor %d\n", id, (int)pthread_self(), id);

	if (id == 3)
		while (1);
		
	pthread_detach(pthread_self());
}


int main(void)
{
	cpu_set_t mask;
	int i;
	int num = sysconf(_SC_NPROCESSORS_CONF);
	pthread_t th[num];

	printf("system has %d process(s)\n", num);

	for (i = 0; i < num; i++)
	{
		if (pthread_create(&th[i], NULL, fun, (void *)i) != 0)
		{
			fprintf(stderr, "thread create fail\n");
			return -1;
		}

		CPU_ZERO(&mask);
		CPU_SET(i, &mask);

		if (pthread_setaffinity_np(th[i], sizeof(mask), &mask) < 0)
			fprintf(stderr, "set thread affinity failed\n");
	}

	for (i = 0; i < num; i++)
		pthread_join(th[i], NULL);

	printf("exit\n");
	return 0;
}

