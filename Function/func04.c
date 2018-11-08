// func04.c
// Created by roohom on 2018/11/8.
// 2018/11/8 19:09

//计算绝对值
#include <stdio.h>

float absNum(float a)
{
    if(a<0)
        a = -a;
    return a;
}



int main(void)
{
    float f1 = -15.5, f2 = 20.0, f3 = -5.0;
    int i1 = -716;
    float result;

    result = absNum(f1);
    printf("result = %.2f\n", result);
    printf("f1 = %.2f\n", f1);

    result = absNum(f2);
    printf("result = %.2f\n", result);
    printf("f2 = %.2f\n", result);

    result = absNum(f1) + absNum(f3);
    printf("result = %.2f\n", result);

    result = absNum((float)i1);
    printf("result = %.2f\n", result);

    result = absNum(i1);
    printf("result = %.2f\n", result);

    printf("%.2f\n", absNum(-6.0) / 4);
}
