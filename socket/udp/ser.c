#include"utili.h"

//ser
int main()
{
	int sockSer = socket(AF_INET,SOCK_DGRAM,0);
	if(sockSer == -1)
	{
		perror("sockSer");
		exit(1);
	}
	struct sockaddr_in addrSer,addrCli;
	addrSer.sin_family = AF_INET;
	addrSer.sin_port = htons(9090);
	addrSer.sin_addr.s_addr = inet_addr("127.0.0.1");
	socklen_t len = sizeof(struct sockaddr);

	int ret = bind(sockSer,(struct sockaddr*)&addrSer,len);
	if(ret == -1)
	{
		perror("bind");
		exit(1);
	}
	char sendbuf[BUFFER_SIZE];
	char recvbuf[BUFFER_SIZE];
	while(1)
	{
			
		recvfrom(sockSer,recvbuf,BUFFER_SIZE,0,(struct sockaddr*)&addrCli,&len);
		printf("Cli:>%s\n",recvbuf);
		printf("Ser:>");
		scanf("%s",sendbuf);
		sendto(sockSer,sendbuf,strlen(sendbuf)+1,0,(struct sockaddr*)&addrCli,len);
		
	}
	close(sockSer);
	return 0;
}


