#include"../utili.h"
#include"../socket.h"
//./ser xx.xx.xx.xx 5050
int main(int argc,char* argv[])
{
		int sockSer;
		sockSer = start_up(argv[1],atoi(argv[2]),TCP);
		if(sockSer == -1)
		{
				perror("socket bind listen");
				exit(1);
		}
		struct sockaddr_in addrCli;
		socklen_t len = sizeof(struct sockaddr);
		int sockCon=accept(sockSer,(struct sockaddr*)&addrCli,&len);//产生一个connfd，即一个客户端可服务器进行通信
		if(sockCon == -1)
		{
				printf("Ser connect cli  failed.\n");
		}
	else{
		printf("Ser connect cli success.\n");
		printf("Cli Port:>%d\n",ntohs(addrCli.sin_port));
		printf("Cli  IP:>%s\n",inet_ntoa(addrCli.sin_addr));
	}
			char sendbuf[BUFFER_SIZE];
			char recvbuf[BUFFER_SIZE];
		while(1)
		{				
			printf("Ser:>");
			scanf("%s",sendbuf);
			send(sockCon,sendbuf,strlen(sendbuf)+1,0);
			recv(sockCon,recvbuf,BUFFER_SIZE,0);
			printf("Cli:>%s\n",recvbuf);
		}
						close(sockSer);


return 0;
}

