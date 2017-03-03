#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])

{   //Проверяем ввёл ли пользователь два аргумента в командную строку
    if (argc!=2)
    {
        printf("INPUT!\n");
        return 1;
    }
    for (int i = 0;i < strlen(argv[1]);i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("INPUT!\n");
            return 1;
        }    
        else
        {
             argv[1][i] = tolower( argv[1][i]);    
        }
    }
    string plaintext = GetString();
    int l = strlen (plaintext);
    int i = 0,j = 0;
    int l_key = strlen (argv[1]);
   
    while (i<l)
    {
        if (isalpha(plaintext[i]) && isupper(plaintext[i]))
        {
            char ciphertext = (plaintext[i] -'A'+ argv[1][j%l_key]-'a')%26;
            printf ("%c", ciphertext+'A');
            i++;
            j++;
        } 
        else if (isalpha(plaintext[i]) && islower(plaintext[i]))
        {
            char ciphertext = (plaintext[i] -'a'+ argv[1][j%l_key]-'a')%26;
            printf ("%c", ciphertext+'a');
            i++;
            j++;
        } 
        
        else
        {
            printf ("%c",plaintext[i]);
            i++;
        }
        
    }
    printf("\n");
    return 0;
}     