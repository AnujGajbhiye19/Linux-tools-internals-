#include<stdio.h>
#include<string.h>

int main()
{
	char buf1[10];
	char buf2[10];
	int ret;
	memcmp(buf1, "linux",5);
	memcmp(buf2, "LINUX",5);
	ret= memcmp(buf1, buf2, 5);
	printf("ret=%d\n\n",ret);
	if(ret>0)
		printf("buf1 is greater than buf2\n");
	else if(ret<0)
		printf("buf1 is less than buf2\n");
	else
		printf("buf1 is equal to buf2\n");

	return 0;

}
