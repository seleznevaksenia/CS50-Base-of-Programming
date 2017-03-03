#include <stdio.h>
#include <cs50.h>

int main(void)
{
    
    //ask user how long he takes his shower
    printf("How many minutes do you take shower?:\n");
    int min = GetInt();
    if (min<=0)
    { 
        do
        {
            printf("Minutes is a positive number!:\n");
            min = GetInt();
        }
         while (min<0);
    }
    int num = min*12;
        
    printf("You spent %d bottles of water, when you take a shower\n", num);
}