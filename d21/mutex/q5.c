#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

int sharedVar=0;   //our shared variable

pthread_mutex_t my_mutex;  //create mutex
int i;

void *thread_inc1(void *arg)
{
 printf("thread1 locked    \nthread 1 running    \nthread1 unlocked\n\n\n");
 pthread_mutex_lock(&my_mutex);     //take mutex
 for(i=0;i<100000;i++)
 sharedVar++;         // critical section 
 pthread_mutex_unlock(&my_mutex);  //release mutex
}

void *thread_inc2(void *arg)
{
 printf("thread2 locked    \nthread 2 running    \nthread2 unlocked\n\n\n");
 pthread_mutex_lock(&my_mutex);      //take mutex
 for(i=0;i<100000;i++)
 sharedVar++;                      //critical section
 pthread_mutex_unlock(&my_mutex);  //release mutex
}

int main()
{
 pthread_t thread1,thread2;

 pthread_mutex_init(&my_mutex,NULL);  //initialize mutex

 pthread_create(&thread1,NULL, thread_inc1,NULL);
 pthread_create(&thread2,NULL, thread_inc2,NULL);
 
 pthread_join(thread1,NULL);
 pthread_join(thread2,NULL);

 printf("sharedVar = %d\n",sharedVar);
 return 0;
}
