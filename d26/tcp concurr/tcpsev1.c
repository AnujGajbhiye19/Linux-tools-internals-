#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<netinet/in.h>

void handleclient(int connfd)
{
	int n;
	char buf[200];
	n = read(connfd, buf, 200);
	buf[n] = '\n';
	printf("data recieved from client = %s\n", buf);
	printf("request handled by server %d\n", getpid());
	write(connfd, "Good Bye", 8);
	exit(0);
}

void main()
{
	int listfd, connfd, retval;
	pid_t childpid;
	socklen_t clilen;
	struct sockaddr_in cliaddr, servaddr;
	
	listfd = socket(AF_INET, SOCK_STREAM, 0);
	if(listfd<0)
	{
		perror("sock:");
		exit(1);
	}
	
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	
	servaddr.sin_port = htons(8000);

	retval = bind(listfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
	
	if(retval<0)
	{
		perror("bind:");
		exit(2);
	}	
	
	listen(listfd, 5);
	
	while(1)
	{
		char buf[200];
		pid_t p;
		int n;
		clilen = sizeof(cliaddr);
		connfd = accept(listfd, (struct sockaddr *)&cliaddr, &clilen);
		printf("client connected\n");
		p = fork();
		if(p==0)
		{
			handleclient(connfd);
		}
		close(connfd);
	}
}
















