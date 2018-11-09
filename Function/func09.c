// func09.c
// Created by roohom on 2018/11/9.
// 2018/11/9 22:05


// 在函数中改变数组元素

#include <stdio.h>

void multiplyBy2(float array[], int n)
{
    int i;
    for (i = 0; i < n; i++) {
        array[i] *=2;
    }
}



int main(void)
{
    float floaVals[4] = {1.2f, -3.7f, 6.2f, 8.55f};
    int i;

    multiplyBy2(floaVals, 4);

    for (i = 0; i < 4 ; i++) {
        printf("%.2f ", floaVals[i]);
    }
    printf("\n");

}