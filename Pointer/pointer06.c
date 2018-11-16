// pointer06.c
// Created by roohom on 2018/11/16.
// 2018/11/16 16:42

// 使用链表

#include <stdio.h>

int main(void)
{
    struct entry
    {
        int value;
        struct entry *next;
        
    };
    
    struct entry n1,n2,n3;
    int i;
    
    n1.value = 100;
    n2.value = 200;
    n3.value = 300;
    
    n1.next = &n2;
    n2.next = &n3;
    
    i = n1.next->value;
    printf("%i  ", i);
    
    printf("%i\n",n2.next->value);
}