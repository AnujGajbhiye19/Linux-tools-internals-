#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("My process ID : %d\n",getpid());
	printf("My parent PID : %d\n",getppid());

	printf("Linux Karnel\n");
	while(1);
	return 0;
	
}
