#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<unistd.h>
int main()
{
int fd1[2];
int fd2[2];
  char *msg1[]={"hi","what's time ?","oh,mygod,bybey","NULL"};
  char *msg2[]={"hello","4:00","bybey","NULL"};

int re=pipe(fd1);
if(re==-1)
{
	printf("msg is error\n");
	exit(1);
}
 re=pipe(fd2);
if(re==-1)
{
	printf("msg2 is  error\n");
	exit(1);
}
pid_t pid=fork();

if(pid==0)
{
	int i=0;
	char buffer[256];
	close( fd2[1]);//read
	close (fd1[0]);//write
	char*child=msg2[i];
	while(child!=NULL)
	{
		
		read(fd2[0],buffer,256);
		write(fd1[1],child,strlen(child)+1);
		i++;
		child=msg2[i];
		printf(" read parent=%s\n",buffer);
	}
	close (fd2[0]);
	close (fd1[1]);
}
else if(pid>0)
{
	int i=0;
	char  buffer[256];
	close (fd1[0]);//write
	close (fd2[1]);//read
	char* parent =msg1[i];
	while(parent!=NULL)
	{
	write(fd1[1],parent,strlen(parent)+1);
	read(fd2[0],buffer,256);
	printf("read Child=%s\n",buffer);
	++i;
	parent=msg1[i];
	}
	close( fd1[1]);
	close (fd2[0]);
	int status;
	wait(&status);
}
else 
{
	printf("fork is failed\n");
}
return 0;
}
