#include "../utili.h"
// ./cli xx.xx.xx.xx 9090
int main(int argc,char* argv[])
{
	int sockCli = socket(AF_INET,SOCK_STREAM,0);
	if(sockCli == -1)
	{
		perror("socketCli");
		exit(1);
	}
	struct sockaddr_in addrSer;
	addrSer.sin_family = AF_INET;
	addrSer.sin_port = htons(atoi(argv[2]));
	addrSer.sin_addr.s_addr = inet_addr(argv[1]);
	socklen_t len = sizeof(struct sockaddr);
	int  ret =connect(sockCli,(struct sockaddr*)&addrSer,len);
	if(ret == -1)
	{
		printf("Cli connect failed.\n");
		exit(1);
	}
	else 
		printf("Cli connect success .\n");
	
	char sendbuf[BUFFER_SIZE];
	char recvbuf[BUFFER_SIZE];

	while(1)
	{
		recv(sockCli,recvbuf,BUFFER_SIZE,0);
		printf("Ser:>%s\n",recvbuf);
		printf("Cli:>");
		scanf("%s",sendbuf);
		if(!strcmp(sendbuf,"quit"))
			break;
		send(sockCli,sendbuf,strlen(sendbuf)+1,0);

	}
	close(sockCli);
	
		
	return 0;
	
}
