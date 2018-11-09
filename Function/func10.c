// func10.c
// Created by roohom on 2018/11/9.
// 2018/11/9 23:11

// 简单的交换排序算法

// 1.将i设定为i+1；
// 2.将j设定为i+1.
// 3.若a[i] > a[j],交换他们的值；
// 4.设定j为j+1.若j<n,则返回步骤3；
// 5.设定i为j+1。若i<n-1,则返回步骤2；
// 6.a现在被排列为递增顺序。

#include <stdio.h>
#include <stdlib.h>

void sort(int a[], int n)
{
    int i, j, temp;
    for (i = 0; i < n-1; ++i) {
        for (j = i+1; j < n; ++j) {
            if(a[i]>a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main(void)
{
    int i;
    int array[16] = {34,-5,6,0,12,100,56,22,44,-3,-9,12,17,22,6,11};

    printf("The array before the sort:\n");
    for (i = 0; i < 16; ++i) {
        printf("%i ",array[i]);
    }
    printf("\n");

    printf("The array after the sort:\n");
    sort(array, 16);
    for (i = 0; i < 16; ++i) {
        printf("%i ",array[i]);
    }
    printf("\n");
}