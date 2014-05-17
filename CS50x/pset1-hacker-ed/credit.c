/**
 * credit.c
 * 
 * CS50x
 * Problem Set 1
 * "Hacker" Edition Challenge
 * 
 * Matthew T. Banbury
 * matbanbury@gmail.com
 *
 * A credit card number validation tool that prompts
 * the user for a credit card number and returns the
 * type of card, either MASTERCARD, AMEX, VISA, or
 * INVALID otherwise.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>

// prototypes
bool valid(long long int num);
int doubleDigs(long long int num);

int main(void)
{
    // prompt user for credit card number (assumed numeric)
    printf("Number: ");
    long long int cc = GetLongLong();
    
    // check number validity (should be 13-16 digits)
    if (cc < 1000000000000 || cc > 9999999999999999)
    {
        printf("INVALID\n");
        return 0;
    }
    
    // cast cc number to string for ease of validation checks
    char strcc[17];
    snprintf(strcc, 17, "%lli", cc);
    
    // check number validity (should NOT be 14 digits)
    if (strlen(strcc) == 14)
    {
        printf("INVALID\n");
        return 0;
    }

    // check for type VISA
    if ((strlen(strcc) == 16 || strlen(strcc) == 13) && strcc[0] == '4')
    {
        if (valid(cc))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    // check for type AMERICAN EXPRESS
    else if (strlen(strcc) == 15 && strcc[0] == '3' &&
            (strcc[1] == '4' || strcc[1] == '7'))
    {
        if (valid(cc))
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    // check for type MASTERCARD
    else if (strlen(strcc) == 16 && strcc[0] == '5' &&
            (strcc[1] == '1' || strcc[1] == '2' ||
             strcc[1] == '3' || strcc[1] == '4' ||
             strcc[1] == '5'))
    {
        if (valid(cc))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    // credit card number somehow escaped validation
    else
    {
        printf("INVALID\n");
    }
    return 0;
}

/**
 * doubleDigs() is part of valid(). It takes the card
 * number as input, multiplies each by 2, and adds them
 * together. If a product is higher than 10, those digits
 * are added together instead.
 */
int doubleDigs(long long int num)
{
    int total = 0;
    
    // cast num to string
    char strcc[17];
    snprintf(strcc, 17, "%lli", num);
    
    // iterate over each other digit, starting from the right
    for (long long int n = num/10; n > 0; n/=100)
    {
        int product = (n % 10) * 2;
        if (product >= 10)
        {
            int digit1 = product / 10;
            int digit2 = product % 10;
            total += digit1 + digit2;
        }
        else
        {
            total += product;
        }
    }

    // iterate over previously not visited digits starting at the right
    for (long long int n = num; n > 0; n/=100)
    {
        total += n % 10;
    }
    
    return total;
}

/**
 * Hans Peter Luhn's credit card validation algorithm
 * Original recreation from CS50x instructional pseudocode
 *
 * returns true if card number is valid
 */
bool valid(long long int num)
{
    int checksum = doubleDigs(num);
    
    // return true if last digit of checksum is zero
    if (checksum % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * testable credit card numbers
 *
 * AMEX ......... 378282246310005
 * AMEX ......... 371449635398431
 * VISA ......... 4111111111111111
 * VISA ......... 4012888888881881
 * MASTERCARD ... 5555555555554444
 * MASTERCARD ... 5105105105105100
 */
