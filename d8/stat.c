#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>

int main()
{
	struct stat st;
	int fd;

	fd= open("fcntl.c", O_RDONLY);

	fstat(fd , &st);

//	stat("fcntl.c", &st);

	printf("Filesize: %lu\n",(st.st_size));

	printf("File inode: %lu\n",(st.st_ino));

	printf("Size disk of blocks: %lu\n",(st.st_blksize));

	printf("File uid: %u\n",(st.st_uid));

	printf("File gid: %u\n",(st.st_gid));
	
	printf("\n\n");
	close(fd);
	return 0;
	
}
