#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>//socket
#include<string.h>//memset
#include<netinet/in.h>//INADDR_ANY
#include<sys/socket.h>
#include<stdlib.h>//SIZE OF

#define PORT 8000
#define MAXSZ 100
int main()
{
	int listfd;//to create socket
	int newsockfd;//to accept connection
	int retval,sockfd,connfd;
	
	socklen_t clilen;
	struct sockaddr_in clientAddress,serverAddress;//serevr send to client on this address

	int n;
	char msg[MAXSZ];
	int clientAddressLength;
	
	//create a socket
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	//INITILIAZE THE SOCKET ADDRESSES
	memset(&serverAddress,0,sizeof(serverAddress));
//	bzero(&servaddr,sizeof(servaddr));
	serverAddress.sin_family=AF_INET;
	serverAddress.sin_addr.s_addr=htonl(INADDR_ANY);;
	serverAddress.sin_port=htons(PORT); //TCP protocol http-----port
//BIND THE SOCKET WITH THE SERVER ADDRESS AND PORTS

	retval=bind(listfd,(struct sockaddr *) &serverAddress,sizeof(serverAddress));
//listen for connection from client


	listen(sockfd,5);
	
	
	//accept a connection
	while(1)
	{
	printf("\n*******server waiting for new client connection*********\n");
	clientAddressLength=sizeof(clientAddress);
	newsockfd=accept(sockfd,(struct sockaddr*)&clientAddress,&clientAddressLength);//newcokfd is called client socket //accepted socket// connected socket
	
	//recieve from client
	while(1)
	{
	n=recv(newsockfd,msg,MAXSZ,0);//n=recv(skfd,msg,size,0)	cliwr(100)
	if(n==0)		//n=100
	{
	close(newsockfd);
	break;
	}
	msg[n]=0;
	send(newsockfd,msg,n,0);
	printf("Recieve and set:%s\n",msg);
	}//close interior while
}//close exterior while
	
	return 0;
}
	
	
	//recvfrom(skfd,ptr buempty,size,flag 0,sockaddr sock,size)	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
