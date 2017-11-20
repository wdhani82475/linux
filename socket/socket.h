#ifndef _SOCKET_H
#define _SOCKET_H
#define TCP 0
#define UDP 1
#define LISTEN_QUEUE_SIZE 5
int start_up(char* ip,short port,int mode)
{
	int sockfd;
	if(mode == TCP)
	{
		sockfd = socket(AF_INET,SOCK_STREAM,0);
	}
	else if(mode == UDP)
	{
		sockfd = socket(AF_INET,SOCK_DGRAM,0);
	}
	else
	{
		printf("socket bulid failed ，mode must is tcp or udp.\n");
		exit(1);
	}

		
	struct sockaddr_in address ;
	address.sin_family = AF_INET;
	address.sin_port = htons(port);
	address.sin_addr.s_addr = inet_addr(ip);
	
	socklen_t len = sizeof(struct sockaddr);
	int yes = 1;
	setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof(int));
	int ret = bind(sockfd,(struct sockaddr*)&address,len);
	if(ret == -1)
	{
		perror("bind");
		exit(-1);
	}

	if(mode == TCP)
	{
		ret = listen(sockfd,LISTEN_QUEUE_SIZE);
		if(ret == -1)
		{
			perror("listen");
			exit(1);
		}
	}

	return sockfd;

}	

#endif //_SOCKET_H
