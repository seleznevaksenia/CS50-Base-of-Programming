#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main()
{
    string  full_name = GetString();
    printf ("%c",toupper(full_name[0]));
    int size = strlen(full_name), i=1;
   
    while (i<size)
    {
        if (full_name[i] != ' ')
        {           
            i++;
        } 
        else
        {
            i++;
            printf ("%c",toupper(full_name[i]));
        }
    }
     printf("\n");
}     