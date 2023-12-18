#include<stdio.h>
#include<sched.h>

int main()
{
	int policy;
	printf("my pid is %d \n",getpid());

	policy=sched_getscheduler(0);	//fetching thesched policy of the curent proces

	switch(policy)
	{
		case SCHED_OTHER:
			printf("Policy is normal\n");
			break;
		case SCHED_RR:
			printf("Policy is round robin\n");
			break;
		case SCHED_FIFO:
			printf("policy is first in first out.\n");
			break;
		case -1:
			perror("sched_getscheduler");
			break;
		default:
			fprintf(stderr,"unknown policy!\n");
	}

	getc(stdin);

	struct sched_param sp={.sched_priority=1};	// it is a structure that contains argument parameter var wihc are used for changing the shceduler policy
	int ret;

	ret = sched_setscheduler(0,SCHED_RR,&sp);	// arg1:0 going to set change schd policy of the current process ///arg2: policy name /// arg3:address of var 'struct shced param'

	if(ret=-1)
	{
		perror("sched_setshcedeuler");
		return 1;
	}


	policy=sched_getscheduler(0);

	switch(policy)
	{
		case SCHED_OTHER:
			printf("Policy is normal\n");
			break;
		case SCHED_RR:
			printf("Policy is round robin\n");
			break;
		case SCHED_FIFO:
			printf("Policy is first in first out\n");
			break;
		case -1:
			perror("sched_getscheduler");
			break;
		default:
			fprintf(stderr,"unknown policy!\n");
	}

	getc(stdin);
	while(1)
	return 0;
}
