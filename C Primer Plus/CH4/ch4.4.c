// ch4.4.c
// Created by roohom on 2018/12/31.
// 2018/12/31 3:07

#include <stdio.h>
#define PI 3.1415926

int main(void)
{
    float area, circum, radius;

    printf("What is the radius of your pizza?\n");
    scanf("%f", &radius);
    area = PI*radius * radius;
    circum = 2* PI*radius;
    printf("Your basic pizza parameters are as flowers:\n");
    printf("circumference = %1.2f, area = %1.2f\n", circum, area);
}