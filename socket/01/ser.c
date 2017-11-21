#include"../utili.h"

int main()
{
	int sockSer = socket(AF_INET,SOCK_STREAM,0);
	if(sockSer == -1)
	{
		perror("socketSer");
		exit(1);
	}
	struct sockaddr_in addrSer,addrCli;
	addrSer.sin_family = AF_INET;
	addrSer.sin_port =htons(SERVER_PORT);
	addrSer.sin_addr.s_addr = inet_addr(SERVER_IP);
	socklen_t len = sizeof(struct sockaddr);

	int on = 1;
	setsockopt(sockSer,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on));



	int ret = bind(sockSer,(struct sockaddr*)&addrSer,len); 
	if(ret == -1)
	{
		perror("bind");
		exit(1);
	}
	
	ret = listen(sockSer,LISTEN_QUEUE_SIZE);
	if(ret == -1)
	{
		perror("listen");
		exit(1);
	}
	int sockCon=accept(sockSer,(struct sockaddr*)&addrCli,&len);//产生一个connfd，即一个客户端可服务器进行通信
	if(sockCon == -1)
	{
		printf("Ser connect cli  failed.\n");
	}
	else
	printf("Ser connect cli success.\n");
	printf("Cli Port:>%d\n",ntohs(addrCli.sin_port));
	printf("Cli  IP:>%s\n",inet_ntoa(addrCli.sin_addr));
				
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

