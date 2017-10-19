#include<stdio.h>
#include<unistd.h>

int main()
{
	pid_t pid;
	pid = fork();
	if(pid>0)
	{
		int status;
		wait(&status);
		printf("Parent.ppid[%d]\n",getpid());
	}
	else if(pid==0)
	{
		sleep(3);
		printf("Child.pid[%d]\n",getpid());
	}
	else
	{
		perror("fork");
	}
	
	return 0;
}	
