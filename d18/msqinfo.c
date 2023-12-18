#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

#define KEY 1123



main()
{
 int qid;
 struct msqid_ds info;
 qid = msgget(KEY, IPC_CREAT|0644);
 printf(" qid = %d\n",qid);
 msgctl(qid,IPC_STAT,&info);
 printf(" Here are the details of the queue\n");
 printf("no pf msg's in q %d\n",info.msg_qnum);
 printf("no pf bytes in q %d\n",info.msg_cbytes);
 msgctl(qid, IPC_RMID, NULL);
 printf("Message queue Removed successfully\n");

}
