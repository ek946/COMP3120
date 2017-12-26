#include <stdio.h>
#include <unistd.h>

int main()
{
	int pid = fork();

	if(pid >0) // parent
	{
		wait(NULL);
		printf("I am parent\n");
	}
	else if( pid ==0)
	{
		//wait(NULL);
		printf("I am child\n");
	}
	return 0;
}
