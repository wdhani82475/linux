

#include"utili.h"
int main()
{
	int read_fd=open(write_fifo,O_RDONLY);
		if(read_fd == -1)
		{
			perror("open write fail.\n");
			exit(1);
		}
		int ret;
	if(ret=(access(read_fifo,F_OK)!=0))
	{
		ret=mkfifo(read_fifo,O_CREAT|0755);
	
		if(ret == -1)
		{
			perror("mkfifo fail.\n");		
			close(read_fd);
			exit(1);
		}
	}
	int write_fd=open(read_fifo,O_WRONLY);
		if(write_fd == -1)
		{
			printf("open read_fifo fail.\n");
			close(read_fd);
			exit(1);
		}
	char send_buff[256];
	char recv_buff[256];
	while(1)
	{
		read(read_fd,recv_buff,256);
		printf("ser>>%s\n",recv_buff);
		printf("cli>");
		scanf("%s",send_buff);
		write(write_fd,send_buff,strlen(send_buff)+1);
	}
	close(read_fd);
	close(write_fd);
	return 0;
}
