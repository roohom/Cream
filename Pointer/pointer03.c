// pointer03.c
// Created by roohom on 2018/11/16.
// 2018/11/16 16:28

//在表达式中使用指针

#include <stdio.h>

int main(void)
{
    int i1,i2;
    int *p1,*p2;
    
    i1 = 5;
    p1 = &i1;
    i2 = *p1/2+10;
    p2 = p1;
    
    printf("i1 = %i, i2 = %i, *p1 = %i, *p2 = %i\n",i1,i2,*p1,*p2);
    
}