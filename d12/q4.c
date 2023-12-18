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
		int ret;
		printf("I am going to execute ps prgram \n");
		ret= execl("/bin/ps","ps","-l",0);
		printf("this line will not get executed\n");
		exit(0);
	}
	printf("going into wait state\n");
	id=wait(&stat);
	printf("parent pid:%d\n",id);
	printf("\n\nParent process terminated\n\n");
	//printf("%d\n",WEXITSTATUS(stat));
	return 0;
}
