#include<stdio.h>
void main()
{
printf("i am going to execut ls program...\n");
execlp("ls","ls","-l",0);
printf("i execed 'ls' process...\n");
}
