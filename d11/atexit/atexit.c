#include<stdio.h>
#include<stdlib.h>

void callback1()
{
	printf("callback1 fun called\n");
}
void callback2()
{
	printf("callback2 fun called\n");
}
void callback3()
{
	printf("callback3 fun called\n");
}

void main()
{
	printf("registering callback1\n");
	atexit(callback1);
	printf("registering callback2\n");
	atexit(callback2);
	printf("registering callback3\n");
	atexit(callback3);
	printf("main() exiting now...\n");
	exit(0);
}
