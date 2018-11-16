// pointer12.c
// Created by roohom on 2018/11/16.
// 2018/11/16 20:48

//求一个整数数组中的各元素之和

#include <stdio.h>

int arraySum(int *array,int n)
{
    int sum = 0;
    int *const arrayEnd = array +n;

    for (; array < arrayEnd; ++array) {
        sum += *array;
    }
    return sum;
}

int main(void)
{
    int values[10] = {3,7,-9,3,6,-1,7,9,1,-5};

    printf("The sum is %i.\n",arraySum(values,10));

}
