#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

#define N 10
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond=PTHREAD_COND_INITIALIZER;

void* fun2(void* arg)
{
	int n=*(int*)arg;
	pthread_mutex_lock(&mutex);	
	printf("this is %d thread.\n",n);
	 pthread_cond_wait(&cond);
	 printf("%d thread wake up.\n",n);
	pthread_mutex_unlock(&mutex);
}
void* fun1(void* arg)
{
	pthread_cond_broadcast(&cond);	
}
int main()
{
	int i=1;
	pthread_mutex_t tid1,tid2[N];
	pthread_create(&tid1,NULL,fun1,NULL);
	for(;i<=N;++i)
	{
		pthread_create(&tid2[i],NULL,fun2,&i);
		sleep(1);
	}
	for(;i<=10;i++)
	{
	pthread_join(&tid2[i],NULL);
	}
	pthread_join(&tid1,NULL);
	return 0;
}



/*
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;//init mutex
pthread_cond_t cond=PTHREAD_COND_INITIALIZER;//init cond
void* thread_fun1(void* arg)
{

	pthread_mutex_lock(&mutex);
	printf("this is fun1 thread.\n");
	pthread_cond_wait(&cond,&mutex);//unlock&& sleep
	printf("fun1 thread finish.\n");
	pthread_mutex_unlock(&mutex);
}
void*thread_fun2(void* arg)
{
	pthread_mutex_lock(&mutex);
	
	printf("this is fun2 thread.\n");
	pthread_cond_signal(&cond);//run && lock fun1
	printf("fun2 thread finish.\n");
	sleep(3);
	printf("sleep 3 s.....\n");
	pthread_mutex_unlock(&mutex);

}

int main()
{
	pthread_t tid1,tid2;
	pthread_create(&tid1,NULL,thread_fun1,NULL);//invilable
	sleep(1);
	pthread_create(&tid2,NULL,thread_fun2,NULL);//inviliable

	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	return 0;
}
*/
/*
void* pthread_fun(void*arg)
{
	int n=*(int*)arg;
	int i;
	for(i=0;i<n;i++)
	{
		printf("this is child pthread.\n");
		//sleep(2);
	}
	pthread_exit("Child pthread run:Finish.\n");
}

int main()
{
	pthread_t tid;
	int n=10;
	int ret=pthread_create(&tid,NULL,pthread_fun,&n);
	if(ret != 0)
	{
		printf("pthread_create fail.\n");
		exit(1);
	}
	else
		printf("pthread_tid=%d\n",tid);
	int  i;
	for(i=0;i<n;i++)
	{
			//pthread_join(tid,NULL);
		printf("this is main thread.\n");
	}
	char*Exit_code;
	pthread_join(tid,(void**)&Exit_code);
	printf("In main code:%s\n",Exit_code);
	return 0;
}
*/

/*
void* pthread_fun(void*arg)
{
		pthread_t tid;
		tid=pthread_self();
	printf("tid2=%d\n",tid);
}
int main()
{
		pthread_t tid;
		int ret=pthread_create(&tid,NULL,pthread_fun,NULL);
		if(ret != 0)
		{
			perror("pthread_create fail.\n");
		}
		else				
		printf("tid1=%d\n",tid);
		pthread_join(tid,NULL);

	return 0;
}

*/
/*
int main()
{
	pthread_t tid = pthread_self();
	printf("pthread tid = %d\n",tid);
	return 0;

}
*/
