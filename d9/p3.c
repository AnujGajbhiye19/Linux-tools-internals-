#include<stdio.h>
int main()
{
	int n;
	printf("Enter a number: ");
	scanf("%d",&n);

	switch(n)
	{
		case 1:
			printf("Result : one\n");
			break;
		case 2:
			printf("Result : two\n");

		case 3:
			printf("Result : three\n");
			break;
		default:
			printf("INVALID\n");
			break;
	}
	return 0;
}
