#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#define N 5
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond=PTHREAD_COND_INITIALIZER;

void*fun2(void*arg)
{
	pthread_cond_broadcast(&cond);
}
void*fun1(void*arg)
{	
	int n=*(int*)arg;	
	pthread_mutex_lock(&mutex);
	printf("this is [%d] thread.\n",n);
	pthread_cond_wait(&cond,&mutex);//阻塞
	printf("[%d] thread is waked up.\n",n);
	pthread_mutex_unlock(&mutex);
}
int main()
{
	pthread_t tid1,tid[N];
	int i;
	for(i=0;i<N;i++)
	{
		pthread_create(&tid[i],NULL,fun1,&i);
		sleep(1);
	}
	pthread_create(&tid1,NULL,fun2,NULL);
	for(i=0;i<N;i++)
	{
		pthread_join(tid[i],NULL);
	}
	pthread_join(tid1,NULL);
	return 0;
}

/*
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond=PTHREAD_COND_INITIALIZER;
void*fun1(void*arg)
{
	pthread_mutex_lock(&mutex);//加锁  区域称为临界区
	printf("this is fun1 thread.\n");
	sleep(3);
	printf("this is fun1 thread finish.\n");
	//pthread_mutex_unlock(&mutex);//解锁
	pthread_cond_wait(&cond,&mutex);//阻塞，解锁
	printf("aaaaaaaaa.\n");
}
void*fun2(void*arg)
{
		int ret;
	//pthread_mutex_unlock(&mutex);
	//pthread_mutex_lock(&mutex);
	//ret=pthread_mutex_trylock(&mutex);//非阻塞加锁
	
	ret=pthread_mutex_lock(&mutex);
	{
		if(ret !=0 )
		{
			printf("lock error.\n");
		}
		else
			printf("lock success.\n");
	}
	printf("this is fun2 thread.\n");
	printf("thread fun2 finish.\n");
	pthread_cond_signal(&cond);//先执行，后加锁	
	printf("bbbbbbbb.\n");
	pthread_mutex_unlock(&mutex);
	printf("cccccccc.\n");
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

*/

/*
void*fun(void*arg)//多线程创建
{
	int n=*(int*)arg;
	int i;
	for(i=0;i<n;i++)
	{
		printf("this is [%d] thread.\n",i);
	}
}
int main()
{	
	int i;
	pthread_t tid[N];
	for(i=0;i<N;i++)
	{
		pthread_create(&tid[i],NULL,fun,&i);
		sleep(2);

	}
	for(i=0;i<N;i++)
	{
		pthread_join(tid[i],NULL);
	}
	return 0;
}

*/

/*
void*fun(void*arg)//单线程创建
{
		
	printf("tid1=%d\n",pthread_self());
		int i;
		int n=*(int*)arg;
	for(i=0;i<n;i++)
	{
		printf("this is child thread.\n");
	}
	pthread_exit("child thread is finish.");	
		
}
int main()
{
	pthread_t tid;
	int ret;
	int n=10;
	if((ret=pthread_create(&tid,NULL,fun,&n))!=0)
		exit(1);
	else
		printf("tid=%d\n",tid);

	int i;
	for(i=0; i<n;i++)
	{
		printf("this is main thread.\n");
	}
	char *exit_code;
	pthread_join(tid,(void**)&(exit_code));
	printf("main in wait:%s\n",exit_code);
	return 0;
}
*/
