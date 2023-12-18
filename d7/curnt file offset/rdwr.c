#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	int fd, len;
	char write_buff[50]= "Hii, how are you? wow?";
	char read_buff[50];

	fd = open("question1c.txt", O_CREAT | O_RDWR, 777);

	len= write(fd, write_buff, 50);

	printf("Return value from write open: %d\n", len);

	lseek(fd, -20, SEEK_CUR);
	
	read(fd, read_buff,len);

	printf("Data from buffer (read option): %s\n", read_buff);

	close(fd);

	return 0;
}
