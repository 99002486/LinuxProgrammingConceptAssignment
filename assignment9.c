#include <stdio.h>
#include <time.h>
 
int main()
{
    time_t Time= time(NULL);
    struct  tm current_tm = *localtime(&Time);
     

    printf("The Time is: %02d:%02d:%02d\n",current_tm.tm_hour, current_tm.tm_min, current_tm.tm_sec);
 
    return 0;
}
