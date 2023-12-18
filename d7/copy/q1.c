
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
	int ipfd, opfd, openflags;
	mode_t fileperms;
	ssize_t numread;
	char buf[BUF_SIZE];

	ipfd= open(argv[1], O_RDONLY);
	if(ipfd==-1){
		printf("OPEN ERROR!!!\n");
	return 0; 
	}

	opfd= open(argv[2], O_RDWR,777);
	if(opfd==-1)
	{
		printf("OPEN ERROR!!!\n");
		return 0;
	}

	while((numread= read(ipfd, buf, BUF_SIZE)) > 0)
	{
		if(write(opfd, buf, numread) != numread)
		{
			printf("WRITE ERROR!!!\n");
			return 0;
		}
	}
	if(numread ==-1)
	{
		printf("READ ERROR!!!\n");
		return 0;
	}
	if(close(ipfd)==-1)
	{
		printf("Closed ip file\n");
		return 0;
	}
	if(close(opfd)==-1)
	{
		printf("Closed op file\n");
		return 0;
	}


	return 0;
}
