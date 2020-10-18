#include <stdio.h>
#include <time.h>	// for clock_t, clock()
#include <unistd.h>	// for sleep()


// C program to find the execution time of code
int main()
{
	char a[]="Clock Cycle test";
	// to store execution time of code
	double time_taken = 0.0;

	clock_t start = clock();

	// do some stuff here
	for(int i=0;i<sizeof(a);i++)
	{
		printf("%c\n",a[i]);
	}
	sleep(2);

	clock_t finish = clock();

	// calculate taken time by finding difference (finish - start) and
	// divide by CLOCKS_PER_SEC to convert to seconds
	time_spent += (double)(finish - start) / CLOCKS_PER_SEC;

	printf("Time taken is %f seconds", time_taken);

	return 0;
}
