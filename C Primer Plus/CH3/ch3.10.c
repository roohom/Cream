// ch3.10.c
// Created by roohom on 2018/12/31.
// 2018/12/31 2:10

#include <stdio.h>

int main(void)
{
    float salary;

    printf("\aEnter your desired monthly salary:\n");
    printf("$_____ \b\b\b\b\b\b\b");
    scanf("%f", &salary);
    printf("\n\t$%.2f a month is $%.2f a year.", salary, salary * 12.0);
    printf("\rGee!\n");


}