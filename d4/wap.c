#include<stdio.h>
#include<stdlib.h>
void main()
{
int *ptr;
ptr=(int*)malloc(sizeof(int));
int x=1;
*ptr=x;
free(ptr);
*ptr=x;
printf("%d\n",*ptr);
}
