/*
** Create a doubly linked list. Make sure one of the entered elements is 42.
** Delete an element before the existing linked list element 42. If there are more than one occurrence of 42, give user the choice where the new element must be deleted.
** 
** 
** Sample Input/Output 1
**     Input:
**     > 42 19 32 45 42 39 -999
**     Output:
**     > 2 occurrence of 42 found. Where should the deletion occur?
**     Input:
**     > 2
**     Output:
**     > 42 19 32 42 39
** 
** Sample Input/Output 2
**     Input:
**     > 42 19 32 45 42 39 -999
**     Output:
**     > 2 occurrence of 42 found. Where should the deletion occur?
**     Input:
**     > 1
**     Output:
**     > No element before 42
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
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
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

void removeBefore42(struct Node* head, int pos)
{
    struct Node* temp = head;
    while(temp != NULL)
    {
        if(temp->data == 42)
            pos--;
        if(pos == 0)
        {
            if(head == temp)
            {
                printf("No element before 42");
                return;
            }
            else
            {
                struct Node* prev = temp->prev;
                if(prev->prev == NULL)
                {
                    printList(temp);
                    return;
                }
                else
                {
                    prev->prev->next = temp;
                    temp->prev = prev->prev;
                    printList(head);
                    return;
                }
            }
        }
        temp = temp->next;
    }
}

void main()
{
    char ch;
    int bz = 0;
    int z42 = 0;
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
            if(data == 42)
                z42++;
            buffer = NULL;
        }
        else
        {
            bz++;
            buffer = realloc(buffer, sizeof(char));
            buffer[bz-1] = ch;
        }
    }

    if(z42 == 0)
    {
        printf("At least one element must be 42.");
        return;
    }
    else if(z42 == 1)
    {
        removeBefore42(head, z42);
    }
    else
    {
        printf("%d occurrence of 42 found. Where should the deletion occur?\n", z42);
        scanf("%d", &z42);
        removeBefore42(head, z42);
    }
}