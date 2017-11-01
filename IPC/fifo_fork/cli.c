

#include"utili.h"
void read_msg(int fd);
void write_msg(int fd);
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
	pid_t pid;
	pid = fork();
	if(pid==0)
	{
		read_msg(read_fd);
	}
	else if(pid>0)
	{
		pid = fork();
		if(pid==0)
		{
			write_msg(write_fd);
		}
		else if(pid>0)
		{
			int status;
			waitpid(&status);
			close(read_fd);
			close(write_fd);
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

	void read_msg(fd)
	{
		while(1)
		{
		printf("Ser>>");
		read(fd,buf,256);
		memset(buf,0,256);
		printf("Cli>>");
		scanf("%s",buf);
		write(fd,buf,256);
		if(strcmp(buf,"quit")==0)
		{
			break;
		}
		}
	}
	return 0;
}
