#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char* str = "simple txt";

int main()
{
	int fd[2];
	char buff[BUFSIZ];
	int state,pid;

	state = pipe(fd);

	if(state == -1)
	{
		puts("pipe() error");
		exit(1);
	}

	pid = fork();

	if( pid ==0) // child
	{
		printf("child : %d\n",fd[1]);
		write(fd[1], str, strlen(str));
	}
	else if( pid >0) // parent
	{	
		wait(NULL);
		printf("parent : %d\n",fd[0]);
		read(fd[0],buff,strlen(str));
		printf("parent ouput : ");
		puts(buff);
	}
	return 0;
}
