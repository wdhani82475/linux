#include"../../utili.h"
#include"../../socket.h"
#include<poll.h>
#define	MAX_CLIENT_SIZE 5

int main(int argc,char*argv[])
{
	int sockSer = start_up(argv[1],atoi(argv[2]),TCP);
	struct sockaddr_in addrCli;
	socklen_t len = sizeof(struct sockaddr);
	char buffer[128];

	struct pollfd client_fd[MAX_CLIENT_SIZE+1];
	client_fd[0].fd = sockSer;//存放服务器的描述符
	client_fd[0].events = POLLIN;//带数据可读事件
	
	int i;
	for(i=1; i<MAX_CLIENT_SIZE; ++i)
	{
		client_fd[i].fd = 0;//客户端的描述符设置为0
	}
	int numfd = 1;
	while(1)
	{
		
		int ret = poll(client_fd,numfd,-1);//搭建服务器
		if(ret == -1)
		{
			perror("poll");
			continue;
		}
		else if(ret == 0)
		{
			printf("time out");
			continue;
		}
		else
		{
			if(client_fd[0].revents & POLLIN)//true
			{
				int connfd = accept(sockSer,(struct sockaddr*)&addrCli,&len);
				if(connfd == -1)
				{
					perror("accept");
					continue;
				}
				for(i=1;i<MAX_CLIENT_SIZE;++i)
				{
					if(client_fd[i].fd == 0)
					{
						client_fd[i].fd = connfd;
						client_fd[i].events = POLLIN;
						numfd++;
						break;
					}
				}
				if(i>=MAX_CLIENT_SIZE)
				{
					printf("Server Over Laod.\n");
				}
				else
				{
					printf("A new Client Come Baby....\n");
				}
			}
			else//通信
			{
					int recvbyte;
				for(i = 1; i<MAX_CLIENT_SIZE; i++)
				{
					if(client_fd[i].fd !=0 && (client_fd[i].events &POLLIN))
					 recvbyte = recv(client_fd[i].fd,buffer,128,0);
					/*if(recvbyte <= 0)
					{
						perror("recv data");
						break;
					}*/
					int sendbyte = send(client_fd[i].fd,buffer,strlen(buffer)+1,0);
			/*		if(sendbyte <= 0)
					{
						perror("send data");
						break;
					}  */

				}
			}

		}
	}
	close(sockSer);
	return 0;
}

