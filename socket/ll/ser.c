

#include"calc.h"
#include"../socket.h"

void process_handle(int connfd);
int main(int argc,char *argv[])
{
		int sockSer = start_up(argv[1],atoi(argv[2]),TCP);
		if(sockSer == -1)
		{
				perror("sockSer");
		}
		struct sockaddr_in addrCli;
		socklen_t len = sizeof(struct sockaddr);
		int connfd;
		pid_t pid;
		
		while(1)				
			{	connfd=accept(sockSer,(struct sockaddr*)&addrCli,&len);
				if(connfd == -1)
				{
						perror("Ser Conect Cli fail.\n");
						continue;
				}
				else
				{
				printf("Ser Connect Cli Success.\n");
				printf("Cli port = %d\n",ntohs(addrCli.sin_port));
				printf("Cli Ip=%s\n",inet_ntoa(addrCli.sin_addr));
				}
			
				pid = fork();
				if(pid>0)
				{
						close(connfd);
				}
				else if(pid == 0)
				{
						process_handle(connfd);
				}
				else
				{
						perror("fork");
				}
		}
		close(sockSer);
		return 0;

}
void process_handle(int connfd)//recv struct(oper1 oper2 op) // calc
{		
		//send result
		calcst oper;
		int result;
		int ret_byte_size;
		while(1)
		{
				ret_byte_size = recv(connfd,&oper,sizeof(oper),0);
				if(ret_byte_size<0)
				{
						perror("Ser recv Cli data fail.\n");
						continue;
				}                         //recv success 
				if(oper.op == ADD)
						result = oper.oper1+oper.oper2;
				else if(oper.op == SUB)
						result = oper.oper1-oper.oper2;
				else if(oper.op == MUL)
						result = oper.oper1*oper.oper2;
				else if(oper.op == DIV)
				{
						if(oper.oper2 == 0)
								printf("oper2 is error.\n");
						else
								result = oper.oper1/oper.oper2;
				}
				else if(oper.op == MOD)
						result = oper.oper1%oper.oper2;
				else if(oper.op == QUIT)
				{
					break;
				}
				ret_byte_size = send(connfd,&result,sizeof(result),0);
				if(ret_byte_size<0)
				{
						perror("Ser send Data to Cli fail.\n");
						continue;
				}
		}
}
