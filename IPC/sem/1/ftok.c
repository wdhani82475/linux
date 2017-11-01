#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<stdlib.h>
int main()
{
	key_t key;
	key=ftok("test",0xee);//exit filename
	if(key == -1)
	{
		perror("ftok");
		exit(1);
	}
	else 
		printf("key=%x\n",key);
	key=ftok("test",0xfe);
	if(key == -1)
	{
		perror("ftok");
	}
	else
		printf("key=%x\n",key);
	key=ftok("mytest",0xee);
	if(key == -1)
	{
		perror("ftok");
	}
	else
		printf("key=%x\n",key);
	return 0;
}
