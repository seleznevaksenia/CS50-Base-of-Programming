/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool binary_search(int value, int sorted_values[], int min, int max)
{
   //Если максимальный индекс меньше минимального, т.е. элемент не найден
   if (max<min) 
   {
       return false;
   }
   else
   {    //Находим середину массива
       int midpoint = (max-min)/2+min;
        
        //Если значение в средней точке массива меньше искомого
        if (sorted_values[midpoint]<value)
        {
            return binary_search(value, sorted_values,midpoint +1, max);    
        }
        
        //Если значение в средней точке массива большого искомого
        else if (sorted_values[midpoint]>value)
        {
            return binary_search(value, sorted_values,min, midpoint -1); 
        }
        
        //Если значение в средней точке равно искомому
        else
        {
            return true;
        }
   }
}


bool search(int value, int values[], int n)
{
    int min = 0;
    int max = n-1;
    
    if (binary_search(value,values, min,max))
        {
            return true;    
        }
    
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{   //implement an O(n) sorting algorithm
    int zero_arr[65536];
    int i;
    int j;
    
    //creat a massive zero_arr[i], wich cotains only "0", 65535 - max value of number produced by random - LIMIT)
    for (i = 0; i< 65536; i ++)
    {
        zero_arr[i] = 0;
    }
    
    // put "1" in zero_arr[values[i]] and if have several same numbers in values, put +1
    for (i= 0; i < n-1; i++)
    {
        zero_arr[values[i]] ++;
    }
    // creat sored massiv, b - index of sorted massiv
    int b = 0;
    for (j = 0; j < 65534 ; j++)
    {
        // this circle doesn't impliment if zero_arr[j] ==0. If zero_arr[j] > 1, we will have the same value in several cell 
        for (i = 0; i < zero_arr[j]-1 ; i++)
        {
            values[b] = j;
            
            b++;
        }
    }
    
}