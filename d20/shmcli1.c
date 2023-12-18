#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/sem.h>
#include<string.h>

#define MY_KEY 1992
#define SHM_SIZE 0x1000
#define MSG_LEN 256

int main()
{
	int semid, shmid;
	char *pSHM;
	struct sembuf smop;
	semid = semget(MY_KEY, 1, 0660);
	
	if(semid < 0)
	{
		printf("could not create semaphore\n");
		return (1);
	}
	else
		printf("Opened a semaphore with id: %d\n", semid);
	
	shmid = shmget(MY_KEY, SHM_SIZE, 0660);
	if(shmid < 0)
	{
		printf("could not create a shared memory segment\n");
		return (2);
	}
	
	pSHM =  shmat(shmid, NULL, 0);
	if(!pSHM)
	{
		printf("could not attach shared memory address\n");
		return (3);
	}
	
	printf("CLIENT: \nEnter some request message to send to server...\n");
	fgets(pSHM, MSG_LEN, stdin);
	
	smop.sem_num = 0;
	smop.sem_op = 1;
	smop.sem_flg = 0;
	
	semop(semid, &smop, 1);
	
	return 0;
}
