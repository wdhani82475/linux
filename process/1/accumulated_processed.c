#include<stdio.h>
#include<unistd.h>

int main()
{
	int i=0;
	for(;i<100;i++)
	{
		printf("i= %d\n",i);
		sleep(3);
	}
	return 0;
}
