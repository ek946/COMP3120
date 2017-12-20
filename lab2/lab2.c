#include <stdio.h>

int main()
{
	FILE *f;
	
	f=fopen("lab2.txt","w");

	if(!f)
	{
		printf("failed\n");
	}
	
	fprintf(f,"Hello, lab2!!\n");
	fprintf(f,"Goodbye\n");

	fclose(f);
}

