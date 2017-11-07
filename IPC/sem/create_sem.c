#include"ipc.h"
#include<sys/sem.h>
int main(int argc,char*argv[])
{	
	if(argc!=3)
	{
		printf("<Usage >:pathname %s proj_id",argv[0]);
		return -1;
	}

	key_t key=Ftok(argv[1],atoi(argv[2]));//create key
	printf("semkey=%x\n",key);
/*	int	semid=Semget(key,1,IPC_CREAT|IPC_EXCL|0755);
	printf("semid=%d\n",semid);	*/
	return 0;
}
