#include<pthread.h>
#include<stdio.h>
#include<unistd.h>

void *printhello(void *threadid)
{
	printf("\nhello world!!!\n");
	printf("Iam waiting\n");
	while(1);
}

int main()
{
	pthread_t thread;
	int rc, t=0;
	printf("Creating thread %d\n",t);
	rc= pthread_create(&thread, NULL, printhello, NULL);
//	pthread_join(thread,NULL);
	sleep(3);
	t=pthread_cancel(thread);
	if(t==0)
		printf("\ncancel thread\n");
	printf("\nThread ID= %lu\n",thread);

	return 0;
}
