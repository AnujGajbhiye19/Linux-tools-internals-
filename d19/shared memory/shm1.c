#include<stdio.h>
#include<sys/shm.h>
#include<string.h>

void main()
{
	char *ptr;
	int shmid, pid;
	
	shmid = shmget((key_t)1,20, IPC_CREAT|0666);
	
	ptr= (char *)shmat(shmid, (char *)0,0);// 2nd arg is address i.e. zero(leaving to kernel to map at free kernal address space)
											// SHM_RDONLY
	pid= fork();
	if(pid==0){
		strcpy(ptr, "shared Memory\n");
		
	}
	else{
		wait(0);
		printf("Parent reads ...%c\n", *(ptr+2));
		ptr[2] = 'o';
		printf("parent reads %s\n",ptr);
	}
}
