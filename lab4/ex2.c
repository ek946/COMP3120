#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
int main()
{
	int f =open("ex2.txt",O_RDWR|O_CREAT);
	int pid;
	char buf[BUFSIZ];

	pid =fork();

	if(pid >0 ) // parent
	{
		printf("parent number %d\n",f);
		strcpy(buf, "I am parent\n");
		write(f,buf,strlen(buf));
		wait(NULL);

	}
	else if( pid ==0) //child
	{
		printf("child number %d\n",f);
		strcpy(buf, "I am child\n");
		write(f,buf,strlen(buf));
	}
	else if( pid ==-1)
	{
		perror("fork error\n");
		exit(1);
	}
	close(f);
	return 0;
}
