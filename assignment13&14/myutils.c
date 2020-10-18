#include"myutils.h"

int factorial(int num)
{
    if(num>=1)
    {
        return num*factorial(num-1);
    }
    else
    {
        return 1;
    }

}

int isPrime(int number)
{
    if (number>1)                     //proceeds only if number is greater than 1
    {
        if (number==2 || number==3)        //returns 1 for 2 or 3
            return 1;
        else if (number%2==0)         //eliminates even numbers
            return -1;
        else
        {
            /*divides odd numbers less than n to see if there are
            any divisors.
            If there are none, it is prime*/
            for(int i=3;i<number;i+2)
            {
                if(number%i==0)
                    return -1;
                else
                    return 1;
            }
        }
    }
    else
        return 0;
}

int isPalindrome(int number)
{
	int reversed_number = 0, original_number;
    	original_number = number;

    	// reversed integer is stored in reversed_number
    	while (number != 0) 
	{
        	int remainder = number % 10;
        	reversed_number = (reversed_number * 10) + remainder;
        	number /= 10;
    	}
	return(reversed_number == original_number);
}

int vsum(int num,...)
{
    va_list valist;
    int sum = 0;
    va_start(valist,num);
    for(int i=0;i<num;i++)
    {
        sum += va_arg(valist,int);
    }
    va_end(valist);
    return sum;
}

