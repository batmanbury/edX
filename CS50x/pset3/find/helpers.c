/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
//#include <stdio.h>
#include "helpers.h"

/**
 * Binary search returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // declare start, end, and mid points
    int first = 0;
    int last = n - 1;
    int middle = (first+last)/2;

    // loop while numbers between first and last
    while (first <= last)
    {
        if (values[middle] < value)
        {
            // discard lower half
            first = middle + 1;
        }
        else if (values[middle] > value)
        {
            // discard upper half
            last = middle - 1;
        }
        else if (values[middle] == value) 
        {
            // value found
            return true;
        }
        // new mid point
        middle = (first + last)/2;
    }
    return false;
}

/**
 * Sorts array of n values using insertion sort
 */
void sort(int values[], int n)
{
    int i, temp;
    
    for (int e = 1; e <= n - 1; e++)
    {
        i = e;
        while (i > 0 && values[i] < values[i-1])
        {
            temp = values[i];
            values[i] = values[i-1];
            values[i-1] = temp;
            i--;
        }
    }
    
    // uncomment to print the sorted haystack
    //for(int p = 0; p <= n - 1; p++)
    //{
    //    printf("%d\n", values[p]);
    //}
}
