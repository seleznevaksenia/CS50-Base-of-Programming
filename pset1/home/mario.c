#include <stdio.h>
#include <cs50.h>

int main(void)
{
    
    //ask user for the half-pyramid’s height, a non-negative integer no greater than 23.
    
    int h ;
        do
        {
            printf("Put the half-pyramid’s height, a non-negative integer no greater than 23:\n");
            h = GetInt();
        }
         while ((h<0) || (h>23));
    
    char space = ' ';
    char reshetka = '#';
    for (int i = 2;i<=(h+1);i++) 
    {
        for (int ii = 1;ii<=(h-i+1);ii++)
            printf("%c", space);
        for (int iii = 1;iii<i;iii++ ) 
            printf("%c",reshetka);
        printf("%c\n",reshetka);   
    }        
}