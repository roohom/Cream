// pointer05.c
// Created by roohom on 2018/11/16.
// 2018/11/16 16:37

//包含指针的结构体

#include <stdio.h>

int main(void)
{
    struct intPtrs
    {
        int *p1;
        int *p2;
    };

    struct intPtrs pointers;
    int i1 = 100,i2;

    pointers.p1 = &i1;
    pointers.p2 = &i2;
    *pointers.p2 = -97;

    printf("i1 = %i, *pointers.p1 = %i\n",i1,*pointers.p1);
    printf("i2 = %i, *pointers.p2 = %i\n",i2,*pointers.p2);
}