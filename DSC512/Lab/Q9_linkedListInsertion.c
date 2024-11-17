/*
** Create a linked list and Insert an element after a particular element.
** If there are more than one similar elements in the linked list, add the element after the first occurrence.
** 
** 
** Sample Input/Output
**     Input:
**     > 17 42 16 18 39 -999
**     > 16 87
** Output
**     17 42 16 87 18 39   
*/


#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* mkNode(int data)
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
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
}

void printList(struct Node* head)
{
    struct Node* temp = head;
    if(temp != NULL)
        while(temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    else
        printf("Underflow");
    printf("\n");
}

int appendList(struct Node** head, int start, int insert)
{
    struct Node* temp = *head;
    if(temp != NULL)
        while(temp != NULL)
        {
            if(temp->data == start)
            {
                struct Node* insertNode = mkNode(insert);
                insertNode->next = temp->next;
                temp->next = insertNode;
                return 1;
            }
            temp = temp->next;
        }
    else
        printf("Not Found");
    printf("Not Found");
    return 0;
}


void main()
{
    struct Node* head = NULL;
    int data;
    
    char *buffer = NULL;
    int bz = 0;
    char ch;
    while((ch = getchar()) != '\n' && ch != EOF)
    {
        if((int) ch == 32)
        {
            bz = 0;
            data = atoi(buffer);
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
    
    int start = 0;
    int insert = 0;
    scanf("%d %d", &start, &insert);
    
    if(appendList(&head, start, insert) == 1)
        printList(head);
}