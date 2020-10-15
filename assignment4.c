#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main()
{
    pid_t ret;
    int status;
    char CLIin[100];
    printf("Enter your command: ");
    scanf("%[^\n]%*c", CLIin);
    ret=fork();
    //printf("%s\n",CLIin);
    if(ret<0)
    {
        perror("fork");
        exit(1);
    }
    if(ret==0)
    {
        
        int cmd_exec,cmd_flag=0,arg_index=0;
        char *cmd,*argmts[10]={0};
        char* token;
        char sep[2] = " ";
        token = strtok(CLIin," ");
        while (token != NULL)
        {
            argmts[arg_index]=token;
            printf("%s\n",argmts[arg_index]);
            token = strtok(NULL, " ");
            arg_index++;
        }
        argmts[arg_index] = NULL;
        cmd=argmts[0];
        cmd_exec=execv(strcat("usr/bin",cmd),argmts);
        if(cmd_exec<0)
        {
            perror("execv");
            exit(2);
        }
        exit(0);
    }
    else
    {
        waitpid(-1,&status,0); //wait(&status);
    }
    
}
