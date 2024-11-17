/*
** Read an array of ‘n’ integers from the user and do the following operations:
** Search for a specific element in the array.
** 
** 
** Sample Input/Output. 
**     Input:
**     > 5
**     > 17 42 16 18 39
**     > 18
**     Output: 
**     > Element Found  at position 4      
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
    int arsz = 0;
    scanf("%d", &arsz);

    int size = 0;
    char ch = getchar();
    char *sent = NULL;
    while((ch = getchar()) != '\n' && ch != EOF)
    {
        size++;
        sent = realloc(sent, size*sizeof(char));
        sent[size-1] = ch;
    }
    int val = 0;
    scanf("%d", &val);
    
    sent[size] = '\0';
    //printf("%s\n", sent);
    
    int sz = 0;
    int pos = 1;
    char *buffer = NULL;
    for(int i = 0; i<size; i++)
    {
        if((int)sent[i] != 32)
        {
            sz++;
            buffer = realloc(buffer, sz*sizeof(char));
            buffer[sz-1] = sent[i];
        }
        else
        {
            int check = atoi(buffer);
            //printf("%d\n",check);
            if(check == val)
            {
                printf("Element found at position %d", pos);
                return;
            }
            else
            {
                pos++;
                buffer = NULL;
                sz = 0;
            }
        }
    }
    int check = atoi(buffer);
    if(check == val)
    {
        printf("Element found at position %d", pos);
        return;
    }
    else
    {
        printf("Element not Found");
    }
}