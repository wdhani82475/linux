
#include"utili.h"

int main()
{
	if(access(write_fifo,F_OK)!=0)
	{
		int ret=mkfifo(write_fifo,O_CREAT|0755);
		if(ret == -1)
		{
		perror("mkfifo error.\n");
		exit(1);
		}
	}
	printf("1111111111\n");
	int write_fd=open(write_fifo,O_WRONLY|O_NONBLOCK);
	if(write_fd == -1)
	{
		perror("open write  fail.\n");
		exit(1);
	}
	int read_fd=open(read_fifo,O_RDONLY);
	/*if(read_fd == -1)
	{
		perror("open read fail.\n");
	}*/
	while(read_fd == -1)
	{
		printf("cli is not start up.\n");
		sleep(1);
	}
	printf("222222222\n");
	char send_buff[256];
	char recv_buff[256];
	while(1)
	{
	printf("ser>>");
	scanf("%s",send_buff);
	write(write_fd,send_buff,strlen(send_buff)+1);
	read(read_fd,recv_buff,256);
	printf("cli>>%s\n",recv_buff);
	}
	close(write_fd);
	close(read_fd);

	return 0;
}
