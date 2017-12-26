#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int pid=fork();

	if (pid ==-1)
	{
		perror("fork error\n");
		exit(1);
	}

	else if( pid ==0)
	{
		execl("/bin/ls","ls","-l",0);
	}

	else if( pid >0)
	{
		wait(NULL);
	}

	return 0;
}
