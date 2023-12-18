#include<stdio.h>
#include<unistd.h>
#include<string.h>

void main()
{
	int p[2];
	pipe(p);
	printf("Read end of pipe= %d\tWrite end of pipe=%d\n",p[0],p[1]);
	if(fork())
	{
		char s[20];
		printf("In parent Enter data...\n");
		scanf("%s",s);
		write(p[1],s,strlen(s)+1);
	}
	else
	{
		char buf[20];
		printf("in child ...\n");
		read(p[0],buf,sizeof(buf));
		printf("Child pro printing... data... of parent process...%s\n",buf);
	}
}
