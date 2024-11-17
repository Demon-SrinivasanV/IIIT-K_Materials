/*
** Create a doubly linked circular list. 
** Delete the 3rd element in the doubly linked circular list.
** Display the elements of the resulting linked list in reverse order.
** 
** 
** Sample Input/Output
**     Input
**     > 84 19 32 45 25 39 -999    
**     Output
**     > 39 25 45 19 84
*/


#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
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
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void printList(struct Node* head)
{
    struct Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

void deleteThird(struct Node** head)
{
    struct Node* temp = *head;
    
    temp = temp->next->next;
    
    if(temp->next != NULL)
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    else
        temp->prev->next = NULL;
}

void main()
{
    int count = 0;
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
            {
                addNode(&head, data);
                count++;
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

    if(count<3)
    {
        printf("Underflow !!! Minimum 3 elements must be entered.");
        return;
    }
    
    deleteThird(&head);
    
    printList(head);
}