#include<string.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int pipefd1[2];
	int pipefd2[2];
	int re;
	char buffer[256];
	char*msg1[]={"hi","can you tell me current time","oh,hurry!,bybey",NULL};
	char*msg2[]={"hello","no problem","bybey",NULL};
	if(re=pipe(pipefd1)==-1)
	{
		printf("pipefd1 failed.\n");
		exit(1);
	}
	if(re=pipe(pipefd2)==-1)
	{
		printf("pipefd2 failed.\n");
		exit(1);
	}
	pid_t cpid=fork();
	if(cpid==0)
	{
		int i=0;
		char*child=msg1[i];
		close(pipefd1[0]);
		close(pipefd2[1]);
		while(child != NULL)
		{
			if(i==1)
			{
			time_t ti;
			time(&ti);
			memset(buffer,0,256);
			sprintf(buffer,"%s,%s",child,ctime(&ti));
			write(pipefd2[1],buffer,strlen(buffer)+1);
			}
			else{
			write(pipefd1[1],child,strlen(child)+1);
			}
			read(pipefd2[0],buffer,256);
			printf("read from parent>>%s\n",buffer);
			i++;
			child=msg1[i];	
		}
		close(pipefd1[1]);
		close(pipefd2[0]);

	}
	else if(cpid>0)
	{
			int i=0;
			//int status;
		char*parent=msg2[i];
		close(pipefd1[1]);
		close(pipefd2[0]);
		while(parent != NULL)
		{
			
		read(pipefd1[0],buffer,256);
		printf("read msg1 from child>>%s\n",buffer);
		write(pipefd2[1],parent,strlen(parent)+1);
		i++;
		parent=msg2[i];
		}
		close(pipefd1[0]);
		close(pipefd2[1]);
	//	wait(&status);
	}
	else 
	{
		printf("fork process error.\n");
	}



	return 0;
}







/*
int main()
{	
	char buffer[256];
	char *msg="hi,child process";
	int pipefd[2];//创建管道
	int re=pipe(pipefd);
	pid_t cpid=fork();
	if(re == -1)
	{
		printf("pipe failed.\n");
		exit(1);
	}
	if(cpid>0)
	{
		close(pipefd[0]);
		write(pipefd[1],msg,strlen(msg)+1);
		close(pipefd[1]);

	}
	else if(cpid==0)
	{
		close( pipefd[1]);
		read(pipefd[0],buffer,256);
		printf("from parent process>>%s\n",buffer);
		close (pipefd[0]);
		int status;
		wait(&status);
	}
	else
	{
		printf("fork error.\n");
	}

	return 0;
}
*/
