#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct statstruct_proc
{
	int pid;
	char exName[255];
	char state;
	int ppid;
	int pgrp;
	int session;
	int tty;
	int tpgid;
	unsigned int flags;
	unsigned int minflt;
	unsigned int cminflt;
	unsigned int majflt;
	unsigned int cmajflt;
	int utime;
	int stime;
}procinfo;

void *fun(void*);

int main()
{
	pthread_t t;

	pthread_create(&t,NULL,fun,NULL);

	pthread_join(t,NULL);
}

void *fun(void *m)
{
	char line[1024];
	char line2[1024];
	procinfo pinfo;
	int total;
	int cpu_usage;
	int count;
//	FILE *f = fopen("/proc/1245/stat","r");
//	FILE *fp = fopen("/proc/1245/status","r");

	while(!feof(stdin))
	{
		count =0;
	//	rewind(f);
	//	rewind(fp);
		FILE *f = fopen("/proc/1245/stat","r");
		FILE *fp = fopen("/proc/1245/status","r");
		fgets(line,1024,f);

		sscanf(line,"%d %s %c %d %d %d %d %d %u %u %u %u %u %d %d",&(pinfo.pid),pinfo.exName,&(pinfo.state),&(pinfo.ppid),&(pinfo.pgrp),&(pinfo.session),&(pinfo.tty),&(pinfo.tpgid),&(pinfo.flags),&(pinfo.minflt),&(pinfo.cminflt),&(pinfo.majflt),&(pinfo.cmajflt),&(pinfo.utime),&(pinfo.stime));
	
		total = pinfo.utime +pinfo.stime;
		cpu_usage = 100*total;

		printf("[1245]CPU usage(time) : %d\n",cpu_usage);

		while(count <=18)
		{
			fgets(line2,1024,fp);
			++count;
			if(count == 18)
			{
				printf("[1245]");
				printf("%s",line2);
			}
		}

		fclose(f);
		fclose(fp);
		sleep(1);
	}
	//fclose(f);
	//fclose(fp);
}

