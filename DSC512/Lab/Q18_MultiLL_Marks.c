/*
** Write a C program to read name and total marks of students in a batch.
** The program must sort student names in alphabetical order.
** The program must also sort student list based on descending order of marks. 
** You must use multi-linked lists with various links following descending ordered marks and alphabetically ordered records.
** If two students have same marks display them alphabetically.
** If two students have the same name display the details of the student with highest marks first.
** 
** Note: Marks cannot be negative. The name of a student only consists of capital and small English alphabets.
** 
** 
** Sample Input/Output
**     Input:
**     > James
**     > 56
**     > Paul
**     > 39
**     > Augustine
**     > 12
**     > William
**     > 85
**     > Kishan
**     > 35
**     > Rithi Sing
**     > 85
**     > Kishan
**     > 55
**     > -999    
**     Output:
**     > Descending order of Marks: Rithi Sing 85, William 85, James 56, Kishan 55, Paul 39, Kishan 35, Augustine 12,
**     > Alphabetical Order: Augustine 12, James 56, Kishan 55, Kishan 35, Paul 39, Rithi Sing 85, William 85,
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct Name
{
    char *name;
    struct Name* prev;
    struct Name* next;
    struct Mark* mark;
};

struct Mark
{
    int mark;
    struct Mark* prev;
    struct Mark* next;
    struct Name* name;
};

struct Name* mkName(char* name)
{
    struct Name* newName = (struct Name*) malloc(sizeof(struct Name));
    newName->name = strdup(name);
    newName->prev = NULL;
    newName->next = NULL;
    newName->mark = NULL;
}

struct Mark* mkMark(int mark)
{
    struct Mark* newMark = (struct Mark*) malloc(sizeof(struct Mark));
    newMark->mark = mark;
    newMark->prev = NULL;
    newMark->next = NULL;
    newMark->name = NULL;
}

void addStudent(struct Name** nameHead, struct Mark** markHead, char* name, int mark)
{
    struct Name* newName = mkName(name);
    struct Mark* newMark = mkMark(mark);
    newName->mark = newMark;
    newMark->name = newName;
    
    if(*nameHead == NULL && *markHead == NULL)
    {
        *nameHead = newName;
        *markHead = newMark;
        return;
    }
    
    struct Name* tempName = *nameHead;
    int flag = 0;
    while(tempName != NULL)
    {
        if(strcmp(tempName->name, newName->name) == 0)
        {
            flag = 1;
            if((tempName->mark->mark - newName->mark->mark) > 0)
            {
                if(tempName->next != NULL)
                {
                    newName->next = tempName->next;
                    newName->next->prev = newName;
                }
                
                tempName->next = newName;
                newName->prev = tempName;
                break;
            }
            else
            {
                if(tempName == *nameHead)
                {
                    newName->next = tempName;
                    tempName->prev = newName;
                    *nameHead = newName;
                    break;
                }
                tempName->prev->next = newName;
                newName->prev = tempName->prev;
                newName->next = tempName;
                tempName->prev = newName;
                break;
            }
        }
        else if(strcmp(tempName->name, newName->name) > 0)
        {
            flag = 1;
            if(tempName == *nameHead)
            {
                newName->next = tempName;
                tempName->prev = newName;
                *nameHead = newName;
                break;
            }
            tempName->prev->next = newName;
            newName->prev = tempName->prev;
            newName->next = tempName;
            tempName->prev = newName;
            break;
        }
        tempName = tempName->next;
    }
    
    if(flag == 0)
    {
        tempName = *nameHead;
        while(tempName->next != NULL)
            tempName = tempName->next;
        tempName->next = newName;
        newName->prev = tempName;
    }
    
    flag = 0;
    struct Mark* tempMark = *markHead;
    while(tempMark != NULL)
    {
        if((tempMark->mark - newMark->mark) == 0)
        {
            flag = 1;
            if(strcmp(tempMark->name->name, newMark->name->name) > 0)
            {
                if(tempMark == *markHead)
                {
                    newMark->next = tempMark;
                    tempMark->prev = newMark;
                    *markHead = newMark;
                    break;
                }
                
                newMark->prev = tempMark->prev;
                tempMark->prev->next = newMark;
                newMark->next = tempMark;
                tempMark->prev = newMark;
                break;
            }
            else
            {
                if(tempMark->next != NULL)
                {
                    newMark->next = tempMark->next;
                    tempMark->next->prev = newMark;
                }
                tempMark->next = newMark;
                newMark->prev = tempMark;
                break;
            }
        }
        else if((tempMark->mark - newMark->mark) < 0)
        {
            flag = 1;
            if(tempMark == *markHead)
            {
                newMark->next = tempMark;
                tempMark->prev = newMark;
                *markHead = newMark;
                break;
            }
            
            newMark->prev = tempMark->prev;
            tempMark->prev->next = newMark;
            newMark->next = tempMark;
            tempMark->prev = newMark;
            break;
        }
        tempMark = tempMark->next;
    }
    
    if(flag == 0)
    {
        tempMark = *markHead;
        while(tempMark->next != NULL)
            tempMark = tempMark->next;
        tempMark->next = newMark;
        newMark->prev = tempMark;
    }
    
    return;
}

void printName(struct Name* nameHead)
{
    printf("Alphabetical Order: ");
    struct Name* tempName = nameHead;
    while(tempName != NULL)
    {
        printf("%s %d", tempName->name, tempName->mark->mark);
        if(tempName->next != NULL)
            printf(", ");
        tempName = tempName->next;
    }
    printf("\n");
}

void printMark(struct Mark* markHead)
{
    printf("Descending order of Marks: ");
    struct Mark* tempMark = markHead;
    while(tempMark != NULL)
    {
        printf("%s %d", tempMark->name->name, tempMark->mark);
        if(tempMark->next != NULL)
            printf(", ");
        tempMark = tempMark->next;
    }
    printf("\n");
}

void main()
{
    struct Name* nameHead = NULL;
    struct Mark* markHead = NULL;
    
    char ch;
    int bz = 0;
    char *buffer = NULL;
    int flag1 = 0;
    
    while((ch = getchar()) != EOF)
    {
        if(ch == '\n')
        {
            if(strcmp(buffer, "-999") == 0)
                break;
            else
            {
                for(int i = 0; i<bz; i++)
                {
                    if(isdigit(buffer[i]) || buffer[i] == '.' || buffer[i] == '*')
                    {
                        printf("Input Error!!! Name of a student should only have alphabets.");
                        return;
                    }
                }
                bz = 0;
                char *intBuf = NULL;
                int iz = 0;
                while((ch = getchar()) != '\n' && ch != EOF)
                {
                    if(!isdigit(ch) && !(ch == '-'))
                    {
                        printf("Input Error!!! Marks Missing");
                        return;
                    }
                    iz++;
                    intBuf = realloc(intBuf, sizeof(char));
                    intBuf[iz-1] = ch;
                }
                int marks = atoi(intBuf);
                if(marks < 0)
                {
                    printf("Marks cannot be negative.");
                    return;
                }
                addStudent(&nameHead, &markHead, buffer, marks);
                flag1 = 1;
                intBuf = NULL;
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
    
    if(flag1 == 0)
    {
        printf("You must enter atleast one student.");
        return;
    }
    printMark(markHead);
    printName(nameHead);
}