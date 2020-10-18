//c program for creating multiple child processes for linking and executing multiple files
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>


int main()
{
    int n1,n2,n3,n4;
    pid_t pid1,pid2,pid3,pid4,pid5,pid6,pid7;
    int exec_code1,exec_code2,exec_code3;
    n1=fork();
    switch(n1)
    {
    case(-1):
        perror("fork");
        exit(1);
    case(0):

        exec_code1 = execlp("gcc","gcc","-c","test.c","bitmask.c","mystring.c","myutils.c",NULL);
        if(exec_code1<1)
        {
            perror("execlp");
            exit(2);
        }
        break;
    default:
        waitpid(-1,0,0);
        printf("compilation success\n");
        n2=fork();
        break;
    }
    switch(n2)
    {
    case(-1):
        perror("fork");
        exit(1);
    case(0):
        
        exec_code2 = execlp("ar","ar","rc","libmyfunctions.a","bitmask.o","mystring.o","myutils.o",NULL);
        if(exec_code2<1)
        {
            perror("execlp");
            exit(2);
        }
        break;
    default:
        waitpid(-1,0,0);
        printf("library creation success\n");
        n3=fork();
        break;
    }
    switch(n3)
    {
    case(-1):
        perror("fork");
        exit(1);
    case(0):
        exec_code3 = execlp("gcc","gcc","-L.","test.o","-o","libout.out","-lmyfunctions",NULL);
        if(exec_code3<1)
        {
            perror("execlp");
            exit(2);
        }
        break;
    default:
        waitpid(-1,0,0);
        printf("library link success\n");
        n4=fork();
        break;

    }
    switch(n4)
    {
    case(-1):
        perror("fork");
        exit(1);
    case(0):
        
        exec_code2 = execl("libout.out","libout.out",NULL);
        if(exec_code2<1)
        {
            perror("execlp");
            exit(2);
        }
        break;
    default:
        waitpid(-1,0,0);
        printf("execution success\n");
        break;
    }

    

}
