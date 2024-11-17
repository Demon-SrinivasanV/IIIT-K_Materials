/*
** Read an array of ‘n’ integers from the user and do the following operations:
** Delete an element from the array.
** 
** 
** Sample Input/Output
**     Input:
**     > 5
**     > 17 42 16 18 39
**     > 3
**     Output:
**     > 17 42 18 39
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
    int a;
    scanf("%d", &a);
    
    char *buffer = NULL;
    int *array = NULL;
    int az = 0;
    int sz = 0;
    char ch = getchar();
    while((ch = getchar()) != '\n' && ch != EOF)
    {
        if((int)ch == 32)
        {
            az++;
            array = realloc(array, az*sizeof(int));
            array[az-1] = atoi(buffer);
            buffer = NULL;
            sz = 0;
        }
        else
        {
            sz++;
            buffer = realloc(buffer, sz*sizeof(char));
            buffer[sz-1] = ch;
        }
    }
    
    if(sz>0)
    {
        az++;
        array = realloc(array, az*sizeof(int));
        array[az-1] = atoi(buffer);
        buffer = NULL;
        sz = 0;
    }

    int x;
    scanf("%d", &x);
    
    for(int i = 0; i<az; i++)
        if(i+1!=x)
            printf("%d ", array[i]);
}