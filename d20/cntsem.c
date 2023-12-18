#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
void* func1(int x);
int p=5;
sem_t s;
int q=3;
int cd=1;

int num;
int main()
{


	sem_init(&s,0,3);
	printf("Enter number of thread want to create\n");
	scanf("%d",&num);

	pthread_t thread[num];
	for(int i=0;i<num;i++)
	 {
	 	pthread_create(&thread[i],NULL,func1,NULL);
	 
	 }
	 
	for(int i=0;i<num;i++)
	 	pthread_join(thread[i],NULL);
}


void* func1(int x)
{
	//p++;
	int n=x;
	//static int a=2;
	sem_wait(&s);
	if(p<7)
	{
		p++;
		printf("thread %d is sleeping fort 30 sec\n",p-5);
		sleep(15+p);
	}
	if(q<num+1)
	{
		printf("Thread[%d] acquired the resource \n",q++);
	}
	else
	{
		sleep(4);
		printf("Thread[%d] acquired the resource \n",cd++);
	}
	sleep(2);
	//a=a+2;
	sem_post(&s);
	printf("Finished\n");
}
