#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	int x = 100;
	int pid = fork();
	
	if(pid == 0)
	{
		printf("Child: Before changing x : %d\n",x);
		x= x+10;
		printf("child: After changing x : %d\n",x);
	}
	else if( pid>0)
	{
		printf("Parent: Before changing x: %d\n",x);
		x = x+10;
		printf("Parent: After changing x: %d\n",x);	
		wait(NULL);
	}
	else if (pid == -1)
	{
		perror("fork error: ");
		exit(0);
	}
	return 0;
}
