#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<sys/ipc.h>

void main()
{
	int qid;
	qid= msgget(555, IPC_CREAT | 644);
	printf("qid: %d\n\n",qid);
	getchar();
	msgctl(qid, IPC_RMID, NULL);
}
