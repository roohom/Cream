// func07.c
// Created by roohom on 2018/11/9.
// 2018/11/9 20:22

// 找出一个数组中的最小值

#include <stdio.h>
#include <stdlib.h>

int minimum(int values[10])
{
    int minValue,i;
    minValue = values[0];

    for (i = 1; i < 10; i++) {
        if(values[i] < minValue)
            minValue = values[i];
    }
    return minValue;
}

int main(void)
{
    int scores[10],i, minScore;
    printf("ENTER 10 SCORES HERE:\n");

    for (i = 0; i < 10; i++) {
        scanf("%i", &scores[i]);
    }
    minScore = minimum(scores);
    printf("The minimum scores is : %i\n", minScore);

    return 0;
}