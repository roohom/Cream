// pointer08.c
// Created by roohom on 2018/11/16.
// 2018/11/16 19:49

//test 函数实际上将i的值修改为了100

#include <stdio.h>

void test(int *int_pointer)
{
    *int_pointer = 100;
}

int main(void)
{
    int i = 50,*p = &i;

    printf("Before the call to test i = %i\n",i);

    test(p);

    printf("After the call to test i = %i\n",i);
}