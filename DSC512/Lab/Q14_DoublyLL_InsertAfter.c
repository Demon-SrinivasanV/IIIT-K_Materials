/*
** Create a doubly linked list. Make sure one of the entered elements is 24.
** Insert a new element after the existing linked list element 24. If there are more than
** one occurrence of 24, give user the choice where the new element must be inserted.
** 
** 
** Sample Input/Output 
**     Input:
**     > 24 19 32 45 24 39 -999
**     > -56
**     Output:
**     > 2 occurrence of 24 found. Where should the insertion occur?
**     Input:
**     > 1
**     Output:
**     > 24 -56 19 32 45 24 39
*/


#include<stdlib.h>
#include<stdio.h>

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
    }
}

void printList(struct Node* head)
{
    struct Node* temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertAfter24(struct Node* head, int pos, int value)
{
    struct Node* temp = head;
    struct Node* newNode = mkNode(value);
    while(temp != NULL)
    {
        if(temp->data == 24)
            pos--;
        if(pos == 0)
        {
            struct Node* nextTemp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
            if(nextTemp != NULL)
            {
                nextTemp->prev = newNode;
                newNode->next = nextTemp;
            }
            return;
        }
        temp = temp->next;
    }
}

void main()
{
    char ch;
    int bz = 0;
    int z24 = 0;
    char *buffer = NULL;
    struct Node* head = NULL;

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
            if(data == 24)
                z24++;
            buffer = NULL;
        }
        else
        {
            bz++;
            buffer = realloc(buffer, sizeof(char));
            buffer[bz-1] = ch;
        }
    }
    
    int value;
    scanf("%d", &value);
    
    if(z24 == 0)
    {
        printf("At least one element must be 24.");
        return;
    }
    else if(z24 == 1)
        insertAfter24(head, 1, value);
    else
    {
        printf("%d occurrence of 24 found. Where should the insertion occur?\n", z24);
        scanf("%d", &z24);
        insertAfter24(head, z24, value);
    }
    
    printList(head);
    
}