#include<stdio.h>
#include<string.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/socket.h>

#define PORT 8000
#define SERVER_IP "127.0.0.1"
#define MAXSZ 100
int main()
{
	int sockfd,connfd,retval;	// to create socket
	
	socklen_t clilen;
	struct sockaddr_in serverAddress,clientAddress; //client will connect on this
	
	int n;
	char msg1[MAXSZ];
	char msg2[MAXSZ];
	
	//CREATE SOCKET
	sockfd=socket(AF_INET,SOCK_STREAM,0);
//INITLIAZE THE SOCKET ADDRESSESS

//	bzero(&servaddr,sizeof(servaddr));
	serverAddress.sin_family=AF_INET;
	serverAddress.sin_addr.s_addr=inet_addr(SERVER_IP);
	serverAddress.sin_port=htons(PORT);
	
	//client connect to server on port
	retval=connect(sockfd,(struct sockaddr *)&serverAddress,sizeof(serverAddress));
	//send to sever and recieve from server
	while(1)
	{
	printf("\nEnter message to send to server:\n");
	fgets(msg1,MAXSZ,stdin);
	if(msg1[0]=='#')
	break;
	
	n=strlen(msg1)+1;
	send(sockfd,msg2,MAXSZ,0);
	
	n=recv(sockfd,msg2,MAXSZ,0);
	
	printf("Recieve from the server:%s\n",msg2);
	}
	
	return 0;
	}

