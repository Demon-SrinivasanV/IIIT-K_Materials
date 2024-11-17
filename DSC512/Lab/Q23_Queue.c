/*
** Write a C program to implement Queue data structure using linked lists.
** 
** Do the following operations:
** - Insert few elements into the queue. (Minimum 4 elements)
** - Display the element at the front of the queue (Do not remove it from the Queue).
** - Remove and display three elements from the Queue.
** - Display the entire contents of the remaining Queue.
** 
** 
** Sample Input/Output
**     Input:
**     > 42 77 88 9 3 66 -999
**     Output:
**     > Element at the front of the queue: 42
**     > Remove and display three elements: 42 77 88
**     > Contents of the remaining queue: 9 3 66
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* mkNode(int data)
{
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addNode(struct Node **head, int data)
{
    struct Node *newNode = mkNode(data);
    
    if(*head == NULL)
    {
        *head = newNode;
        return;
    }
    
    struct Node *tempNode = *head;
    while(tempNode->next != NULL)
        tempNode = tempNode->next;
    
    tempNode->next = newNode;
    return;
}

void main()
{
    char ch;
    int bz = 0;
    int count = 0;
    char *buffer = NULL;
    struct Node *head = NULL;
    
    while((ch = getchar()) != '\n' && ch != EOF)
    {
        if((int) ch == 32)
        {
            bz = 0;
            int data = atoi(buffer);
            if(data == -999)
                break;
            else
                addNode(&head, data);
            buffer = NULL;
            count++;
        }
        else
        {
            bz++;
            buffer = realloc(buffer, sizeof(char));
            buffer[bz-1] = ch;
        }
    }
    
    if(count<4)
    {
        printf("Minimum 4 elements must be entered.");
        return;
    }
    int first = head->data;
    head = head->next;
    printf("Element at the front of the queue: %d\n", first);
    printf("Remove and display three elements: %d ", first);
    
    struct Node *tempNode = head;
    int i = 2;
    while(tempNode != NULL)
    {
        if(i <= 0)
            break;
        printf("%d ", tempNode->data);
        tempNode = tempNode->next;
        i--;
    }
    
    printf("\nContents of the remaining queue: ");
    while(tempNode != NULL)
    {
        printf("%d ", tempNode->data);
        tempNode = tempNode->next;
    }
    
}