/*
** Create a Doubly linked list and Traverse it in forward and backward direction.
** 
** 
** Sample Input/Output
**     Input:
**     > 17 42 16 18 39 -999
**     Output:
**     > 17 42 16 18 39 
**     > 39 18 16 42 17  
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
    newNode->next = NULL;
    newNode->prev = NULL;
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
    else
    {
        struct Node* temp = *head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
        return;
    }
}

void printList(struct Node* head)
{
    if(head == NULL)
    {
        printf("Underflow");
        return;
    }
    struct Node* temp = head;
    struct Node* temp2 = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp2 = temp;
        temp = temp->next;
    }
    printf("\n");
    while(temp2 != NULL)
    {
        printf("%d ", temp2->data);
        temp2 = temp2->prev;
    }
    return;
}

void main()
{
    struct Node* head = NULL;
    char ch;
    char *buffer = NULL;
    int bz = 0;
    
    while((ch = getchar()) != '\n' && ch != EOF)
    {
        if((int) ch == 32)
        {
            bz = 0;
            int data = atoi(buffer);
            if(data==(-999))
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