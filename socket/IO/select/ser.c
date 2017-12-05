#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<sys/select.h>
#include<stdlib.h>
#include"../../socket.h"

#define MAX_CLIENT_SIZE 5

int main(int argc,char*argv[])
{
		int sockSer = start_up(argv[1],atoi(argv[2]),TCP);
		int client_conn_num = 0;
		int client_sockConn[MAX_CLIENT_SIZE] = {0};
		struct sockaddr_in addrCli;
		socklen_t len = sizeof(struct sockaddr);
			
		char buffer[128];
		fd_set set;
		FD_ZERO(&set);
		int maxfd = sockSer;
		int i;
		while(1)
		{
			FD_ZERO(&set);
			FD_SET(sockSer,&set);
			for(i=0; i<MAX_CLIENT_SIZE; i++)
			{
				if(client_sockConn[i] != 0)
				{
					FD_SET(client_sockConn[i],&set);
				}
			}
			printf("Server Wait.....\n");
			int ret = select(maxfd+1,&set,NULL,NULL,NULL);
			if(ret == -1)
			{
				perror("select");
				continue;
			}
			else if(ret == 0)
			{
				printf("time out\n");
				continue;
			}
			else
			{
				if(FD_ISSET(sockSer,&set))//创建新的套接字，并且连
				{
					int sockConn = accept(sockSer,(struct sockaddr*)&addrCli,&len);	
					if(sockConn == -1)
					{
						printf("Ser Accept Cli failed.\n");
						continue;
					}
					else
					{
						printf("A New Client Come Baby.\n");
						client_conn_num++;
						for(i=0; i<MAX_CLIENT_SIZE;i++)
						{
							if(client_sockConn[i] == 0)
							{
								client_sockConn[i] == sockConn;
								break;
							}
						}
						if(i >= MAX_CLIENT_SIZE)
						{
							printf("Ser Over Load.\n");
						}
						else
						{
							if(sockConn>maxfd)
							maxfd = sockConn;
						}


					}

				}
			else
				{
					printf("Server Handle Client Msg.\n");
					for(i=0; i<MAX_CLIENT_SIZE;i++)
					{
						if(FD_ISSET(client_sockConn[i],&set))
						{
							int recvbyte = recv(client_sockConn[i],buffer,128,0);
							if(recvbyte<0)
							{
								printf("Ser recv Data Error.\n");
								continue;
							}
							send(client_sockConn[i],buffer,strlen(buffer)+1,0);
						
							
						}
					}
				}
			}
		}


	close(sockSer);
	return 0;
}


