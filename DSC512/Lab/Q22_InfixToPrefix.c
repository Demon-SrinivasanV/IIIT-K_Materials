/*
** Write a C program to convert Infix expression to Prefix expression using linked list implementation of stacks.
** 
** 
** Sample Input/Output I
**     Input:
**     > A - (B / C + (D % E * F) / G) * H   
**     Output
**     > - A * + / B C / % D * E F G H
** 
** Sample Input/Output II
**     Input:
**     > ( A + B * ( C - D ) ) / E   
**     Output:
**     > / + A * B - C D E
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stack
{
    char value;
    struct Stack *next;
};

struct Stack *mkStack(char value)
{
    struct Stack *newStack = (struct Stack*) malloc(sizeof(struct Stack));
    newStack->value = value;
    newStack->next = NULL;
    return newStack;
}

void push(struct Stack **head, char value)
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

char pop(struct Stack **head)
{
    struct Stack *tempStack = *head;
    char value = tempStack->value;
    *head = tempStack->next;
    return value;
}

char peek(struct Stack *head)
{
    struct Stack *tempStack = head;
    return tempStack->value;
}

void main()
{
    char ch;
    int bz = 0;
    int pz = 0;
    int flag = 0;
    struct Stack *head = NULL;
    char *buffer = malloc(sizeof(char) * 40);
    char *prefix = malloc(sizeof(char) * 40);
    
    while((ch = getchar()) != '\n' && ch != EOF)
    {
        if((int) ch == 32)
        {
            continue;
        }
        else
        {
            bz++;
            buffer[bz-1] = ch;
        }
    }
    buffer[bz] = '\0';
    
    if(bz < 1)
    {
        printf("No Input detected");
        return;
    }
    
    while(bz > 0)
    {
        char value = buffer[bz-1];
        if(value == '-' || value == '+' || value == '*' || value == '/' || value == '%' || value == '(' || value == ')')
        {
            if(head == NULL || value == ')')
            {
                push(&head, value);
                bz--;
                continue;
            }
            else if(value == '-' || value == '+')
            {
                char op = peek(head);
                if(op == ')')
                {
                    push(&head, value);
                    bz--;
                    continue;
                }
                else
                {
                    while((op = peek(head)) == '/' || op == '*' || op == '%' || op == '-' || op == '+')
                    {
                        op = pop(&head);
                        pz++;
                        prefix[pz-1] = op;
                        pz++;
                        prefix[pz-1] = ' ';
                        if(head == NULL)
                            break;
                    }
                    push(&head, value);
                    bz--;
                    continue;
                }
            }
            else if(value == '/' || value == '*' || value == '%')
            {
                char op = peek(head);
                if(op == '+' || op == '-' || op == ')')
                {
                    push(&head, value);
                    bz--;
                    continue;
                }
                else
                {
                    while((op = peek(head)) == '/' || op == '*' || op == '%')
                    {
                        op = pop (&head);
                        pz++;
                        prefix[pz-1] = op;
                        pz++;
                        prefix[pz-1] = ' ';
                        if(head == NULL)
                            break;
                    }
                    push(&head, value);
                    bz--;
                    continue;
                }
            }
            else if(value == '(')
            {
                char op;
                while((op = pop(&head)) != ')')
                {
                    pz++;
                    prefix[pz-1] = op;
                    pz++;
                    prefix[pz-1] = ' ';
                }
                bz--;
                continue;
            }
        }
        else
        {
            pz++;
            prefix[pz-1] = value;
            pz++;
            prefix[pz-1] = ' ';
            bz--;
            continue;
        }
    }
    
    while(head != NULL)
    {
        pz++;
        prefix[pz-1] = pop(&head);
        pz++;
        prefix[pz-1] = ' ';
    }
    prefix[pz] = '\0';
    
    if(pz < 1)
    {
        printf("Invalid input.");
        return;
    }
    while(pz > 0)
    {
        printf("%c", prefix[pz-1]);
        pz--;
    }
}