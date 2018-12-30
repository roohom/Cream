// ch4.6.c
// Created by roohom on 2018/12/31.
// 2018/12/31 3:35

// 使用printf()

#include <stdio.h>
#define PI 3.1415926
int main(void)
{
    int number = 7;
    float  pies = 12.75;
    int cost = 7800;
    
    printf("The %d contestants are %f berry pise.\n",number,pies);
    printf("The value of pi is %f.\n", PI);
    printf("Farewell! thou art too dear for my possessing,\n");
    printf("%c%d\n", '$', 2*cost);
}