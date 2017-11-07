#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>


void*fun(void*arg)
{
	printf("tid1=%d\n",pthread_self());
	int i;
	for(i=0;i<10;i++)
	{
		printf("this is child thread.\n");
	}
}
int main()
{
	pthread_t tid;
	int ret;
	if((ret=pthread_create(&tid,NULL,fun,NULL))!=0)
		exit(1);
	else
		printf("tid=%d\n",tid);

	int i;
	for(i=0; i<10;i++)
	{
		printf("this is main thread.\n");
	}
	pthread_join(tid,NULL);
	return 0;
}
