#include<stdio.h>
#include<signal.h>

void sighand(int signum)
{
	printf("I have to wake up myboss\n");
	alarm(5);
}

main()
{
	signal(SIGALRM,sighand);
	alarm(5);
	printf("\n HELLO\n");
	while(1)
	{
	}
}
