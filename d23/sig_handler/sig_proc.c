//shows how to send a signal to a process
#include<stdio.h>
#include<signal.h>
#include<sys/types.h>

int main()
{
	pid_t pid;
	int sig_no;
	printf("enter the pid of the process fir which the signal need to be sent:");
	scanf("%d",&pid);
	printf("Enter the signal that need to be sent");
	scanf("%d",&sig_no);
	kill(pid,sig_no);
	perror("Sig_rest:");
}
