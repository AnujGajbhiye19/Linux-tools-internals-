
#include<stdio.h>
#include<unistd.h>

void main(int argc, char * argv[])
{
	long int page_size = sysconf(_SC_PAGESIZE);

	printf("My pagesize: %ld\n",page_size);

	void* c1= sbrk(0);

	printf("Program break adderss: %p\n", c1);

	printf("Size of char: %lu\n",sizeof(char));

	c1= ((char*) c1 + 1);

	printf("c1: %p\n",c1);

	brk(c1);

	void *c2=sbrk(0);

	printf("program break address : %p\n",c2);
}
