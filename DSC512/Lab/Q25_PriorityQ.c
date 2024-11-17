/*
** Write a C program to implement priority queue using sorted linked list. 
** Insert a minimum of five elements.  Display the priority queue.
** Remove two elements and display the queue.
** The input format is: Data followed by Priority value
** 
** 
** Sample Input/Output
**     Input:
**     > 25 9 85 6 -89 2 145 4 30 2 -999
**     Output:
**     > -89-->2, 30-->2, 145-->4, 85-->6, 25-->9
**     > After removing two elements: 145-->4 85-->6 25-->9
*/


#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int data;
    int prio;
    struct Queue* next;
    struct Queue* prev;
};

struct Queue* mkQueue(int data, int prio)
{
    struct Queue* newQueue = (struct Queue*) malloc(sizeof(struct Queue));
    newQueue->data = data;
    newQueue->prio = prio;
    newQueue->next = NULL;
    newQueue->prev = NULL;
    return newQueue;
}

void addQueue(struct Queue** head, int data, int prio)
{
    struct Queue* newQ = mkQueue(data, prio);
    
    if(*head == NULL)
    {
        *head = newQ;
        return;
    }
    
    struct Queue *tempQ = *head;
    
    int flag = 0;
    while(1)
    {
        if(tempQ->prio == newQ->prio)
        {
            flag = 1;
            if(tempQ->data > newQ->data)
            {
                if(tempQ->prev != NULL)
                {
                    newQ->prev = tempQ->prev;
                    tempQ->prev->next = newQ;
                }
                tempQ->prev = newQ;
                newQ->next = tempQ;
                break;
            }
            else
            {
                if(tempQ->next != NULL)
                {
                    tempQ->next->prev = newQ;
                    newQ->next = tempQ->next;
                }
                tempQ->next = newQ;
                newQ->prev = tempQ;
                break;
            }
        }
        else if(tempQ->prio > newQ->prio)
        {
            flag = 1;
            if(tempQ->prev != NULL)
            {
                newQ->prev = tempQ->prev;
                tempQ->prev->next = newQ;
            }
            
            newQ->next = tempQ;
            tempQ->prev = newQ;
            break;
        }
        if(tempQ->next == NULL)
            break;
        tempQ = tempQ->next;
    }
    if(flag == 0)
    {
        tempQ->next = newQ;
        newQ->prev = tempQ;
    }
    
    while(tempQ->prev != NULL)
        tempQ = tempQ->prev;
    
    *head = tempQ;
    
    return;
}

void display(struct Queue* head)
{
    struct Queue* tempQ = head;
    
    while(1)
    {
        printf("%d-->%d", tempQ->data, tempQ->prio);
        if(tempQ->next != NULL)
            printf(", ");
        else
            break;
        tempQ = tempQ->next;
    }
    printf("\n");
    return;
}

void main()
{
    char ch;
    int bz = 0;
    int data = 0;
    int flag = 0;
    int count = 0;
    char *buffer = NULL;
    struct Queue* head = NULL;
    
    while((ch = getchar()) != '\n')
    {
        if((int) ch == 32)
        {
            bz = 0;
            int value = atoi(buffer);
            if(value == (-999))
                break;
            if(flag == 0)
            {
                flag = 1;
                data = value;
                count++;
            }
            else
            {
                flag = 0;
                addQueue(&head, data, value);
                data = 0;
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
    
    if(count<10)
    {
        printf("Insert 5 elements");
        return;
    }
    display(head);
    printf("After removing two elements: ");
    *head = *head->next->next;
    display(head);
}