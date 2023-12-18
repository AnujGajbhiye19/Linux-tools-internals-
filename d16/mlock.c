
//#include<sys/mman.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
void main()
{
	size_t i;
	const int alloc_size= 4*1024;

	char *memory= alloca(alloc_size);

	mlock(memory, alloc_size);

	for(i=0; i<alloc_size;i++)
		memory[i]='0';

	printf("allocated memory initiated with : %s\n",memory);
	munlock(memory, alloc_size);
}
