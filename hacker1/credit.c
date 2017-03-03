#include <stdio.h>
#include <cs50.h>
#include <math.h>

int len_digit(long long x)//Считаем длину числа
{
    int i = 0;   
    while (x>0)
    {
        x /= 10;
        i++;
    }
    return i;
}     

int main()
{
    int sum1 = 0,sum2 = 0,ost;
    printf("number:\n");
    long long x = GetLongLong();
    long long x_ = x;//Сохраняем первоначальное число, чтобы не потерять его
    int n = len_digit(x);
    for (int i = 0 ; i<n; i++)
    {
        ost = x%10;
        if (i%2 != 0) // Проверяем порядковый номер операции i на чётность/нечётность
        {
            if ((ost*2) >= 10)
            {
                 ost = (ost*2)%10+(ost*2)/10;
                 sum1 += ost;
             }// Перескладываем число, если при *2 получилось двухзначное 
            else
            {
                sum1 += ost*2;   
            }
        }
        else
        {
            sum2 += ost;
        }    
        x /= 10;    
    }
    
   
  
    if ((sum1+sum2)%10==0)
    {
        long long pow_13=x_/pow(10,12);// Выделяем первые проверочные числа карточки
        long long pow_16_=x_/pow(10,15);
        long long pow_16=x_/pow(10,14);
        long long pow_15=x_/pow(10,13);
    
        if (n == 15 && ( pow_15 == 34 || pow_15 == 37))
       {      
            printf ("AMEX\n");
       } 
    
        else if (n == 16 && pow_16>=51 && pow_16 <=55)
        {
            printf ("MASTERCARD\n");
        }
        
        else if (((n == 16) || (n == 13 )) && (( pow_16_==4) || ( pow_13 ==4)))
        {
            printf ("VISA\n"); 
        }
        else 
        {
            printf ("INVALID\n");    
        }
    }
    else
    {
        printf ("INVALID\n");
    }
}        

