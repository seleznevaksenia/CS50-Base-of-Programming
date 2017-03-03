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
    
    for (int i = 1;i <= h;i++) 
    {
        for (int ii = 0;ii<=(h-i-1);ii++)
            printf(" ");
        for (int iii = 0 ;iii<(i-1);iii++ ) 
            printf("#");
        printf("#  ");
        for (int iii = 0;iii<(i-1);iii++ ) 
            printf("#");
        printf("#\n");
        
    }        
}