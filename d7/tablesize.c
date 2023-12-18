#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
void main()
{
	printf("max fds:%d\n",gettablesize());
	exit(0);
}
