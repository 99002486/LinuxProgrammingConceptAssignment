#include"bitmask.h"
#include"mystring.h"
#include"myutils.h"

int main()
{
    int fact_val = factorial(5);
    int prime_val = isPrime(3);
    int palind_val = isPalindrome(12321);
    int sum = vsum(3,41,32,60);
    
    printf("factorial = %d, prime? %d, palindrome? %d vsum = %d \n",fact_val,prime_val,palind_val,sum);

    char string1[10] = "potatoes";
    char string2[10] = "potaters";
    char stringcopy[10];
    char stringcatenate[30];
    int stringlength = mystrlen(string1);
    printf("length of string = %d \n",stringlength);
    mystrcpy(stringcopy,string1);
    printf("copied string = %s \n", stringcopy);
    mystrcat(stringcatenate,string1,string2);
    int compare_val = mystrcmp(string1,string2);
    
    
    printf("string comparevalue = %d \n", compare_val);
    printf("string cat = %s \n",stringcatenate);
    int set_bit = set(32,3);
    printf("0x%x \n",set_bit);
    int reset_bit = set(set_bit,3);
    printf("0x%x \n",reset_bit);
    int flip_bit = flip(reset_bit,3);
    printf("0x%x \n",flip_bit);
    int qry = query(flip_bit,3);
    printf("%d \n",qry);
}