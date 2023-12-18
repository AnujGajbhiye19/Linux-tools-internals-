#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/shm.h>
#include<string.h>

#define MY_KEY 1992
#define SHM_SIZE 0x1000

int main()
{
	int semid, shmid;
	char *pSHM;
	struct sembuf smop;
	
	semid = semget(MY_KEY, 1, 0660 | IPC_CREAT);
	if(semid<0)
	{
		printf("Could not create Semaphore\n");
		return (1);
	}
	else
		printf("Opened semaphore ID is %d\n", semid);
	
	semctl(semid, 0, SETVAL, 0);
	
	shmid= shmget(MY_KEY, SHM_SIZE, 0660 | IPC_CREAT);
	if(shmid<0)
	{
		printf("could not create a shared segment\n");
		return (2);
	}
	
	pSHM = shmat(shmid, NULL, 0);
	if(!pSHM)
	{
		printf("could not attach shared memory segment\n");
		return (3);
	}
	
			smop.sem_num=0;//index of semaphore on semaphore array
			smop.sem_op=-1;//operation to do in smop
			smop.sem_flg=0;//flags
			
			semop(semid, &smop, 1);
	
	printf("Got the semaphore\n");
	printf("%s\n", pSHM);
	
	return 0;
}
