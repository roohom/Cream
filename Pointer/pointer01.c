// pointer01.c
// Created by roohom on 2018/11/16.
// 2018/11/16 16:20

//指针的演示

#include <stdio.h>


int main(void)
{
    int count = 10,x;
    int *int_pointer;

    int_pointer = &count;
    x = *int_pointer;

    printf("count = %i,x = %i\n", count,x);
}