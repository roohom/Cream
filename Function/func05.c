// func05.c
// Created by roohom on 2018/11/8.
// 2018/11/8 19:32

// 计算一个数的平方根
//牛顿-拉弗森迭代法
//    算       法
// 0.程序由guess=1开始猜测平方根
// 1.将guess值设定为1
// 2.若|guess**2 - x| < e,执行步骤4
// 3.将（x/guess+guess）/2 的值赋给guess，再重新执行2.
// 4.guess的值就是所求平方根的值。

#include <stdio.h>

float absNum(float x){
    if(x<0)
        x = -x;
    return x;
}

float sqrt(int x)
{
    float guess = 1.0 , e = 0.000001;
    while(absNum(guess*guess - x) >= e)
    {
        guess = (x/guess + guess)/2;
    }
    return guess;
}

int main(void)
{
    float x;
    printf("Enter a number here to get it`s sqrt:\n");
    scanf("%f", &x);
    printf("Your number`s sqrt is equal to %f", sqrt(x));
}