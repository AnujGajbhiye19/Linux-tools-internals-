#include<stdio.h>
#include<signal.h>

void sighand(int no)
{
	printf("I am in sighandler with sig_num =%d\n",no);
}

main()
{
	sigset_t s_set;
	signal(1,sighand);
	sigemptyset(&s_set);
	sigaddset(&s_set,1);
	perror("sig1");
	sigaddset(&s_set,4);
	perror("sig4");
	sigprocmask(SIG_BLOCK,&s_set,NULL);//SIG_Block: set of sig's pointed by set var are blocked for current process
	//sigprocmask(SIG_BLOCK|SIG_SETMASK,&s_set,NULL);
	perror("sigmask");
	printf("PID of the process =%d\n",getpid());
	printf("send me signal one and see the effect now \n");
	getchar();
	getchar();
	sigprocmask(SIG_UNBLOCK,&s_set,NULL);
	printf("Now signals are unblocked\n");
	while(1);
}
