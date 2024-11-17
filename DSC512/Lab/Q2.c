/*
** Write a C program to read an integer from the user and check whether it is a palindrome or not.
** The program should output the number and say whether it is a palindrome or not.
** 
** After printing it, can you reverse the order of digits in the number the user has just entered.
** E.g. 1234 should become 4321. Display the result on the screen in an easily understandable format.
** 
** 
** Sample Input/Output
**     Input:
**     > 121
**     Output
**     > Palindrome
**     > 121
** 
**     Input
**     > 1143
**     Output
**     > Not Palindrome
**     > 3411
*/


#include<stdio.h>
#include<stdbool.h>

void main()
{
    int a = 0, b = 0;
    scanf("%d", &a);
    bool boo = false;
    if(a==0)
    {
        printf("Palindrome\n0");
        return;
    }
    if(a<0)
    {
        boo = true;
        a = a *(-1);
    }
    bool boo2 = false;
    if(a%10==0)
        boo2 = true;
    int inp = a;
    int x = a;
    int i;
    for(i=0; x>0; i++)
    {
        x = x/10;
    }
    
    while(a>0)
    {
        b = b*10 + a%10;
        a = a/10;
    }
    
    if (inp==b)
    {
        if (boo && boo2)
            printf("Palindrome\n-0%d", b);
        else if (boo)
            printf("Palindrome\n-%d", b);
        else if (boo2)
            printf("Palindrome\n0%d", b);
        else
            printf("Palindrome\n%d", b);
    }
    else if (boo && boo2)
        printf("Not Palindrome\n-0%d", b);
    else if (boo)
        printf("Not Palindrome\n-%d", b);
    else if (boo2)
        printf("Not Palindrome\n0%d", b);
    else
        printf("Not Palindrome\n%d", b);
}