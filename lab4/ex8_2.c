#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

#define NUM 1000000000

pthread_mutex_t mutex_lock;

int count =0;
void *print_count(void*);

int main()
{
	pthread_t t[25];
	struct timeval ft;
	struct timeval lt;
	int i;
	// start
	gettimeofday(&ft,NULL);

	for( i=0;i<25;i++)
	{
		pthread_create(&t[i],NULL,print_count,NULL);
	}

	for( i =0;i<25;i++)
	{
		pthread_join(t[i],NULL);
	}

	// end
	gettimeofday(&lt,NULL);

	printf("start time-> %ld:%ld\n",ft.tv_sec,ft.tv_usec);
	printf("end time-> %ld:%ld\n",lt.tv_sec,lt.tv_usec);
	printf("count time-> %ld:%ld\n",lt.tv_sec-ft.tv_sec,lt.tv_usec-ft.tv_usec);

	return 0;
}
void *print_count(void *m)
{
	int i;
	while(count < NUM)
	{
		
		pthread_mutex_lock(&mutex_lock);// lock
		if( count >= NUM)
		{
			pthread_mutex_unlock(&mutex_lock);
			break;
		}// check >= NUM unlock break
		count++;
		pthread_mutex_unlock(&mutex_lock);
	}
	return NULL;
}
