#include <stdio.h>
#include <time.h>	// for clock_t, clock()
#include <unistd.h>	// for sleep()


// C program to find the execution time of code
int main()
{
    int a=57,b=100;
	// to store execution time of code
	double time_spent = 0.0;

	clock_t begin = clock();

	// do some stuff here
    printf("%d\n%d\n",a+b,a*b);
	sleep(3);

	clock_t end = clock();

	// calculate elapsed time by finding difference (end - begin) and
	// divide by CLOCKS_PER_SEC to convert to seconds
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

	printf("Time elpased is %f seconds", time_spent);

	return 0;
}