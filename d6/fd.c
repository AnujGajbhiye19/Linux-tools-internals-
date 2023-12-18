#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fd1, fd2, fd3;

	fd1= open("linux111.txt", O_WRONLY , 777);
	fd2= open("linux111.txt", O_WRONLY , 777);

	printf("fd returned by kernel for linux111.txt : %d\n",fd1);
	printf("fd returned by kernel for linux111.txt : %d\n",fd2);

	//close(fd1);
	//close(fd2);
	printf("fd returned by kernel for closing linux111.txt : %d\n",close(fd1));
	printf("fd returned by kernel for closing linux111.txt : %d\n",close(fd2));
}
