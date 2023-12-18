#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<signal.h>


void sh_for_one(int signum)
{
	printf("This is handler for signal no one\n");
}

void sh_for_nine(int signum)
{
	printf("I am now handling signal no %d \n",signum);
}


int main()
{
	
	signal(1,sh_for_one);
	signal(SIGKILL,sh_for_nine);
	perror("sig install:");
	getchar();
	getchar();


	while(1)
	{
		sleep(1);
		printf("I am happy now,I will do same work forever\n");
	}
}

