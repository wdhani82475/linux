

#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<stdlib.h>
///////////////////////////
//1.key
key_t Ftok(const char* pathname,int pro_id)//key
{
	key_t key=ftok( pathname, pro_id);
	if(key == -1)
	{
		perror("ftok");
	}
	else
		return key;
}
///////////////////////////
//2.id
int Semget(key_t key,int nums,int oflag)
{
	int semid=semget(key,nums,oflag);
	if(semid == -1)
	{
		perror("semid ");
	}
	else
		return semid;
} 

