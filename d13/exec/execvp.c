#include<stdio.h>
#include<unistd.h>
void main()
{
printf("i am going to execut ls program...\n");
char *args[3];
args[0]="ls";
args[1]="-l";
args[2]=0;
execvp("ls",args);
printf("i execed 'ls' process...\n");
}
