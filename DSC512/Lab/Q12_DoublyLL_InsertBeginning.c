/*
** Create a doubly linked list. 
** Add 3 elements at the beginning of the linked list. Display the elements of the resulting doubly linked list in reverse order.
** 
** 
** Sample Input/Output
**     Input:
**     > 84 19 32 45 25 39 -999
**     > -5 -12 -68
**     Output:
**     > 39 25 45 32 19 84 -5 -12 -68
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

void addNodeFront(struct Node** head, int data)
{
    if(*head == NULL)
    {
        struct Node* newNode = mkNode(data);
        *head = newNode;
        return;
    }
    else
    {
        struct Node* newNode = mkNode(data);
        struct Node* temp = *head;
        
        temp->prev = newNode;
        newNode->next = temp;
        *head = newNode;
        return;
    }
}

void printList(struct Node* head)
{
    if(head == NULL)
        printf("Underflow");
    
    struct Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
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
    
    bz = 0;
    buffer = NULL;
    int az = 0;
    
    while((ch = getchar()) != '\n' && ch != EOF)
    {
        if((int) ch == 32)
        {
            bz = 0;
            int data = atoi(buffer);
            if(data==(-999))
                break;
            else
                addNodeFront(&head, data);
            buffer = NULL;
            az++;
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
        bz = 0;
        int data = atoi(buffer);
        if(data!=(-999))
            addNodeFront(&head, data);
        buffer = NULL;
        az++;
    }
    
    if(az<3)
    {
        printf("Error!! Three elements must be inserted.");
        return;
    }

    printList(head);
}