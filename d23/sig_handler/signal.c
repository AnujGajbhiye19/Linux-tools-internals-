#include<stdio.h>
#include<signal.h>
#include<unistd.h>


void ouch(int sig)
{
	printf("OUCH -I got a signal %d\n",sig);
	(void) signal(sig,SIG_DFL);	//if we not use this it will go on running and to kill the process we should open new terminal and write(kill -2 pid of program)this will make just give the signal and if we give the cmd(kill -9 pid of process) this will immmediate killed the process) 
}

int main()
{
	(void) signal(SIGINT,ouch);
	printf("PID of the process=%d\n",getpid());
	while(1)
	{
		printf("hellow world\n");
		sleep(1);
	}
}
