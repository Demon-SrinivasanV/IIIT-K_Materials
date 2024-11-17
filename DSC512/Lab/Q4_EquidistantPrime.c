/*
** Write a C program to generate prime numbers which has two equidistant prime numbers from it within a given range.
** For example, 5 is one such number because we have two prime numbers 3 and 7 both of which are equidistant from 5. The distance in this case would be 2.
** 
** Can you generate all such numbers in ascending order within a given range along with their corresponding two prime numbers and distance?
** 
** 
** Sample Input/Output
**     Input:
**     > 2 10
**     Output:
**     > 3 5 7 2
** 
**     Input:
**     > 0 30
**     Output:
**     > 11 17 23 6
**     > 17 23 29 6
*/


#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

void main()
{
    // Get Input.
    int x, y = 0;
    scanf("%d %d", &x, &y);
    
    int *num = NULL;
    num = realloc(num, (y+1)*sizeof(int));
    
    // Applying Modified Sieve of Eratosthenes.
    memset(num, 0, (y+1)*sizeof(int));
    
    // Setting digits [0] & [1] as not prime by default.
    num[0] = 1;
    num[1] = 1;
    
    int range = sqrt(y);
    for(int i = 2; i<range+1; i++)
        if(num[i]==0)
            for(int j = i; (i*j)<(y+1); j++)
                num[i*j] = 1;
    
    num[y+1] = '\0';
    
    // Ascertain the Prime Numbers from the Sieve Array.
    int *prm = NULL;
    int size = 0;
    for(int i = 0; i<y+1; i++)
        if(num[i]==0)
        {
            size++;
            prm = realloc(prm, (size+1)*sizeof(int));
            prm[size-1] = i;
        }
    
    // Checking the difference between of the Prime Array for Equidistant Primes.
    // WARNING: Current method not ideal, as it is basically brute forcing the Array.
    //          But no better method found. Skill Issue - Demon.
    for(int i = 0; i<(size-2); i++)
        if(prm[i]>=x)
            for(int j = i+1; j<(size-1); j++)
            {
                int diff = prm[j] - prm[i];
                for(int k = 0; k<size; k++)
                    if((prm[k]-prm[j])==diff)
                        printf("%d %d %d %d\n", prm[i], prm[j], prm[k], diff);
            }
    
    // Freeing allocated Arrays, likely best practices, to avoid memory leakages.
    // Need to understand the accurate reasoning as to why this is done.
    // But from what I have been seeing this is as a best practice. - Demon.
    free(num);
    free(prm);
    
    // PS: From my recent executions, the code does seem to run relatively fast.
    //     Likely due to the low-level nature of C Programming.
    //     Enabling incredibly efficient execution of programs. - Demon.
}