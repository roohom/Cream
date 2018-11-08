//
// Created by rooho on 2018/11/8.
//
//计算第N个三角数
#include <stdio.h>

void calculateTriangularNumber(int n)
{
    int i,triangularNumber = 0;
    for (i = 0; i <= n; i++) {
        triangularNumber += i;
    }
    printf("Triangular Number %i is %i\n",i, triangularNumber);
}


int main(void)
{
    calculateTriangularNumber(10);
    calculateTriangularNumber(50);
    calculateTriangularNumber(100);
}