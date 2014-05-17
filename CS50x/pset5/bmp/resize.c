/**
 * resize.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Original code by David Malan
 *
 * Problem Set completed by
 * Matthew T. Banbury
 * matbanbury@gmail.com
 *
 * Resizes a BMP by a factor of N.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./resize n infile outfile\n");
        return 1;
    }

    // remember resize factor
    int factor = atoi(argv[1]);
    if (factor < 1 || factor > 100)
    {
        printf("Usage: ./resize n infile outfile\n");
        return 1;
    }
    
    // remember filenames
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

    // remember old BITMAPINFOHEADER width and height
    int in_width = bi.biWidth;
    int in_height = bi.biHeight;

    // update BITMAPINFOHEADER width and height
    bi.biWidth = bi.biWidth * factor;
    bi.biHeight = bi.biHeight * factor;

    // determine padding for scanlines
    int newpadding = (4 - (bi.biWidth * sizeof (RGBTRIPLE)) % 4) % 4;
    int oldpadding = (4 - (in_width * sizeof (RGBTRIPLE)) % 4) % 4;

    // update BITMAPINFOHEADER image size and file size
    bi.biSizeImage = abs(bi.biHeight) * ((bi.biWidth * sizeof (RGBTRIPLE)) + newpadding);
    bf.bfSize = bi.biSizeImage + sizeof (BITMAPFILEHEADER) + sizeof (BITMAPINFOHEADER);

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    RGBTRIPLE scanline[bi.biWidth];
    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(in_height); i < biHeight; i++)
    {
        int pos = 0;
        // iterate over pixels in scanline
        for (int j = 0; j < in_width; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            for (int p = 0; p < factor; p++)
            {
                scanline[pos].rgbtRed = triple.rgbtRed;
                scanline[pos].rgbtBlue = triple.rgbtBlue;
                scanline[pos].rgbtGreen = triple.rgbtGreen;
                pos++;
            }
        } // end of scanline

        for (int k = 0; k < factor; k++)
        {
            // copy scanlines
            for (pos = 0; pos < bi.biWidth; pos++)
            {
                // write RGB triple to outfile
                fwrite(&scanline[pos], sizeof(RGBTRIPLE), 1, outptr);
            }

            // add padding to outfile
            for (int k = 0; k < newpadding; k++)
            {
                fputc(0x00, outptr);
            }
        }

        // skip over padding, if any
        fseek(inptr, oldpadding, SEEK_CUR);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
