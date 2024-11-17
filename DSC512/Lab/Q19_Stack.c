/*
** Write a C program to implement stack data structure using linked lists.
** 
** Do the following operations:
** - PUSH a few elements into the stack. (Minimum 4 elements)
** - Do a PEEK operation.
** - Do three consecutive POP operations and display the elements.
** - Display the entire contents of the remaining Stack.
** 
** 
** Sample Input/Output
**     Input:
**     > 42 19 32 45 42 39 45 25 36 -999
**     Output:
**     > Peek: 36
**     > POP operations: 36 25 45
**     > Contents of the remaining Stack: 39 42 45 32 19 42
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stack
{
    int value;
    struct Stack* next;
};

struct Stack *mkStack(int value)
{
    struct Stack *newStack = (struct Stack *) malloc(sizeof(struct Stack));
    newStack->value = value;
    newStack->next = NULL;
    return newStack;
}

void push(struct Stack **head, int value)
{
    struct Stack *newStack = mkStack(value);
    
    if(*head == NULL)
    {
        *head = newStack;
        return;
    }
    
    newStack->next = *head;
    *head = newStack;
}

int pop(struct Stack **head)
{
    struct Stack *tempStack = *head;
    int value = tempStack->value;
    *head = tempStack->next;
    return value;
}

void main()
{
    char ch;
    int bz = 0;
    int count = 0;
    char *buffer = NULL;
    struct Stack *head = NULL;
    
    while((ch = getchar()) != '\n' && ch != EOF)
    {
        if((int) ch == 32)
        {
            int value = atoi(buffer);
            if(value == (-999))
                break;
            else
            {
                push(&head, value);
                count++;
            }
            bz = 0;
            buffer = NULL;
        }
        else
        {
            bz++;
            buffer = realloc(buffer, sizeof(int));
            buffer[bz-1] = ch;
        }
    }
    
    if(count<4)
    {
        printf("Minimum 4 elements must be entered.");
        return;
    }
    
    int fpop = pop(&head);
    int spop = pop(&head);
    int tpop = pop(&head);
    printf("Peek: %d\n", fpop);
    printf("POP operations: %d %d %d\n", fpop, spop, tpop);
    printf("Contents of the remaining Stack: ");
    while(head != NULL)
    {
        printf("%d ", pop(&head));
    }
    
    
}