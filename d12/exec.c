#include<stdio.h>
#include<stdlib.h>
int main()
{
	int ret;
	printf("I am going to execute ps prgram \n");
	ret= execl("/bin/ps","ps","-l",0);
	printf("this line will not get executed\n");
	
	return 0;
}
