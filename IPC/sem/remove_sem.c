#include"ipc.h"
int main()
{
	
	key_t key=Ftok("mytest",0xfe);
	int semid=Semget(key,0,0);
	semctl(semid,0,IPC_RMID);

	return 0;
}
