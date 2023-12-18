#include<stdio.h>
#include<unistd.h>
int main()
{
	printf("one\n");

	fork();
	fork();
	fork();

	printf("two\n");
	while(1);
	return 0;

}
