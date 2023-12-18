#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
   pid_t chpid,child1,child2,chpid1,chpid2;
   int ii,stat;
   
   printf("I am a parent process my process id is %d\n",getpid());
   printf("I am creating two child processes & make them rum some code\n");
   
   child1=fork();
   
   if(child1==0)
   {
       printf("I am first child,my pid is %d\n",getpid());
       printf("I am tired ,sleeping for 10 seconds\n");
       sleep(10);
       exit(0);
 
   }
   child2=fork();
   
   if(child2==0)
   {
       printf("I am a second child,my pid is %d\n",getpid());
       
       printf("I am tired ,sleeping for 5 sec\n");
      sleep(5);
       exit(0);

   }
   
   printf("I am Parent ,children are working & sleeping ,i wait for them\n");
   
   chpid1=waitpid(child1 , &stat,0);
      printf("MY first child terminated with status %d\n",WEXITSTATUS(stat));
      printf("Terminate child1 pid from wait =%d\n",chpid1);
   
   chpid2=waitpid(child2 , &stat ,0);
      printf("MY first child terminated with status %d\n",WEXITSTATUS(stat));
      printf("Terminated child2 pid from wait =%d\n",chpid2);
        
   printf("Both Children got teminated,i will do the same\n");

}

