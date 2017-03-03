/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 * Variant with pointers
 *
 * Recovers JPEGs from a forensic image.
 */
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdint.h>

int main()
{
   uint8_t* buffer = malloc(512);//uint8_t* typedef like unsigned char byte;
   int n = 0;
   char title[8];//array for "%03d.jpg"
   FILE* outptr = NULL;
   
   
   FILE* inptr = fopen("card.raw", "r"); // TODO
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", "card.raw");
        return 2;
    }
    //проходим до конца файла
    while (fread(buffer,1,512, inptr)==512)
    {
         //смотрим первые 4 байта кластера
        if (*buffer == 0xff && *(buffer+1)==0xd8 && *(buffer+2)==0xff && *(buffer+3)>>4==0x0e)//*(buffer+3)>>4 -побитовій сдвиг вправо на 4 бита(0x0e -16-ричное число, размеров 8 бит)
        {
            if (outptr!=NULL)
            {
                fclose(outptr);
            }
           
            sprintf(title,"%03d.jpg",n);//Запись названия файла в массив
            
            n++;//счётчик для имени файла
            
            outptr = fopen(title, "a");//открываем файл для записи
        }
        if (outptr != NULL)
        {
            fwrite(buffer,1,512, outptr);
        }
        
    }
    if(outptr!=NULL)
    {
        fclose(outptr);
    }
     free(buffer);//освобождаем память в heap? выделенную под массив
    
     // close outfile
    fclose(inptr);

    // that's all folks
    return 0;

}
