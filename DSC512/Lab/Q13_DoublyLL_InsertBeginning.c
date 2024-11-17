/*
** Create a doubly linked list. 
** Delete 3 elements from the end of the linked list. Display the elements of the resulting doubly linked list in reverse order.
** 
** 
** Sample Input/Output
**     Input:
**     > 84 19 32 45 25 39 -999    
**     Output:
**     > 32 19 84
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
    if(head == NULL)
    {
        printf("NULL");
        return;
    }
    struct Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
}

int remove3(struct Node** head)
{
    struct Node* temp = *head;
    while(temp->next != NULL)
        temp = temp->next;
    
    int i = 3;
    while(i>0)
    {
        if(temp->prev != NULL)
            temp = temp->prev;
        else
            return 0;
        i--;
    }
    if(temp->prev == NULL)
    {
        printf("NULL");
        return 0;
    }
    temp->next = NULL;
    return 1;
}

void main()
{
    char ch;
    char *buffer = NULL;
    int bz = 0;
    int az = 0;
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
            {
                addNode(&head, data);
                az++;
            }
            buffer = NULL;
        }
        else
        {
            bz++;
            buffer = realloc(buffer, sizeof(char));
            buffer[bz-1] = ch;
        }
    }
    
    if(az<3)
        printf("Error!! Underflow, Minimum 3 elements are required.");
    else if(remove3(&head) == 1)
        printList(head);
    else
        printf("NULL");
}