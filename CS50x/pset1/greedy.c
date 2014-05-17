/**
 * CS50x
 * Problem Set 1
 * greedy.c
 *
 * Matthew T. Banbury
 * matbanbury@gmail.com
 *
 * Prompts the user for the amount of change owed
 * and displays the number of coins that would be returned.
 * Uncomment the last line to see the number of each coin.
 */

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // coin values
    int q = 25;
    int d = 10;
    int n = 5;
    
    float change;
    
    // prompt user for a positive float
    do
    {
        printf("How much change is owed?\n");
        change = GetFloat();
    }
    while (change < 0);
    
    // cast change to manageable integer
    int c = round(change * 100);
    
    // for each coin type (q,d,n), get number of coins and
    // subtract their value from change owed
    int quarters = (c - (c % q))/q;
    c = c - quarters*q;
    
    int dimes = (c - (c % d))/d;
    c = c - dimes*d;
    
    int nickels = (c - (c % n))/n;
    c = c - nickels*n;
    
    // add each coin type together and display the total
    int coins = quarters + dimes + nickels + c;  //remaining value of c == pennies
    
    printf("%d\n", coins);
    
    // uncomment next line to display number of each coin
    //printf("%d quarters, %d dimes, %d nickels, %d pennies\n", quarters, dimes, nickels, c);
}
