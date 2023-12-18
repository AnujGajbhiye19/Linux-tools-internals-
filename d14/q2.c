#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void *proc(void* param)
{
	sleep(2);
	return(0);
}

int main()
{
	pthread_attr_t attr;
	pthread_t id;
	void *stack;
	size_t size;
	int err;

	size_t my_stacksize= 5 * 1024 * 1024;
	void* my_stack;

	pthread_attr_init(&attr);

	pthread_attr_getstacksize(&attr, &size);
	pthread_attr_getstackaddr(&attr, &stack);

	printf("Default: addr=%08x default size=%d\n",stack,size);

	my_stack= (void*) malloc(my_stacksize);

	pthread_attr_setstack(&attr, my_stack, my_stacksize);

	pthread_create(&id,&attr, proc,NULL);

	pthread_attr_getstack(&attr, &stack, &size);

	printf("Newly defined stack: addr=%08x and size =%d\n", stack, size);
	sleep(3);
	return (0);
}
