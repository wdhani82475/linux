
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

pthread_rwlock_t rwlock;
void*fun1(void* arg)
{
	pthread_rwlock_wrlock(&rwlock);
	printf("this is fun1 thread.\n");
	sleep(3);
	printf("thread fun1 wake up ......\n");
	pthread_rwlock_unlock(&rwlock);	
	printf("thread fun1 finish.\n");
}
void*fun2(void*arg)
{
	pthread_rwlock_rdlock(&rwlock);
	printf("this is fun2 thread.\n");
	pthread_rwlock_unlock(&rwlock);
	printf("thread fun2 finish.\n");
}
int main()
{
		pthread_t tid1,tid2;
		pthread_create(&tid1,NULL,fun1,NULL);
		sleep(1);
		pthread_create(&tid2,NULL,fun2,NULL);
		pthread_join(tid1,NULL);
		pthread_join(tid2,NULL);
	return 0;
}
