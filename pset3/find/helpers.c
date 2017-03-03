/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

#include <stdio.h>

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
{
    
    // insertion sort
    //Перебираем элементы неотсортированной части
    for (int i=1; i < n; i++)
    {
        int x = values[i]; //первый неотсортированный элемент
        int j = i;
        //пока неотсортированный элемент больше отсортированного, сдвигаем вправо отсортированные
        while ( j>0 && values[j-1] > x)
        {
              values[j]  = values[j-1]  ;
              j--;
        } 
        //присваиваем значение неотсортированного элемента впереди отсортированного большего х
        values[j] = x;
              
    }
    for (int i = 0;  i < n; i++)
    {
        printf("sort%i\n",values[i]);
    }
    // TODO: implement an O(n^2) sorting algorithm
    return;
}
