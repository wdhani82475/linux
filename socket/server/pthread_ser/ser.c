
#include"../calc.h"
#include"../../socket.h"

void*thread_handle(void *arg);
int main(int argc,char *argv[])
{
		int sockSer = start_up(argv[1],atoi(argv[2]),TCP);
		printf("Server Wait Client Connect.....\n");
		struct sockaddr_in addrCli;
		socklen_t len = sizeof(struct sockaddr);
		int connfd;
		while(1)
		{
				connfd = accept(sockSer,(struct sockaddr*)&addrCli,&len);
				if(connfd == -1)
				{
						perror("Accept Client Connect Error.\n");
						continue;
				}
				else 
				{
						printf("====================\n");
						printf("ip = %s\n",inet_ntoa(addrCli.sin_addr));
						printf("port = %d\n",ntohs(addrCli.sin_port));
						printf("====================\n");
				}

				pthread_t tid;
				pthread_create(&tid,NULL,thread_handle,&connfd);
		}
		close(sockSer);

		return 0;
}
void* thread_handle(void* arg)
{
		int connfd = *(int *)arg;
		int ret_byte_size;
		int result;
		calcst oper;
		while(1)
		{
				ret_byte_size = recv(connfd,&oper,sizeof(oper),0);
				if(ret_byte_size<0)
				{
						perror("Ser Recv Cli Data Error.\n");
						continue;
				}
				if(oper.op == ADD)
				{
						result = oper.op1+oper.op2;
				}
				else if(oper.op == SUB)
				{
						result = oper.op1-oper.op2;
				}
				else if(oper.op == MUL)
				{
						result = oper.op1*oper.op2;
				}
				else if(oper.op == DIV)
				{
						result = oper.op1/oper.op2;
				}
				else if(oper.op == MOD)
				{
						result = oper.op1%oper.op2;
				}
				else if(oper.op == QUIT)
				{
						printf("Cli Quit.\n");
						break;
				}

				ret_byte_size = send(connfd,&result,sizeof(result),0);
				if(ret_byte_size<0)
				{
						perror("Send Data Error.\n");
				}
				close(connfd);
		}
}


