/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdint.h>

int main()
{
   uint8_t buffer[512];//char
   //typedef unsigned char byte;
   int n = 0;
   char title[8];
   FILE* outptr = NULL;
   //byte sign[] = {0xff,0xd8,0xff,0x0e};
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
       // if (buffer[0] == sign[0] && buffer[1]==sign[1] && buffer[2]==sign[2] && buffer[3]>>4==sign[3]) -Можно и так
        if (buffer[0] == 0xff && buffer[1]==0xd8 && buffer[2]==0xff && buffer[3]>>4==0x0e)
        {
            if (outptr!=NULL)
            {
                fclose(outptr);
            }
           
            sprintf(title,"%03d.jpg",n);
            n++;
            outptr = fopen(title, "a");
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
    
     // close outfile
    fclose(inptr);

    // that's all folks
    return 0;

}
