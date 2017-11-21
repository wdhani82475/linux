#include"../calc.h"
#include"../../socket.h"


int main(int argc,char* argv[])
{
	int sockSer = start_up(argv[1],atoi(argv[2]),TCP);
	if(sockSer == -1)
	{
		perror("sockSer");
		exit(1);
	}
	struct sockaddr_in addCli;
	socklen_t len = sizeof(struct sockaddr);
	int connfd ;
	pid_t pid;
	while(1)
	{
		if((connfd= accept(sockSer,(struct sockaddr*)&addCli,&len)) == -1)
		{
		perror("connfd.");
		continue;
		}
		else
		{
			pid = fork();
			if(pid == 0)
			{
				handle(connfd);		
			}
			else if(pid>0)
			{
				close(sockSer);
			}
			else
			{
				perror("fork");
				exit(1);
			}

		}

	}
	
	return 0;
}

void handle(int connfd)
{
	calcst oper;
	int ret_byte_size;
	int result;
	while(1)
	{
		ret_byte_size = recv(connfd,&oper,sizeof(oper),0);
		if(ret_byte_size<0) 	
		{
			perror("Ser recv Cli Data error.\n");
			continue;
		}
		if(oper.op == ADD)
		{
			result = oper.op1+oper.op2;
		}
		else if(oper.op == SUB)
		{
			result = oper.op1 - oper.op2;
		}
		else if(oper.op == MUL)
		{
			result = oper.op1*oper.op2;
		}
		else if(oper.op == DIV)
		{
			if(oper.op2 == 0)
			printf("oper.op2 is error.\n");
			else
			{
				result = oper.op1/oper.op2;
			}
		}
		else if(oper.op == MOD)
		{
			result = oper.op1%oper.op2;
		}
		ret_byte_size = send(connfd,&result,sizeof(result),0);
		if(ret_byte_size<0)
		{
			perror("Ser send Cli error.\n");
			continue;
		}
	
		
	}
}

