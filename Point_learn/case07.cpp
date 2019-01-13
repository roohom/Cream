// case07.cpp
// Author:roohom<roohom@qq.com>
// Created by roohom on 2019/1/11.
// 2019/1/11 22:40

#include <stdio.h>
#include <stdlib.h>


void swap(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 3, b = 4;
    swap(a,b);
    printf("%d---%d",a,b);

}