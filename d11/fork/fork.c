#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
void main()
{
	int pid_1;

	printf("Current process pid: %d\n", getpid());

	pid_1= fork();
	printf("PID_1=%d\n",pid_1);
	if(pid_1==0)
	{
		//sleep(5);
		printf("New child process pid= %d\n",getpid());
		printf("New child parent process ppid= %d\n",getppid());
	}
	else
	{
		//sleep(3);
		printf("Parent process pid= %d\n",getpid());
		printf("Parent's parent process ppid= %d\n",getppid());
	}
//	while(1)
//	{
//		sleep(3);
//		break;
//	}
	exit(0);
}
