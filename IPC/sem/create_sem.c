#include"ipc.h"
#include<sys/sem.h>
int main()
{
	int semid;
	key_t key=Ftok("mytest",0xfe);//create key
	printf("semkey=%x\n",key);
	semid=Semget(key,1,IPC_CREAT|IPC_EXCL|0755);
	printf("semid=%d\n",semid);	
	return 0;
}
