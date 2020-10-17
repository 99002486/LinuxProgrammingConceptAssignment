#include<unistd.h>
#include<fcntl.h>

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int* fd;
    int nbytes;
	char c;
    int word_count=0;
    int char_count=0;
    int line_count=0;
    fd=fopen("Result.csv",O_RDONLY);
	if(fd<0)
	{
		perror("open");
		exit(1);
	}
    for (c = getc(fd); c != EOF; c = getc(fd)) 
    {
        char_count++;
        if (c == '\n') // Increment count if this character is newline 
            line_count++;
        if (c == ' ' | c == ',')
            word_count++;
    }
    printf("cc = %d,wc = %d,lc = %d",char_count,word_count,line_count);    
}