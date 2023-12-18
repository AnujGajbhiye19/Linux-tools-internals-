#include<stdio.h>
#include<stdlib.h>
int main()
{
	int ret;
	printf("I am going to execute ls prgram \n");
	ret= execl("/bin/ps","ps","-elf",0);
	printf("l executed ps program: %d\n",ret);
	printf("l executed ps program: %d\n",ret);
	printf("l executed ps program: %d\n",ret);
	return 0;
}
