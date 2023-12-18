#include<stdio.h>
#include<signal.h>

void sighand(int sig_num)
{
	printf("abort signal rec'd \n");
	printf("we can use this to perform clean up op's\n");
}

main()
{
	signal(SIGABRT,sighand);
	printf("some thing has gone wrong \n");
	abort();

	printf("can you see this\n");
	printf("can you see this\n");
	printf("can you see this\n");
}

