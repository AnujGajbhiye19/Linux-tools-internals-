#include<stdio.h>
#include<fcntl.h>
#include<sys/mman.h>
#include<string.h>

int main()
{
	char *c;
	c= mmap(0,512,PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_PRIVATE, -1,0);

	strcpy(c, "linuxkernel");

	printf("%s\n",c);

	munmap(c,512);

	return 0;
}
