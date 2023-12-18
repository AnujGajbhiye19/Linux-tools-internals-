#include<stdio.h>
#include<stdlib.h>
int main()
{
	char *args[3];
	printf("im going to execute ls programin current program \n");
	args[0]="ls";
	args[1]="-l";
	//args[2]="bin";
	execv("/bin/ls",args);
	printf("i have run an exev program\n");
	return 0;
}
