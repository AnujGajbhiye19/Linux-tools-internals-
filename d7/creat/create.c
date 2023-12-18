#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fd1, fd2, fd3;

	fd1= creat("linux100.txt",777);

	fd2= creat("linux200.txt",777);

	fd3= creat("linux300.txt",777);

	printf("fd for linux100.txt: %d\n",fd1);
	printf("fd for linux200.txt: %d\n",fd2);
	printf("fd for linux300.txt: %d\n",fd3);

	close(fd1);
	close(fd2);
	close(fd3);
	return 0;
}
