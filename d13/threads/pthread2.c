#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

//int i;

void *start_1(void *arg)
{
int i;
	for(i=0;i<100;i++)
		printf("Thd of control1\n");
}

//int i=0;

void *start_2(void *arg)
{
int i;
	for(i=0;i<100;i++)
		printf("** thd of control2\n");
}

void main()
{
	pthread_t pt1,pt2;
	getchar();
	pthread_create(&pt1,NULL,start_1,NULL);
	//getchar();
	pthread_create(&pt2,NULL,start_2,NULL);
	//getchar();
	
	pthread_join(pt1,NULL);
	pthread_join(pt2,NULL);

	printf("end of the main thread\n");
}
