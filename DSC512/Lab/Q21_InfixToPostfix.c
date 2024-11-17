/*
** Write a C program to convert Infix expression to Postfix expression using linked list implementation of stacks.
** 
** 
** Sample Input/Output I
**     Input:
**     A - (B / C + (D % E * F) / G) * H   
**     Output:
**     A B C / D E % F * G / + H * -
** 
** Sample Input/Output II
**     Input:
**     ( A + B * ( C - D ) ) / E   
**     Output:
**     A B C D - * + E /
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
};

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
    int flag = 0;
    char *buffer = malloc(40 * sizeof(char));
    struct Stack *head = NULL;
    
    while((ch = getchar()) != '\n')
        if((int) ch != 32)
        {
            flag = 1;
            if(ch == '-' || ch == '+' || ch == '/' || ch == '*' || ch == '%' || ch == '(' || ch == ')')
            {
                if(head == NULL || ch == '(')
                {
                    push(&head, ch);
                    continue;
                }
                else if(ch == '-' || ch == '+')
                {
                    char op = peek(head);
                    if(op == '(')
                    {
                        push(&head, ch);
                        continue;
                    }
                    else
                    {
                        while((op = peek(head)) == '/' || op == '*' || op == '%' || op == '-' || op == '+')
                        {
                            op = pop(&head);
                            bz++;
                            buffer[bz-1] = op;
                            bz++;
                            buffer[bz-1] = ' ';
                        }
                        push(&head, ch);
                        continue;
                    }
                }
                else if(ch == '/' || ch == '*' || ch == '%')
                {
                    char op = peek(head);
                    if(op == '+' || op == '-' || ch == '(')
                    {
                        push(&head, ch);
                        continue;
                    }
                    else
                    {
                        while((op = peek(head)) == '/' || op == '*' || op == '%')
                        {
                            op = pop(&head);
                            bz++;
                            buffer[bz-1] = op;
                            bz++;
                            buffer[bz-1] = ' ';
                        }
                        push(&head, ch);
                        continue;
                    }
                }
                else if(ch == ')')
                {
                    char op;
                    while((op = pop(&head)) != '(')
                    {
                        bz++;
                        buffer[bz-1] = op;
                        bz++;
                        buffer[bz-1] = ' ';
                    }
                    continue;
                }
            }
            else
            {
                bz++;
                buffer[bz-1] = ch;
                bz++;
                buffer[bz-1] = ' ';
                continue;
            }
        }
    
    while(head != NULL)
    {
        bz++;
        buffer[bz-1] = pop(&head);
        bz++;
        buffer[bz-1] = ' ';
    }
    buffer[bz] = '\0';
    
    if(flag == 0)
    {
        printf("No Input detected");
        return;
    }
    if(bz == 0)
    {
        printf("Invalid input.");
        return;
    }
    printf("%s", buffer);
    
}