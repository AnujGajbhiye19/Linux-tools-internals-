#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

pthread_once_t once = PTHREAD_ONCE_INIT;

void myinit()
{
	printf("\n I am in init function\n");
}

void *mythread(void *i)
{
	printf("\nI am in mythread: %d\n",(int*)i);
	pthread_once(&once,myinit);

	printf("\nExiting from mythread : %d\n",(int*)i);
}

int main()
{
	pthread_t th1,th2,th3;
	pthread_create(&th1, NULL, mythread, (void *)1);
	
	pthread_create(&th2, NULL, mythread, (void *)2);
	
	pthread_create(&th3, NULL, mythread, (void *)3);
	
	pthread_exit(NULL);

	return 0;
}
