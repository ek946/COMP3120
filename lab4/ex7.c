#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>
#include <string.h>

int main()
{
	struct timeval mytime;
	struct tm *lt;

	gettimeofday(&mytime,NULL);
	printf("%ld : %ld(sec : usec)\n",mytime.tv_sec,mytime.tv_usec);

	lt = localtime(&mytime.tv_sec);

	printf("current time : %04d-%02d-%02d %02d:%02d:%02d.%06d\n",lt->tm_year+1900,lt->tm_mon+1,lt->tm_mday,lt->tm_hour,lt->tm_min,lt->tm_sec,mytime.tv_usec);

	return 0;
}
