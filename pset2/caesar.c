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
    
    //
    int k = atoi(argv[1]);
    string plaintext = GetString();
    int l = strlen (plaintext);
    int i = 0;
   
    while (i<l)
    {
        if (isalpha(plaintext[i]) && isupper(plaintext[i]))
        {
            char ciphertext = (plaintext[i] -'A'+ k)%26;
            printf ("%c", ciphertext+'A');
            i++;
        } 
        else if (isalpha(plaintext[i]) && islower(plaintext[i]))
        {
            char ciphertext = (plaintext[i] -'a'+ k)%26;
            printf ("%c", ciphertext+'a');
            i++;
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