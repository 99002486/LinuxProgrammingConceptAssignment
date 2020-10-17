#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define A 500
#define B 600 
#define C 700
    
int main (int argc, char **argv)
{   
    int i, j;
    long sum;

    // Some arbitrary work done by the child

    printf ("Child: Hello, World!\n");

    for (j = 0; j < 30; j++ ) {
        for (i =0; i < 900000; i++) {
            sum = A * i + B * i * i + C;
            sum %= 543;
        }
    }

    printf ("Child: Work completed!\n");
    printf ("Child: Bye now.\n");

    exit (0);
}