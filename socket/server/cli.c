#include"calc.h"
// ./ xxx.xxx.xxx.xxx 9090
int main(int argc,char* argv[])
{
	int sockCli = socket(AF_INET,SOCK_DGRAM,0);
	if(sockCli == -1)
	{
		perror("sockCli");
		exit(1);
	}
	struct sockaddr_in addrCli,addrSer;
	addrSer.sin_family = AF_INET;
	addrSer.sin_port = htons(atoi(argv[2]));
	addrSer.sin_addr.s_addr = inet_addr(argv[1]);
	socklen_t len = sizeof(struct sockaddr);
	int ret = connect(sockCli,(struct sockaddr*)&addrSer,len);
	if( ret == -1)
	{
		perror("Cli connect Ser failed.\n");
		close(sockCli);
		exit(1);
	}
	else
	{
		printf("Cli connect Ser Sucess .\n");
	}
	calcst oper;
	char cmd[CMD_SIZE];
	int ret_byte_size;//send
	int result;
	while(1)// op1 op op2 
	{
		printf("please input cmd:");
		scanf("%s",cmd);
		printf("please input op1  and op2:");
		scanf("%d%d ",&oper.op1,&oper.op2);
		if(strcmp(cmd,"add") == 0)
		{
			oper.op = ADD;
		}
		else if(strcmp(cmd,"sub") == 0)
		{
			oper.op = SUB;
		}
		else if(strcmp(cmd,"mul") == 0)
		{
			oper.op = MUL;
		}
		else if(strcmp(cmd,"div") == 0)
		{
			oper.op = DIV;
		}
		else if(strcmp(cmd,"mod") == 0)
		{
			oper.op = MOD;
		}
		else if(strcmp(cmd,"quit") == 0)
		{
			break;
		}
		
		ret_byte_size = send(sockCli,&oper,sizeof(oper),0);//send op1 op2 op 
		if(ret_byte_size<0)
		{
			perror("send data error.\n");
			continue;
		}
		ret_byte_size = recv(sockCli,&result,sizeof(result),0);//recv result
		if(ret_byte_size<0)
		{
			perror("recv data error.\n");
			continue;
		}
		else
		{
			printf("result =%d\n",result);
		}
	}
	close(sockCli);
	return 0;
}


