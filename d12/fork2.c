#include<stdio.h>
#include<unistd.h>
int main()
{
	int id;
	int cnt=0;
	printf("I am going to create a new process!!!\n\n");
	id =fork();
	if(id)
	{
		while(cnt<10)
		{
			cnt++;
			printf("Iam parent, My child process is : %d\n\n",id);
			sleep(1);
		}
	}
	else
	{
		while(cnt<20)
		{
			cnt++;
			printf("Iam child Process, I got id : %d \n\n",id);
			sleep(1);
		}
	}
	return 0;
}
