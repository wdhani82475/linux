
#include"utili.h"
void write_msg(int fd);
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
	
	pid_t pid;
	pid =fork();
	if(pid == 0)
	{
		//write
		void write_msg(write_fd);
	}
	else if(pid>0)
	{
		pid=fork();
		if(pid==0)
		{
			//read
			void read_msg(read_fd);
		}
		else if(pid>0)
		{
			int status;
			waitpid(&status);
			close(write_fd);
			close(read_fd);
		}
		else
		{
			perror("fork fail.\n");
		}
	}
	else
	{
		perror("fork fail.\n");
	}
	

	char buf[256];
	void write_msg(fd)
	{
	while(1)
	{
	printf("Ser>>");
	scanf("%s",buf);
	write(fd,buf,strlen(buf)+1);
	if(strcmp(buf,"quit")==0)
	{
		break;
	}
	read(fd,buf,256);
	printf("Cli>>%s",buf);
	memset(buf,0,256);
	}
	}
	return 0;
}
