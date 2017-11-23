
#include"calc.h"

int  main(int argc,char* argv[])
{
	int sockCli = socket(AF_INET,SOCK_STREAM,0);
	if(sockCli == -1)
	{
		perror("sockCli");
	}
	struct sockaddr_in addrCli,addrSer;
	addrSer.sin_family=AF_INET;
	addrSer.sin_addr.s_addr = inet_addr(argv[1]);
	addrSer.sin_port = htons(atoi(argv[2]));
	socklen_t len = sizeof(struct sockaddr);
	int ret = connect(sockCli,(struct sockaddr*)&addrSer,len);
	if(ret == -1)
	{
		perror("Cli connect Ser failed.\n");
	}
	char cmd[CMD_SIZE];
	calcst oper;
	int ret_byte_size;
	int result;
	while(1)//cin  send() //recv()
	{
		printf("please input cmd:>");
		scanf("%s",cmd);
		printf("please input oper1 and oper2:>");
		scanf("%d %d",&oper.oper1,&oper.oper2);
		if(strcmp(cmd,"add") == 0)
			oper.op = ADD;
		else if(strcmp(cmd,"sub") == 0)
			oper.op = SUB;
		else if(strcmp(cmd,"mul") == 0)
			oper.op = MUL;
		else if(strcmp(cmd,"div") == 0)
			oper.op = DIV;
		else if(strcmp(cmd,"mod") == 0)
			oper.op = MOD;
		else if(strcmp(cmd,"quit") == 0)
		{
			break;
		}
		else 
			printf("please input current cmd.\n");
		ret_byte_size = send(sockCli,&oper,sizeof(oper),0);
		
			if(ret_byte_size<0)
			{
				perror("Cli send data error.\n");
				continue;
			}
		ret_byte_size = recv(sockCli,&result,sizeof(result),0);
		if(ret_byte_size<0)
		{
			perror("Cli recv data error.\n");
			continue;
		}
		printf("result = %d\n",result);
	}

		close(sockCli);	
	return 0;
}

