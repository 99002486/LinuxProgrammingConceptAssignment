/* mini shell that can take 6 arguments*/
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

int main()
{
    pid_t ret;
    int status;
    char CLIin[100];
    printf("Enter your command:");
    scanf("%[^\n]%*c", CLIin);                  //read line
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
        char *argmts[6]={};                     //initilaize null array
        /*splitting input and storing into array as arguments*/
        char* token;
        char sep[2] = " ";
        token = strtok(CLIin," ");
        while (token != NULL)
        {
            argmts[arg_index]=token;
            printf("%s %d\n",argmts[arg_index],arg_index);
            token = strtok(NULL, " ");
            arg_index++;
        }
        /*executing using execp*/
        cmd_exec=execlp(argmts[0],argmts[0], argmts[1],argmts[2],argmts[3],argmts[4],argmts[5]);
        if(cmd_exec<0)
        {
            perror("execlp");
            exit(2);
        }
        exit(0);
    }
    else
    {
        waitpid(-1,&status,0); //wait(&status);
        printf("parent--child exit status=%d\n",
			WEXITSTATUS(status));
    }

    
}
