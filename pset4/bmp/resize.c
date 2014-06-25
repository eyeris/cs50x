/****************************************************************************
 * resize.c
 *
 * Computer Science 50
 * Problem Set 4
 *

 ***************************************************************************/
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: resize n infile outfile\n");
        return 1;
    }
    

    // remember filenames
    int n=atoi(argv[1]);
    char* infile = argv[2];
    char* outfile = argv[3];

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
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
	
		int oldWidth=bi.biWidth;
		int oldHeight=bi.biHeight;
		bi.biWidth*=n;
		bi.biHeight*=n;
		
		 // determine padding for scanlinn
    
        int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
        bi.biSizeImage=sizeof(RGBTRIPLE)*(bi.biWidth+padding)*abs(bi.biHeight);
        bf.bfSize=54+bi.biSizeImage;

    // write outfile's BITMAPFILEHEADER
   
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
 
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);
   
    
   
for(int l=0;l<n-1;n++)
{
    // iterate over infile's scanlines
    for (int i = 0, Height = abs(oldHeight); i < Height; i++)
    {
      
      for(int k=0;k<oldWidth;k++)
        {
          
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple frominfile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
           
                for(int j=0;j<n;j++)
                    {
                        // write RGB triple to outfile
                        fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                    }     
       } 
                // skip over padding, if any
                //fseek(inptr, patrdding, SEEK_CUR);

                // then add it back (to demonstrate how)
                for (int m = 0; m < padding; m++)
                fputc(0x00, outptr);        
                
     }
     fseek(inptr,3*oldWidth+padding,SEEK_SET) ;    
             
 }      

       

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
