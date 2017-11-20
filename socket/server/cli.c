
#include"calc.h"

int main(int argc,char *argv[])
{
	int sockCli=socket(AF_INET,SOCK_STREAM,0);
	{
		if(sockCli == -1)
		return -1;
	}
	sockaddr_in addrSer;
	addrSer.sin_family = AF_INET;
	addrSer.sin_addr.s_addr = inet(argv[1]);
	addrSer.sin_addr_port = htons(argv[2]);
		
	oper op1,op2;
	calc op;
	socklen_t len = sizeof(struct sockaddr);
	while((int ret= Connect(sockCli,(struct sockaddr*)&sockSer,len) )!= -1)
	{

		printf("请输入操作符：\n");
		scanf("%s",&op);
		printf("请输入两个操作数："\n);
		scanf("%d %d",&oper.op1,&oper.op2);
		if(strcmp(op,"ADD") == 0)
		{
			
		}
		else if(strcmp(op,"SUB") == 0)
		{
		}
		else if(strcmp(op,"MUL") == 0)
		{

		}
		else if(strcmp(op,"DIV") == 0)
		{

		}
		else if(strcmp(op,"QUIT") == 0)
		{
			break;
		}

	}

	char sendbuf[BUFFER_SIZE];
	char recvbuf[BUFFER_SIZE];

	while(1)
	{	
		send(Cli,sendbuf,strlen(sendbuf)+1,0);
		recv(Cli,recvbuf,BUFFER_SIZE,0);
		printf("Ser:>%s\n",recvbuf);
	
	}
	close(sockSer);
	return 0;
}

