#include"../calc.h"
#include"../socket.h"

void* handle(void* arg);

int main(int argc,char* argv[])
{
	int sockSer = socket(argv[1],atoi(argv[2]),TCP);
	printf("Server Wait Client Connect.......\n");
	int i=0;
	pthread_t tid[MAX_THREAD_NUM];
	for(;i<MAX_THREAD_NUM;i++)
	{
		pthread_create(&tid[i],NULL,threadle,&i);
		thread_pool[i].sockConn = 0;
		thread_pool[i].flag = 0;
		sleep(1);

	}
	calcst oper;
	struct sockaddr_in ddrCli;
	socklen_t len = sizeof(struct sockaddr);
	int sockConn;
	while(1)
	{
		sockConn = accept(sockSer,(struct sockaddr*)&addrCli,&len);
		if(sockConn == -1)
		{
			perror("Accept Client Connect Error.\n");
			continue;			
		}
		else
		{
			printf("<=======Client==========>\n");
			printf("ip = %s\n",inet_ntoa(addrCli.sin_addr));
			printf("port = %d\n",ntohs(addrCli.sin_port));
			printf("<=======Client===========>\n");
		}
		for(i=0;i<MAX_THREAD_NUM;++i)
		{
			if(thread_pool[i].flag == IDLE)
			{
				thread_pool[i].flag == BUSY;
				threaf_pool[i].sockConn == sockConn;
				break;
			}
		}
		if(i == )


	}
}
