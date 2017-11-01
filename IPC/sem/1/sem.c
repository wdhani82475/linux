#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/sem.h>







 union semun{
		 int   val;    /*Value for SETVAL */
		 struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
       unsigned short  *array;  /* Array for GETALL, SETALL */
	   struct seminfo  *__buf;  /* Buffer for IPC_INFO
																                                            (Linux-specific) */
																											           };


int main()
{
		key_t semkey;
		int ret;
		int sem_val;
	semkey=ftok("mytest",0xff);//ftok key value
	if(semkey == -1)
	{
		printf("ftok");
		exit(1);
	}
	else
			printf("semkey=%x\n",semkey);
	
	int semid=semget(semkey,1,IPC_CREAT|0755);//creat semid
	if(semid == -1)
	{
		perror("semget");
		exit(1);
	}
	printf("semid=%d\n",semid);
	
	//value && sem
	union semun init_val;//init value
	init_val.val=3;
	semctl(semid,0,SETVAL,init_val);
	sem_val=semctl(semid,0,GETVAL);
	if(sem_val == -1)
	{
		perror("GETVAL");
	}
	else
	printf("old sem_val=%d\n",sem_val);

/*	struct sembuf{
			short sem_num;
			short sem_op;
			short sem_flg;
			};*/
	struct sembuf op;
	op.sem_num=0;
	op.sem_op=3;
	op.sem_flg=0;

	semop(semid,&op,1);
	sem_val=semctl(semid,0,GETVAL);	
	if(sem_val == -1)
	{
		perror("GETVAL");
	}
	else
	printf(" new  sem_val=%d\n",sem_val);


	ret=semctl(semid,0,IPC_RMID);//delete sem
	if(ret == -1)
	{
		perror("failed delete.");
	}
	else
		printf("success delete.\n");

		
	return 0;
}
