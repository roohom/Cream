// ch3.1.c
// Created by roohom on 2018/12/24.
// 2018/12/24 19:59

#include <stdio.h>
int main(void)
{
    float weight;
    float value;

    printf("Are you worth your weight in platinum?\n");
    printf("Let's check it out.\n");
    printf("Please enter your weight in pounds:");

    scanf("%f", &weight);
    value = 1700.0 *weight*14.5833;
    printf("Your weight in platinum is worth $%.2f.\n", value);
    printf("You are easily worth that! If platinum drop prices.\n");
    printf("Eat more to maintain your value.\n");

}