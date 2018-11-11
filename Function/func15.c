// func15.c
// Created by roohom on 2018/11/11.
// 2018/11/11 19:05

// 递归计算阶乘


#include <stdio.h>

int main(void)
{
    unsigned int j;
    unsigned long int factorial(unsigned int n);

    for (j = 0; j < 11; ++j) {
        printf("%2u! = %lu\n", j, factorial(j));
    }

}



unsigned long int factorial(unsigned int n)
{
    unsigned long int result;
    if(n == 0)
        result = 1;
    else
        result = n*factorial(n-1);

    return result;
}