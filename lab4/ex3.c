#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int pid;
	pid = fork();

	if(pid >0) //parent
	{
		sleep(1);
		printf("goodbye\n");
	}

	else if(pid == 0) // child
	{
		printf("hello\n");
	}

	else if( pid == -1)
	{
		perror("fork error\n");
		exit(1);
	}

	return 0;
}
