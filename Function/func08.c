// func08.c
// Created by roohom on 2018/11/9.
// 2018/11/9 21:34

//找出一个数组中的最小值

#include <stdlib.h>
#include <stdio.h>

int minimum(int values[],int numOfElements)
{
    int minValue, i;
    minValue = values[0];

    for (i = 1; i < numOfElements; i++) {
        if(values[i]<minValue)
            minValue = values[i];
    }
    return minValue;
}


int main(void)
{
    int array1[] = {157, -28, -37, 26, 10};
    int array2[] = {12, 45, 3, 10, 1, 3, 22};
    //int minimum(int values[], int numOfElements);

    printf("The minimum of array1 is %i\n", minimum(array1,5));  //取地址和不取地址结果一样，这是为社么？
    printf("The minimum of array2 is %i\n", minimum(array2,7));

}