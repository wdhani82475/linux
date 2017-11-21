
#include"../utili.h"
int main()
{
		int sockSer = socket(AF_INET,SOCK_STREAM,0);
				if(sockSer == -1)
				perror("sockSer");
	
		struct sockaddr_in addrSer,addrCli;
		addrSer.sin_family = AF_INET;
		addrSer.sin_addr.s_addr = inet_addr(SERVER_IP);
		addrSer.sin_port = htons(SERVER_PORT);
		socklen_t len=sizeof( struct sockaddr);

		int yes = 1;
		setsockopt(sockSer,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof(int));//重新获得ip和端口号

		int ret = bind(sockSer,(struct sockaddr*)&addrSer,len);
		{
				if(ret == -1)
						perror("bind");
		}
		ret = listen(sockSer,LISTEN_QUEUE_SIZE);
		if(ret == -1)
		{
				perror("listen");
		}
		int connfd;
		/*

		while( (connfd=accept(sockSer,(struct sockaddr*)&addrCli,&len)) == -1)
		{
				printf("Ser Connect Cli fail.\n");
		}
		*/  //产生一个新的描述符,即一个客户端与服务器进行通信
		char sendbuf[BUFFER_SIZE];
		char recvbuf[BUFFER_SIZE];
		while(1)
		{
				
		 if((connfd=accept(sockSer,(struct sockaddr*)&addrCli,&len)) == -1)//服务器和客户端通信一次结束后,会产生新的描述符即(可以实现不同的客户端和服务器进行通信(但只能客户端进行通信一次)（因为accept()为阻塞函数），总在等待connfd)
		{
				printf("Ser Connect Cli fail.\n");
		}
				printf("Ser:>");
				scanf("%s",sendbuf);
				send(connfd,sendbuf,strlen(sendbuf)+1,0);
				recv(connfd,recvbuf,BUFFER_SIZE,0);
				printf("Cli:>%s\n",recvbuf);
		}
		close(sockSer);
		return 0;
}
