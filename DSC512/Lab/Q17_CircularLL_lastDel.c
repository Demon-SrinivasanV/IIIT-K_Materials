/*
** Create a doubly linked circular list.
** Delete the last element in the doubly linked circular list.
** 
** 
** Sample Input/Output
**     Input
**     > 84 19 32 45 25 39 -999
**     Output
**     > 84 19 32 45 25
*/


#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* mkNode(int data)
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void addNode(struct Node** head, int data)
{
    struct Node* newNode = mkNode(data);
    
    if(*head == NULL)
    {
        *head = newNode;
        return;
    }
    
    struct Node* temp = *head;
    
    if(temp->prev == NULL)
    {
        temp->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = temp;
        return;
    }
    else
    {
        newNode->prev = temp->prev;
        newNode->next = temp;
        temp->prev->next = newNode;
        temp->prev = newNode;
    }
}

void printList(struct Node* head)
{
    if(head == NULL)
    {
        printf("Underflow !!! Empty Linked list.");
        return;
    }
    else if(head->next == NULL)
    {
        printf("Empty Linked List !!!");
        return;
    }
    struct Node* marker = head;
    struct Node* temp = head;
    
    while(temp->next != head)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void main()
{
    char ch;
    int bz = 0;
    char *buffer = NULL;
    struct Node* head = NULL;
    
    while((ch = getchar()) != '\n' && ch != EOF)
    {
        if((int) ch == 32)
        {
            bz = 0;
            int data = atoi(buffer);
            if(data == (-999))
                break;
            else
                addNode(&head, data);
            buffer = NULL;
        }
        else
        {
            bz++;
            buffer = realloc(buffer, sizeof(char));
            buffer[bz-1] = ch;
        }
    }
    
    printList(head);
}