#include<stdio.h>
#include<unistd.h>
int main()
{
	printf("one\n");

	if(fork()!=0)
	//fork();
	//fork();
{
	printf("two\n");//parent
}
else{
printf("three");//child
}
	//while(1);
	return 0;

}
