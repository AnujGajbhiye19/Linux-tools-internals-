#include<stdio.h>
#include<string.h>

void main()
{
	char dest[]= "oldstring";
	const char src[]="newstring";

	printf("Before memmove dest: %s source= %s\n",dest, src);
	memmove(dest,src,9);
	printf("after memmove dest: %s source= %s\n",dest, src);
}
