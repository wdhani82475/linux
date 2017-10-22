
#include<stdio.h>
#include<unistd.h>//exit(0)
#include<sys/resource.h>//priority
#include<wait.h>//sigin

int main()
{
	//execl("/bin/ls","ls",NULL);
	//execle("/bin/ls","ls","-la",NULL);
	//execlp("ls","ls","-la",NULL);
	char* ar[]={"ls",NULL};
	execvp("ls",ar);//realize ls
	return 0;
}


/*
int main()
{
	pid_t pid=fork();
	if(pid == 0)
	{
		printf("child pid =%d\n",getpid());
		printf("i go tt.\n");
		execl("./tt","tt",NULL);
		printf("===============");
	}
	else if(pid>0)
	{
			int status;
			wait(&status);
		printf("parent pid=%d\n",getpid());
	}
	else 
	{
		printf("fork error\n");
	}
	return 0;
	
}
*/
/*
int main()
{
	pid_t pid=fork();
	if(pid == 0)
	{
		printf("child pid =%d\n",getpid());
		sleep(2);
	}
	else if(pid>0)
	{
		//	sleep(3);
		int status;
		kill(pid,SIGINT);//异常退出
		printf("parent pid=%d\n",getpid());
		wait(&status);

		if(WIFEXITED(status))
		{
			printf("child process is ok.\n");
		}
		else
		{
			printf("child process is error.\n");
		}
	}
	else 
	{
		printf("fork is faided\n");
	}
	
	return 0;
}
*/
/*
int main()
{
	pid_t pid = vfork();//指向同一块内存空间--用exit(0)
	int oldpri,newpri;
	if(pid>0)
	{	
		oldpri=getpriority(PRIO_PROCESS,getpid());//acquire priority
		newpri=nice(3);//change process priority
		printf(" parent oldpri=%d\n",oldpri);
		printf(" prarent newpri=%d\n",newpri);
		printf("parent pid=%d\n",getpid());
		exit(0);
	}
	else if(pid == 0)
	{	
		printf("child pid=%d\n",getpid());
		oldpri=getpriority(PRIO_PROCESS,getpid());
		newpri=nice(5);
		printf("child oldpri=%d\n",oldpri);
		printf(" child newpri=%d\n",newpri);
	}
	else
	{
		printf("fork error\n");
	}
	return 0;
}
*/
