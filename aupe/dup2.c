
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
int main()
{
	int fd=open("youfile.txt",O_WRONLY|O_CREAT,0775);
	//close(1);
	int fd1=dup2(fd,1);//fd和1一样，直接返回1
	printf("hello c++ \n");
	return 0;
}
