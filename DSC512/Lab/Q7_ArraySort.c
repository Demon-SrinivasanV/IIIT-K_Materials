/*
** Read an array of ‘n’ integers from the user and do the following operations:
** Sort the array in ascending order.
** Sort the array in descending order.
** 
** 
** Sample Input/Output
**     Input:
**     > 5
**     > 17 42 16 18 39
**     Output:
**     > 16 17 18 39 42
**     > 42 39 18 17 16
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swp(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void qSrt(int arr[], int lo, int hi)
{
    if(lo<hi)
    {
        int i = lo;
        int pivot = arr[hi];
        
        for(int j = lo; j<hi; j++)
            if(arr[j] < pivot)
            {
                swp(&arr[i], &arr[j]);
                i++;
            }
        swp(&arr[i], &arr[hi]);
        
        qSrt(arr, lo, i-1);
        qSrt(arr, i+1, hi);
    }
}

void main()
{
    int a;
    scanf("%d", &a);
    
    int *array = NULL;
    int az = 0;
    char *buffer = NULL;
    int bz = 0;
    
    char ch = getchar();
    while((ch = getchar()) != '\n' && ch != EOF)
    {
        if((int) ch == 32)
        {
            az++;
            array = realloc(array, sizeof(int));
            array[az-1] = atoi(buffer);
            bz = 0;
            buffer = NULL;
        }
        else
        {
            bz++;
            buffer = realloc(buffer, sizeof(char));
            buffer[bz-1] = ch;
        }
    }
    
    if(bz>0)
    {
        az++;
        array = realloc(array, sizeof(int));
        array[az-1] = atoi(buffer);
        bz = 0;
        buffer = NULL;
    }
    
    qSrt(array, 0, az-1);
    
    for(int i=0; i<az; i++)
        printf("%d ", array[i]);
    
    printf("\n");
    
    for(int i=az-1; i>=0; i--)
        printf("%d ", array[i]);
}