/**But you should check that the user’s input makes cents!
 * Er, sense. Using GetFloat alone will ensure that the user’s input 
 * is indeed a floating-point (or integral) value but not that it is non-negative.
 * If the user fails to provide a non-negative value, your program should re-prompt
 * the user for a valid amount again and again until the user complies.
 * 
 */

#include <stdio.h>
#include <cs50.h>
#include <math.h>


 int coins(int x)
 {
    if (x>=25)
    {
        return 25;
    }    
    else if (x>=10)
    {
        return 10;
    }    
    else if (x>=5)
    {
        return 5;
    }    
    else
    {
        return 1;    
    }
 }    

int main(void)
{
    float x_float;
    printf("O hai! How much change is owed?\t");
    x_float = GetFloat(); 
    while (x_float<0)
    {
      printf("How much change is owed?\t");
      x_float = GetFloat();  
    }
    x_float = x_float*100;
    x_float = round(x_float);
    int x = (int)x_float;
    int result = 0;
    int ost;
    do
    {
        int cel = x/ coins(x);
        ost = x % coins(x);
        result=result+cel;
        x=ost;
    }
    while (ost != 0);
    printf("%i\n",result);
}    