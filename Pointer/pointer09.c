// pointer09.c
// Created by roohom on 2018/11/16.
// 2018/11/16 19:53


//用指针交换值

#include <stdio.h>

void exchange(int *const pint1, int *const pint2)
{
    int temp;

    temp = *pint1;
    *pint1 = *pint2;
    *pint2 = temp;
}

int main(void)
{
    int i1 = 05, i2 = 66, *p1 = &i1, *p2 = &i2;

    printf("i1 = %i, i2 = %i\n", i1,i2);

    exchange(p1,p2);
    printf("i1 = %i, i2 = %i\n", i1,i2);

    exchange(&i1,&i2);
    printf("i1 = %i, i2 = %i\n", i1,i2);
}