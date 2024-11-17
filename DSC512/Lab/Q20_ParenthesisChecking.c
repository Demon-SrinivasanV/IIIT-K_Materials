/*
** Write a C program for parenthesis checking using linked list implementation of stack.
** 
** Sample Input/Output I
**     Input:
**     > [56 + 29 {a - b (m + n) * u} + 89]    
**     Output:
**     > Parenthesis Matched.
** 
** Sample Input/Output II
**     Input:
**     > [ p + q {m + 8 ] * c { -4 / b ) }    
**     Output:
**     > Parenthesis Mismatched.
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stack
{
    char value;
    struct Stack* next;
};

struct Stack* mkStack(char value)
{
    struct Stack* newStack = (struct Stack*) malloc(sizeof(struct Stack));
    newStack->value = value;
    newStack->next = NULL;
}

void push(struct Stack** head, char value)
{
    struct Stack* newStack = mkStack(value);
    
    if(*head == NULL)
    {
        *head = newStack;
        return;
    }
    
    newStack->next = *head;
    *head = newStack;
}

char pop(struct Stack **head)
{
    struct Stack *tempStack = *head;
    char value = tempStack->value;
    *head = tempStack->next;
    return value;
}

void main()
{
    char ch;
    int bz = 0;
    int flag = 0;
    char *buffer = NULL;
    struct Stack *head = NULL;
    
    while((ch = getchar()) != '\n' && ch != EOF)
    {
        if(ch == '[' || ch == '{' || ch == '(')
        {
            flag = 1;
            push(&head, ch);
        }
        else if(ch == ']' || ch == '}' || ch == ')')
        {
            if(head == NULL)
            {
                printf("Parenthesis Mismatched.");
                return;
            }
            flag = 1;
            char value = pop(&head);
            
            if(ch == ']' && value != '[')
            {
                printf("Parenthesis Mismatched.");
                return;
            }
            else if(ch == '}' && value != '{')
            {
                printf("Parenthesis Mismatched.");
                return;
            }
            else if(ch == ')' && value != '(')
            {
                printf("Parenthesis Mismatched.");
                return;
            }
        }
    }
    
    if(flag == 0)
    {
        printf("No Parenthesis found.");
        return;
    }
    else if(head != NULL)
    {
        printf("Parenthesis Mismatched.");
        return;
    }
    else
    {
        printf("Parenthesis Matched.");
        return;
    }
}