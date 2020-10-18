#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    int ret;
    ret=fork();
    if(ret<0)
    {
        perror("fork");
        exit(1);
    }
    if(ret==0)
    {
        printf("Enter pid:");
        char pid[1000],signal_num[10];
        scanf("%s",pid);
        printf("Enter Signal number/name with '-' :");
        int exec_ret;
        scanf("%s",signal_num);
        exec_ret=execlp("kill","kill",signal_num,pid,NULL);
        if(exec_ret<0)
        {
            perror("execlp");
            exit(3);
        }
        exit(0);

    }
    else
    {
        waitpid(-1,0,0);
        printf("Signal sent..");
    }
    
}
