
#include"../utili.h"

int main(int argc,char*argv[])
{
	int sockCli = socket(AF_INET,SOCK_STREAM,0);
	if(sockCli == -1)
	{
		perror("sockCli");
		return -1;
	}
	struct sockaddr_in addrSer;
	addrSer.sin_family = AF_INET;
	addrSer.sin_port = htons(atoi(argv[2]));
	addrSer.sin_addr.s_addr = inet_addr(argv[1]);
	socklen_t len = sizeof(struct sockaddr);
	int ret = connect(sockCli,(struct sockaddr*)&addrSer,len);
	if(ret == -1)
	{
		printf("Clinet Connect Server Error.\n");
		return -1;
	}
	else
		printf("Client Connect Servver Success.\n");

	char buffer[128];
	while(1)
	{
		printf("Cli:>");
		scanf("%s",buffer);
		if(!strcmp(buffer,"quit"))
				break;
	send(sockCli,buffer,strlen(buffer)+1,0);

	int	ret_byte_size=recv(sockCli,buffer,128,0);
	printf("From Slef Msg:>%s\n",buffer);
	}
	close(sockCli);
	return 0;
}
