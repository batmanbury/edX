/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Matthew T. Banbury
 * matbanbury@gmail.com
 *
 * Recovers JPEGs from a specific raw SD
 * card file with 50 recoverable images
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef uint8_t BYTE;

int main(void)
{
    // open card file
    FILE* card = fopen("card.raw", "r");

    // initialize outfile and JPG file number
    FILE* newjpg = NULL;
    int number = 0;
    
    // known block size
    BYTE block[512] = {};

    for (;;) // infinite loop
    {
        for (int i = 0; i < 512; i++)
        {
            // if end of file is reached
            if (feof(card))
            {
                // close last JPG and card.raw
                fclose(newjpg);
                fclose(card);
                return 0;
            }
            // read one byte
            fread(&block[i], sizeof(BYTE), 1, card);
        }
        
        // check block for JPG signature
        if (block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && (block[3] == 0xe0 || block[3] == 0xe1))
        {
            if (newjpg != NULL)
            {
                fclose(newjpg);
            }
            
            // write new filename for each jpg starting with 000.jpg
            char filename[8];
            sprintf(filename, "%03d.jpg", number);
            number++;
            
            // open new file for writing
            newjpg = fopen(filename, "w");
            
            // write block to new file
            fwrite(&block[0], 512, 1, newjpg);
        }
        else if (number && newjpg != NULL) // JPGs already being written
        {
            // continue write
            fwrite(&block[0], 512, 1, newjpg);
        }
    }
}
