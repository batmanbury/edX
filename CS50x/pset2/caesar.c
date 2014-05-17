/**
 * CS50x
 * Problem Set 2--Crypto
 * caesar.c
 * 
 * Matthew T. Banbury
 * matbanbury@gmail.com
 *
 * Takes one integer command line argument used as an
 * encryption key, then prompts the user for text to
 * encrypt/decrypt using Caesar's Cipher.
 */

#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

 
int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Error: Enter exactly 1 argument.\n");
        return 1;
    }
    
    // all positive keys modulate to a value 0-25
    int key = atoi(argv[1]) % 26;
    
    //printf("Enter plaintext to encrypt:\n");
    string text = GetString();
    
    // create iterable alphabetic arrays
    string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string lower = "abcdefghijklmnopqrstuvwxyz";

    // iterate over each char to encrypt/decrypt
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            if (isupper(text[i]))
            {
                // wrap around to 'a' if char + key > 26
                printf("%c", upper[(text[i] - 65 + key) % 26]);
            }
            else    // current char is lowercase
            {
                printf("%c", lower[(text[i] - 97 + key) % 26]);
            }
        }
        else
        {
            // non-alphabetic characters remain unchanged
            printf("%c", text[i]);
        }
    }
    printf("\n");
}
