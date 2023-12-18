#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	int id, stat;
	id= fork();
	if(id==0)
	{
		printf("\nChildProcess\n");
		exit(0);
	}
	printf("going into wait state\n");
	id=wait(&stat);
	printf("pid:%d\n",id);
	printf("%d\n",WEXITSTATUS(stat));
	return 0;
}
