/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#include <stdint.h>
#include <ctype.h>

#include "dictionary.h"
#define SIZE 144000

//struct of hash table
typedef struct node{
    char word[LENGTH+1];
    struct node* next;
    
}node;
node* array[SIZE] = {NULL};
int size_dictionary;
unsigned int hash_func(const char* word);
unsigned int hash;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word_check)
{
   char buffer[LENGTH+1];
   int len = strlen(word_check);
    for (int i = 0 ; i < len ; i++)
    {
        //Переводим буквы слова,которое проверяем в нижний регистр
		buffer[i] = tolower(word_check[i]);
	}
	
	//Последний символ нашего массива "\0"
	buffer[len] = '\0';
	//Кодирем слово
    hash = hash_func(buffer);
    if (array[hash] == NULL )
    {
        return false;
    }
    //_item - указатель на элемент массива с индексом hash
    node* _item = array[hash];//Присваимваем указатель, который указывает на root new element
   
   //двигаемся по связанному списку с корнем в array[hash]
    while (_item != NULL)
    { 
        //сравниваем строки, ищем искомое слово в списке
        if (strcmp(_item->word,buffer) == 0)
            {
               return true;
            }
             _item = _item->next;
    }
           //(*item).next = value of next of object item
        return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    int index = 0;
    FILE* inptr = fopen(dictionary, "r");
    char buffer[LENGTH+1];
    if (inptr == NULL)
    {
        return false;
    }
    //читаем построчно файл
     while(fscanf(inptr, "%s\n", buffer) != EOF)
    {
        //считаем сколько скол в словаре
        size_dictionary++;
        
        unsigned int hash = hash_func(buffer);  
        index = 0;
		node* newnode = malloc(sizeof(node));
		
		//копирум строку из buffer в newnode->word
		strcpy(newnode->word, buffer);
		
		//если слова с кодом hash ещё не было
        if (array[hash] == NULL)
        {
            array[hash] = newnode; 
			newnode->next = NULL;
        }
        else
        {
            //Добавляем в начало списка
            newnode->next = array[hash];
			array[hash] = newnode;
        }
    }
	
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return size_dictionary;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    
    for(int i = 0;i< SIZE;i++)
    {
        if (array[i] != NULL)
        {
            while (array[i] != NULL)
            {
                node* cursor = array[i];
                array[i] = cursor->next;
                free(cursor);
            }
        }
    }    
        
    return true;    
}
//hash function
unsigned int hash_func(const char* word)
{
    unsigned int hash = 0;
	int n = 0;
	
	//перебираем элементы строки
    for (;*word;word++)
    {
       if(isalpha((unsigned char)*word))
	   {
			n = (unsigned char)*word- 'a' + 1;
	   }
	   else{
		   n = 27;
	   }
	   hash = ((hash << 3) + n);
    }   
	   
    return hash%SIZE;
}

