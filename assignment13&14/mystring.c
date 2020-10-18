#include"mystring.h"

int mystrlen(char* string_in)
{
    int n = 0;
    int i = 0;
    while(string_in[i]!='\0')
    {
        n++;
        i++;
    }
    return n;
}

int mystrcpy(char* destination, const char* source)
{
    int i = 0;
    while(source[i]!='\0')
    {
        destination[i] = source[i];
        i++;
    }
    destination[i+1] = '\0';
    return 0;
}

int mystrcmp(char* string1, char* string2)
{
    int i = 0;
    int ret_val = 0;
    while(string1[i]!='\0')
    {
        if(string1[i]!=string2[i])
        {
            ret_val = string1[i] - string2[i];
            break;
        }
        else
        {
            i++;
        }


    }
    return ret_val;
}
int mystrcat(char* destination, const char* string1, const char* string2)
{
    int i = 0;
    int j = 0;
    while(string1[i]!='\0')
    {
        destination[j] = string1[i];
        j++;
        i++;
    } 
    i=0;
    while(string2[i]!='\0')
    {
        destination[j] = string2[i];
        i++;
        j++;
    }
    destination[j+1] = '\0';
    return 0;
}