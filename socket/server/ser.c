#include"calc.h"
#include"../../socket.hi"
void process_handler(sockConn);
int main(int argc,char *[argv])
{
	int sockSer = start_up(argv[1],atoi(argv[2]),TCP);
	socklen_t len = sizeof(struct sockaddr*);
	while(1)
	{
	int	sockConn = accept(sockSer,(struct sockaddr*)&addrCli,&len);
	if(sockConn == -1)
	{
		printf("Accept Client Connect Error.\n");
		continue;
	}
	pid_t pid = fork();
	if(pid == 0)
	{
		proccess_handler(sockConn);
	}
	else if(pid>0)
	{
		int status;
		wait(&status);	
	}
	return 0;
}
int  process_handler(sockConn)
{
	
}

