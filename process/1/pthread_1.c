#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void* thread_fun(void*arg)
{
	return NULL;
}

int main()
{
	pthread_t tid;
	pthread_create(&tid,NULL,thread_fun,NULL);
	return 0;
}
