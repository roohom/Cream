// func02.c
// Created by rooho on 2018/11/8.
// 2018/11/8 18:19

//函数 求两个非负整数的最大公约数
#include <stdio.h>
#include <stdlib.h>

void gcd(int m, int n){
    int temp;
    printf("The gcd of %i and %i is", m,n);
    while(n != 0){
        temp=m % n;
        m = n;
        n = temp;
    }
    printf("%i\n",m);
}



int main(void)
{
    int i,j;
    printf("Plz enter two number here:\n");
    scanf("%i %i\n", &i,&j);
    gcd(i,j);
    system("pause");
}