#include<unistd.h>
#include<fcntl.h>

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int fd,nbytes;
	fd=open("Results.csv",O_RDONLY);
	if(fd<0)
	{
		perror("open");
		exit(1);
	}
	int len=135;
	char buf[len];
	nbytes=read(fd,buf,len);
	if(nbytes<0)
	{
		perror("read");
		exit(2);
	}
    buf[len]='\0';
    printf("%s\n",buf);
    close(fd);
}