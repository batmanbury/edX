/**
 * CS50x
 * Problem Set 1
 * mario.c
 *
 * Matthew T. Banbury
 * matbanbury@gmail.com
 *
 * Prompts the user for an int and displays a Mario
 * style staircase with height equal to that integer.
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
        for (int s = 0; s < height - i; s++)
        {
            // print preceding spaces 
            printf(" ");
        }
        
        for (int h = 0; h <= i; h++)
        {
            // print proceeding stair steps
            printf("#");
        }
        
        printf("\n");
    }
}
