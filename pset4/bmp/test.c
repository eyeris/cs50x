for(int i=0;i<n;i++)
{
    for(int j=0:j<oldWidth;j++)
    {   fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
        for(int k=0;k<n;k++)
        {   
            fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
        }
    }
        // skip over padding, if any
                fseek(inptr, padding, SEEK_CUR);

                // then add it back (to demonstrate how)
                for (int m = 0; m < padding; m++)
                fputc(0x00, outptr);
    
}
