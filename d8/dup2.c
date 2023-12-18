#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fd1, fd2, fd3, fd4;
//	unmask(0);
	fd1=open("linux.txt",O_WRONLY | O_CREAT | O_TRUNC, 0777);
	fd2=open("p22.txt",O_WRONLY | O_CREAT | O_TRUNC, 0777);
	printf("FD of fp1=%d\n", fd1);
	printf("FD of fp2=%d\n", fd2);

	fd3= dup2(fd1,8);

	printf("fp3 is defined dup of fp1=%d\n", fd3);

	close(fd1);
	close(fd2);
	close(fd3);
}
