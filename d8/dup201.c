#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fd;
	fd = open("dumpdemo.txt",O_RDWR |  O_CREAT | O_TRUNC, 0666);
	if(fd<0)
	{
		printf("Could not open file\n");
		exit(2);
	}

	dup2(fd,1);
	printf("Sample string 1\n");
	printf("Sample string 2\n");
	puts("Sampe string 3\n");
}
