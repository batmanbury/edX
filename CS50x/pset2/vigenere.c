/**
 * CS50x
 * Problem Set 2--Crypto
 * vigenere.c
 * 
 * Matthew T. Banbury
 * matbanbury@gmail.com
 *
 * Takes one keyword command line argument used as an
 * encryption key, then prompts the user for plaintext
 * to encrypt using Vigenere's Cipher, a more secure
 * variant of Caesar's Cipher.
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
    
    // check if cmd line argument is alphabetic
    for (int c = 0, l = strlen(argv[1]); c < l; c++)
    {
        if (isalpha(argv[1][c])==false)
        {
            printf("Error: enter an alphabetic key.\n");
            return 1;
        }
    }
    
    string key = argv[1];
    
    // get plaintexttext from user
    string text = GetString();
    
    // create iterable alphabetic arrays
    string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string lower = "abcdefghijklmnopqrstuvwxyz";
    
    // iterate over each user text char and 'key' chars
    for (int i = 0, n = strlen(text), c = 0, m = strlen(key); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            // find the index of current 'key' char in either
            // upper or lower array by creating pointers and
            // offsetting their values from the proper array
            int idx = 0;
            char find = key[c];
            const char* ptrU = strchr(upper, find);
            const char* ptrL = strchr(lower, find);
            
            if (ptrU)  // current char in 'key' is uppercase
            {
                idx = ptrU - upper;
            }
            else       // current char in 'key' is lowercase
            {
                idx = ptrL - lower;
            }
            
            if (isupper(text[i]))
            {
                printf("%c", upper[(text[i] - 65 + idx) % 26]);
                c = (c + 1) % m;  // resets to key[0] when necessary
            }
            else
            {
                // char is lowercase
                printf("%c", lower[(text[i] - 97 + idx) % 26]);
                c = (c + 1) % m;
            }
        }
        else
        {
            // non-alphabetic characters remain decrypted
            printf("%c", text[i]);
        }
    }
    printf("\n");
}
