#include<stdio.h>
#include<fcntl.h>
#define BUF_SIZE 1024


int main(int argc, char *argv[])
{
	int inputFd,outputFd,openFlags;
	mode_t fileperms;
	ssize_t numRead;
	char buf[BUF_SIZE];


	inputFd=open(argv[1],O_RDONLY);
	if(inputFd==-1)
	{
		printf("Open Error\n");
		return 0;
	}
	outputFd=open(argv[2],O_RDWR,777);
	if(outputFd==-1)
	{
		printf("Opening File\n");
		
		return 0;

	}

	while((numRead=read(inputFd,buf,BUF_SIZE))>0)
	{
		if(write(outputFd,buf,numRead)!=numRead)
		{
			printf("Write Error\n");
				return 0;
		}
		printf("%d\n",numRead);
	}
	if(numRead==-1)
	{
		printf("Read Error\n");
		return 0;
	}
	if(close(inputFd)==-1)
	{
		printf("Close input\n");
		return 0;
	}
	if(close(outputFd)==-1)
	{
		printf("Close Output\n");
		return 0;
	}
}
