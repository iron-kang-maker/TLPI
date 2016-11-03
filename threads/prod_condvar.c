#include <time.h>
#include <pthread.h>
#include "tlpi_hdr.h"

static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

static int avail = 0;

static void *threadFunc(void *arg)
{
	int cnt = atoi((char *) arg);
	int s, j;

	for (j = 0; j < cnt; j++)
	{
		sleep(1);

		s = pthread_mutex_lock(&mtx);
		if (s != 0)
			errExitEN(s, "pthread_mutex_lock");

		avail++;

		s = pthread_mutex_unlock(&mtx);
		if (s != 0)
			errExitEN(s, "pthread_mutex_unlock");

		s = pthread_cond_signal(&cond);
		if (s != 0)
			errExitEN(s, "pthread_cond_signal");
	}

	return NULL;
}


int main(int argc, char *argv[])
{
	pthread_t tid;
	int s, j
	int totRequired;

	int numConsumed;
	Boolean done;
	time_t t;

	t = time(NULL);

	totRequired = 0;
	for (j = 1; j < argc; j++)
	{
		totRequired += atoi(argv[j]);

		s = pthread_create(&tid, NULL, threadFunc, argv[j]);
		if (s != 0)
			errExitEN(s, "pthread_create");
	}

	numConsumed = 0;
	done = FALSE;

	for (;;)
	{
		s = pthread_mutex_lock(&mtx);
		if (s != 0)
			errExitEN(s, "pthread_mutex_lock");

		while (avail == 0)
		{
			s = pthread_cond_wait(&cond, &mtx);
			if (s != 0)
				errExitEN(s, "pthread_cond_wait");
		}

		while (avail > 0)
		{
			numConsumed++;
			avail--;
			printf("T = %ld: numConsumed = %d\n", (long) (time(NULL) - t),
					numConsumed);

			done = numConsumed >= totRequired;
		}

		s = pthread_mutex_unlock(&mtx);
		if (s != 0)
			errExitEN(s, "pthread_mutex_unlock");

		if (done)
			break;
	}

	exit(EXIT_SUCCESS);
}
