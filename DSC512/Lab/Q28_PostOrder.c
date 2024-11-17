/*
** Write a C program to read a binary tree from the user and perform Post-order Traversal.
** 
** 
** Sample Input/Output
**     Input:
**     > A  -999
**     > A B C -999     [Comment: A is the parent, B is the left child and C is the right child ]
**     > B D E -999
**     > C NULL F -999  [Comment: NULL is entered because C does not have a left child and F is the right child]
**     > D G H -999
**     > F I J -999
**     > H NULL L -999
**     > J K NULL -999
**     > -999
**     Output:
**     > Post-order Traversal: G, L, H, D, E, B, I, K, J, F, C, A
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
    char data;
    struct Node *l;
    struct Node *r;
};

struct Node* mkNode(char data)
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->r = NULL;
    newNode->l = NULL;
    return newNode;
}

struct Node* tracer(struct Node* head, char data)
{
    if(head == NULL)
        return NULL;
    
    if(head->data == data)
        return head;
    
    struct Node* lRes = tracer(head->l, data);
    if(lRes != NULL)
        return lRes;
    else
        return tracer(head->r, data);
}

void addNode(struct Node** head, char data, char l, char r)
{
    if(*head == NULL)
    {
        *head = mkNode(data);
        return;
    }
    
    struct Node* tempNode = *head;
    tempNode = tracer(tempNode, data);
    
    if(tempNode != NULL)
    {
        if(l != '\0')
        {
            struct Node* left = mkNode(l);
            tempNode->l = left;
        }
        if(r != '\0')
        {
            struct Node* right = mkNode(r);
            tempNode->r = right;
        }
    }
}

void postOT(struct Node* head)
{
    if(head == NULL)
        return;
    
    postOT(head->l);
    postOT(head->r);
    printf("%c ", head->data);
}

void main()
{
    char ch;
    
    char d = '\0';
    char l = '\0';
    char r = '\0';
    int df = 0;
    int lf = 0;
    int rf = 0;
    
    int bz = 0;
    int outerLoop = 1;
    char *buffer = NULL;
    struct Node* head = NULL;
    
    while((ch = getchar()) != EOF && outerLoop == 1)
    {
        if((int) ch == 45)
        {
            if(bz == 0)
                break;
            buffer[bz] = '\0';
            int i = 0;
            int loop = 1;
            int vz = 0;
            char *value = NULL;
            while(loop == 1)
            {
                if(buffer[i] == '\0')
                {
                    loop = 0;
                }
                else if((int) buffer[i] != 32)
                {
                    vz++;
                    value = realloc(value, sizeof(char));
                    value[vz-1] = buffer[i];
                }
                else
                {
                    char inf;
                    if(vz == 1)
                    {
                        inf = value[0];
                    }
                    else
                    {
                        inf = '\0';
                    }
                    
                    if(df == 0)
                    {
                        df = 1;
                        d = inf;
                    }
                    else if(lf == 0)
                    {
                        lf = 1;
                        l = inf;
                    }
                    else if(rf == 0)
                    {
                        rf = 1;
                        r = inf;
                    }
                    
                    vz = 0;
                    value = NULL;
                }
                i++;
            }
            
            if(df == 1)
            {
                addNode(&head, d, l, r);
                d = '\0';
                l = '\0';
                r = '\0';
                df = 0;
                lf = 0;
                rf = 0;
            }
            else
            {
                outerLoop = 0;
            }
            
            bz = 0;
            buffer = NULL;
        }
        else if(ch == '\n')
        {
            bz = 0;
            buffer = NULL;
            ch = '\0';
        }
        else
        {
            bz++;
            buffer = realloc(buffer, sizeof(char));
            buffer[bz-1] = ch;
        }
    }
    
    if(head == NULL)
    {
        printf("Empty Tree");
        return;
    }
    
    printf("\nPost-order Traversal: ");
    postOT(head);
}