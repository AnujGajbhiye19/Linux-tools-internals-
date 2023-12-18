#include<stdio.h>
#include<string.h>

int main()
{
	const char str[]= "linuxkernel.com";
	const char ch='#';

	printf("string before set initialization: %s\n",str);

	memset(str+8,ch,5);

	printf("string after set is: %s\n",str);
	
	return 0;
}
