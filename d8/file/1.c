#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fd;
	fd = open("filex.txt", O_WRONLY | O_CREAT,0777 );
	printf("FD= %d\n", fd);
	while(1)
	{}

}
