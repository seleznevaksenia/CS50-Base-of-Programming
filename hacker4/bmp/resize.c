/**
 * copy.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdint.h>
#include <math.h>


#include "bmp.h"

int main(int argc, char* argv[])
{
    int padding_new;
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./copy infile outfile\n");
        return 1;
    }

    // remember filenames
    float n = atof(argv[1]);
    char* infile  = argv[2];
    char* outfile = argv[3];
    int step = (int)pow(n,-1);
    

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);//ошибка пр открытии файла
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf, bf1;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    bf1 = bf;

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi, bi1;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    bi1 = bi;
    
    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)// проверка сможем ли мы редактором откыть эту версию 
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE))% 4) % 4; 
    
    if (n > 1.0 || n < 1.0)
    {
        if(n > 1.0)
        {
        //structure of new image
            bi1.biWidth = bi.biWidth*(int)n; 
            bi1.biHeight = bi.biHeight*(int)n;
        }
        else
        {
            bi1.biWidth = bi.biWidth/step; 
            bi1.biHeight = bi.biHeight/step;    
        }
         // determine new padding for scanlines, 
        padding_new =  (4 - (bi1.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
        
        bi1.biSizeImage = (bi1.biWidth*sizeof(RGBTRIPLE) + padding_new)*abs(bi1.biHeight);
        bf1.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + bi1.biSizeImage;
        // write outfile's BITMAPFILEHEADER
        fwrite(&bf1, sizeof(BITMAPFILEHEADER), 1, outptr);
    
        // write outfile's BITMAPINFOHEADER
        fwrite(&bi1, sizeof(BITMAPINFOHEADER), 1, outptr);
    }
    else
    {
        // write outfile's new BITMAPFILEHEADER
        fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);
    
        // write outfile's  new BITMAPINFOHEADER
        fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);  
    }
    
    //Each row (aka "scanline") thus takes up (8 pixels) × (3 bytes per pixel) = 24 bytes, which happens to be a multiple of 4. It turns out that BMPs are stored a bit differently if the number of bytes in a scanline is not, in fact, a multiple of 4.

    // iterate over height
    
    if (n>=1.0)
    {
        for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
        {
        //repeat n times horizontaly
            for (int mn = 0; mn< n; mn++)
            {
            //iterate over infile's scanlines
                for (int j = 0; j < bi.biWidth; j++)
                {
                RGBTRIPLE triple;
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                
                //repeat n times vertically
                    for (int s = 0; s < n; s++)
                    {
                        fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                    }
             
                }    
        
                if (n > 1.0)
                {
                // add padding_new
                    for (int k = 0; k < padding_new; k++)
                    {
                        fputc(0x00, outptr);
                    }
                    
                    //return to begining of the line if it isn't last repeat
                    if (mn<n-1)
                    {
                        fseek(inptr, -bi.biWidth*sizeof(RGBTRIPLE), SEEK_CUR);
                    }
                }
            
                else
                {
            
                    for (int k = 0; k < padding; k++)
                    {
                        fputc(0x00, outptr);
                    }
                }
        }
        fseek(inptr, padding, SEEK_CUR);
        }
    }
    //
    else
    {
         for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i += step)
         {
             for (int j = 0; j < bi.biWidth; j += step)
            {
				RGBTRIPLE triple;
				fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
				fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
				
				//Вся фишка в этом передвижении курсора, продвигаем его пропрорционально уменьшению
				fseek(inptr,sizeof(RGBTRIPLE)*step-sizeof(RGBTRIPLE), SEEK_CUR);
            }
            for (int k = 0; k < padding_new; k++)
            {
                fputc(0x00, outptr);
            }
            fseek(inptr, padding, SEEK_CUR);
            for (int k = 0; k < step-1; k++)
            {
                //пропускаем step-1 строки в исходном файле(пропорционально уменьшению)
               fseek(inptr,(bi.biWidth)*sizeof(RGBTRIPLE)+padding, SEEK_CUR);
            }
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}