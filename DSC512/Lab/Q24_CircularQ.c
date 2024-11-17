/*
** Write C program for array implementation of circular queue with maximum size of six.
** Remove three elements from the circular queue and display the queue.
** Display the value of FRONT and REAR.
** Add two elements into the circular queue and display the queue.
** Display the value of FRONT and REAR.
** 
** 
** Sample Input/Output
**     Input:
**     > 42 77 88 9 3 66 -999
**     Output:
**     > Circular Queue: 9 3 66
**     > FRONT = 3, REAR = 5
**     > Contents of the remaining queue: 9 3 66
**     Input:
**     > -89 -63
**     Output:
**     > 9 3 66 -89 -63
**     > FRONT = 3, REAR = 1
*/


#include<stdlib.h>
#include<stdio.h>

int queue[6];
int front = -1;
int rear = -1;

int isEmpty()
{
    return front == -1;
}

int isFull()
{
    return (rear + 1) % 6 == front;
}

int enqueue(int value)
{
    if(isFull())
    {
        printf("Out of bound\n");
        return 0;
    }
    
    if(isEmpty())
    {
        front = 0;
    }
    
    rear = (rear + 1) % 6;
    queue[rear] = value;
    return 1;
}

int dequeue()
{
    if(isEmpty())
    {
        printf("Queue is empty\n");
        return -999;
    }
    
    int value = queue[front];
    
    if(front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % 6;
    }
    
    return value;
}

void display()
{
    if(isEmpty())
    {
        printf("Empty Queue\n");
        return;
    }
    
    int i = front;
    while(1)
    {
        printf("%d ", queue[i]);
        if(i==rear)
            break;
        i = (++i) % 6;
    }
    printf("\n");
}

void main()
{
    char ch;
    int bz = 0;
    int count = 0;
    char *buffer = NULL;
    
    while((ch = getchar()) != '\n' && ch != EOF)
    {
        if((int) ch == 32)
        {
            bz = 0;
            int value = atoi(buffer);
            if(value == (-999))
                break;
            else
            {
                count++;
                if(!enqueue(value))
                    return;
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
    
    if(count == 0)
        printf("Empty Queue.");
    if(count < 3)
    {
        printf("Three elements should be deleted.");
        return;
    }
    
    dequeue();
    dequeue();
    dequeue();
    
    printf("Circular Queue: ");
    display();
    printf("FRONT = %d, REAR = %d", front, rear);
    printf("\nContents of the remaining queue: ");
    display();
    int one = 0;
    int two = 0;
    
    scanf("%d %d", &one, &two);
    enqueue(one);
    enqueue(two);
    
    display();
    printf("FRONT = %d, REAR = %d", front, rear);
}