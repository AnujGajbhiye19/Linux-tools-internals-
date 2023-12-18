#include<stdio.h>
void myprint(char *buff)
{
if(buff!=NULL)
printf("Messge: %s\n",buff);
}

int main()
{
char buff[]="Linux";
myprint(buff);
return 0;
}
