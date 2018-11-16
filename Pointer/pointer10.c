// pointer10.c
// Created by roohom on 2018/11/16.
// 2018/11/16 19:57


//从函数中返回指针

#include <stdio.h>

struct entry
{
    int value;
    struct entry *next;
};

struct entry *findEntry(struct entry *listPtr, int match)
{
    while(listPtr != (struct entry *)0)
    {
        if(listPtr->value == match)
        {
            return listPtr;
        }
        else
            listPtr = listPtr->next;
    }
    return (struct entry *)0;
}
int main(void)
{
    struct entry n1,n2,n3;
    struct entry *listPtr,*listStart = &n1;
    
    int search;
    n1.value = 100;
    n1.next = &n2;
    
    n2.value = 200;
    n2.next = &n3;
    
    n3.value = 300;
    n3.next = 0;
    
    printf("Enter value to locate:");
    scanf("%i",&search);
    
    listPtr = findEntry(listStart,search);
    
    if(listPtr != (struct entry *)0)
        printf("Found %i.\n",listPtr->value);
    else
        printf("Not Found.\n");
    
}