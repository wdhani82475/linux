
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>//exit
int main()
{
	pid_t re_pid;
	pid_t pid;
	pid = fork();
	//pid = vfork();//共享父进程的地址空间
	if(pid==0)
	{
		printf("pid =%d\n",getpid());
		//exit(0);//结束子进程
		//sleep(3);//invaild
	}
	else if(pid>0)
	{
		int status;
		//sleep(2);
		re_pid=wait(&status);
		printf("re_pid=%d\n",re_pid);
		printf("ppid = %d\n",getpid());
	}
	else
		printf("fork is failed\n");
		

	return 0;
}






/*
int main()
{
	pid_t pid;
	pid=fork();
	if(pid==0)
	{
		sleep(5);
		printf("pid is begin...\n");
		printf("Child.pid=%d\n,pid=%d\n ",getpid(),pid);//返回0
		printf("Child.pid is over\n");
	}
	else if(pid>0)
	{
		int status;
		wait(&status);//解决孤子进程
		//sleep(4);
		printf("ppid is begin...\n");
		printf("Parent.pid=%d\n,pid=%d\n",getpid(),pid);//返回pid的id号
		printf("Parent.pid is over\n");
	}
	else
		printf("fork process is failed\n");
	return 0;
}

*/
/*
int main()
{
	int i=0;
	printf("Parent.pid=%d\n,Child.pid=%d\n",getppid(),getpid());
	sleep(2);
	return 0;
}
*/
