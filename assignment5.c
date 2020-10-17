/*
Program to take any source file paths, options and linkers as string input from user and use gcc compiler
from the program.
*/
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<sys/wait.h>

int main()
{
    pid_t ret;
    int status;
    ret=fork();
    if(ret < 0)
    {
        perror("fork");
        exit(1);
    }
    if(ret == 0)
    {
        char input[100];                                                    //input string
        char* argsv[] ={ NULL };                                                //arrray of arguments to be passed
        printf("Enter path of program with linker libraries to compile:");  
        gets(input);                        
        //printf("input = %s",input);                                       //debug statement  
        /* The following code is to seperate the input string
        and put each argument into the argument array*/
        char* token;
        int index=0;
        int execute;
        argsv[index]="gcc";                                                 //First argument must be "gcc" passed to the command line
        index++;
        token=strtok(input," ");
        while(token != NULL)
        {
           argsv[index] = token;
           printf("%s ",token);
           token= strtok(NULL, " ");
           index++; 
        }
        
        argsv[index]= NULL;                                                 //Last argument must be NULL
        execute = execv("/usr/bin/gcc",argsv);                              //execv is used to implement gcc with argument array
        if(execute<0)
        {
            perror("execv");
            exit(2);
        }
        exit(0);

    }
    else
    {
        waitpid(-1,&status,0); 
        printf("parent--child exit status=%d\n",
			WEXITSTATUS(status));
		
    }
    return 0;

}