// pointer11.c
// Created by roohom on 2018/11/16.
// 2018/11/16 20:07


//使用指向数组的指针

#include <stdio.h>

int arraySum(int array[], const int n)
{
    int sum = 0,*ptr;
    int *const arrayEnd = array+n;

    for (ptr = array; ptr < arrayEnd; ++ptr) {
        sum +=*ptr;
    }
    return sum;
}

int main(void)
{
    int values[10] = {1,3,10,-2,3,6,8,9,-5};

    printf("The sum is %i.\n", arraySum(values,9));

}