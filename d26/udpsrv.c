#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<netinet/in.h>

void main()
{
 int sockfd,retval,n;

 socklen_t clilen;
 struct sockaddr_in cliaddr,servaddr;
 char buf[100];

 sockfd=socket(AF_INET,SOCK_DGRAM,0);
 if(sockfd<0)
 {
  perror("sock:");
  exit(1);
 }

 bzero(&servaddr,sizeof(servaddr));
 servaddr.sin_family=AF_INET;
 servaddr.sin_addr.s_addr=htonl(INADDR_ANY);//htonl:host t network long 
 servaddr.sin_port=htons(8000);

 retval=bind(sockfd,(struct sockaddr *) &servaddr,sizeof(servaddr));

 if(retval<0)
 {
  perror("bind:");
  exit(2);
 }

 printf("socket bound to port 8000");
 clilen=sizeof(struct sockaddr_in);
 while(1)
 {
  printf("before recvfrom\n");
  n=recvfrom(sockfd,buf,100,0,(struct sockaddr *)&cliaddr,&clilen);
  printf("rev'd %d bytes\n",n);
  buf[n]='\0';
  printf("msg from client=%s\n",buf);
 }

}

