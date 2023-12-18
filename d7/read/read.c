#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	int fd;
	char buf[300];
	int res;
	fd= open("1.c", O_CREAT | O_RDWR, 664);
	printf("%d\n",fd);
	if(fd<0)
		printf("File is not opened or created\n");
	res=read(fd,buf,300);
	printf("bytes read: %d\n",res);
	printf("Data from buffer: \n%s\n",buf);
	close(fd);

	return 0;
}
