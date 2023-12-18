#include<stdio.h>
#include<signal.h>

/*
struct sigaction{
void(*)(int) sa_handler;
sigset_t sa_mask;
int sa_flags;
};
*/



void sigHandler(int sigNo)
{
	printf("Signal handler function dispalying sigNo:%d\n",sigNo);
	//signal(SIGINT,SIG_DFL);/** This will get default action***/
}


main()
{
	struct sigaction act;
	act.sa_handler=sigHandler;
	act.sa_flags=0;	/*Specifiers set of flags which modify the behaviour of the signal*/
	sigemptyset(&act.sa_mask);/*specifiers maks if signals which should be blocked during execution of signal handler*/
	sigaction(SIGINT,&act,0);
	//signal(sighandler,sig_DFL);
	while(1)
	{
		printf("Hello,world\n");
		sleep(1);
	}
}
