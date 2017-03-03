#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main()
{
    string  full_name = GetString(); 
    int size = strlen(full_name), i=0;
    while (i<size)
    {
        while (isspace(full_name[i]))
        {
            if (i == size)
			{
				break;
			}
			 i++;
        }
        if (i < size)
        {
            printf ("%c",toupper(full_name[i]));
        }
        while (full_name[i] != ' ')
        {
			if (i == size)
			{
				break;
			}
			i++;
        }
    }
    printf ("\n");
    return 0;
}     