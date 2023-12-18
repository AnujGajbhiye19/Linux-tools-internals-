#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("MAX FDs: %d\n", getdtablesize());
	exit(0);
	return 0;
}
