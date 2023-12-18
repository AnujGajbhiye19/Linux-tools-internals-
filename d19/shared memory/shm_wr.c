#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>

int main(int argc, char *argv[])
{
	char *p;
	int id;
	
	id= shmget(48, 250, IPC_CREAT | 0644);
	
	if(id<0){
		perror("shmget");
		return 0;
	}
	
	printf("id= %d\n", id);
	
	p= shmat(id, 0,0);
	strcpy(p,argv[1]);
	//printf("enter the data: ");
	//scanf("%s",p);
	return 0;
}
