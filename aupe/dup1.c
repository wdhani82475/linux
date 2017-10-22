
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
int main()
{
	int fd;
	fd =open("myfile.c",O_WRONLY|O_CREAT,0755);
	close(1);//STDOUT_FILENO
	printf("fd=%d\n",fd);//3
	int fd1=dup(fd);//重新改变输出文件的方向,fd1和fd都指向myfile.c
	printf("fd1=%d\n",fd1);//1
	printf("hello linux\n");
	return 0;
}
