/*
** Write a C program to read a string from the user and check whether the string is a pangram or not.
** A pangram is a sentence containing every letter in the English alphabet.
** If the sentence is not a pangram print the alphabets that are missing that will make the sentence a pangram.
** For example, the sentence, “The quick brown fox jumps over the lazy dog” is a pangram as it contains
** all the characters from ‘a’ to ‘z’. The sentence “The quick brown fox jumps over the dog”
** is not a pangram because the characters ‘a’, ‘l’, ‘z’ and ‘y’ are missing.
** 
** 
** Sample Input/Output
**     Input:
**     > The five boxing wizards jump quickly
**     Output: 
**     > Pangram
**     Input:
**     > bcdefghijklmnopqrstuvwxz.
**     Output:
**     > Not Pangram
**     > a y
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

void main()
{
    int alpha[26] = {0};
    int ch;
    
    while((ch = getchar()) != '\n' && ch != EOF)
    {
        if(ch>64 && ch<91)
            ch = ch + 32;
        if(ch>96 && ch<123)
            alpha[ch - 97] = 1;
    }
    
    bool boo = false;
    for(int i = 0; i<26; i++)
        if(alpha[i]==0)
            boo = true;
    
    if(boo)
        printf("Not Pangram\n");
    else
        printf("Pangram\n");
    
    for(int i = 0; i<26; i++)
        if(alpha[i]==0)
            printf("%c ", ((char) i + 97));
}