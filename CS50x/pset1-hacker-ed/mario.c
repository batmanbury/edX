/**
 * mario.c
 * 
 * CS50x
 * Problem Set 1
 * "Hacker" Edition Challenge
 * 
 * Matthew T. Banbury
 * matbanbury@gmail.com
 *
 * Prompts the user for an int and displays two Mario
 * style half-pyramids with heights equal to that int.
 */

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // prompt for int from 0-23 inclusive
    int height;
    do
    {
        printf("Enter an int for pyramid height: ");
        height = GetInt();
    }
    while (height < 0 || height > 23);
    
    for (int i = 1; i <= height; i++)
    {
        // print 1st half spaces
        for (int s = 0; s < height - i; s++)
        {
            printf(" ");
        }
        
        // print 1st half steps
        for (int h = 0; h < i; h++)
        {
            printf("#");
        }
        
        // gap between half-pyramids
        printf("  ");
        
        // print 2nd half steps
        for (int h = 0; h < i; h++)
        {
            printf("#");
        }

        // next row
        printf("\n");
    }
}
