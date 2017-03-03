/**
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constant
#define LIMIT 65536

int main(int argc, string argv[])
{
    // you should input 2 or 3 command line argument
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    // transfer from string to int
    int n = atoi(argv[1]);

    // call the initialization functions,  which should be called before using drand48() and input the argv[2]
    if (argc == 3)
    {
        srand48((long int) atoi(argv[2]));
    }
    else
    {
        srand48((long int) time(NULL));
    }

    // Print arbitrary numbers with help of drand48() * 65536, becouse drand48() is [0.0;0.1] 
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48()*LIMIT));
    }

    // success
    return 0;
}