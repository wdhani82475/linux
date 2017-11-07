#include"ipc.h"
int main (int argc,char*argv[])
{
	
	key_t key=Ftok(argv[1],atoi(argv[2]));
	int semid=Semget(key,0,0);//obtain id
	printf("semid=%d\n",semid);

	return 0;
}
