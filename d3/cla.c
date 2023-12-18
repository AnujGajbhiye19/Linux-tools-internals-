#include<stdio.h>
#include<stdlib.h>

int main (int argc, char *argv[])
{
int i;
printf("\nFilename: %s\n", argv[0]);//a.out
printf("\nTotal no. of arguments: %d", argc);
printf("\nArguments passed: ");
for(i=0;i<argc;i++)
	printf("%s ",argv[i]);
printf("\n");
}
