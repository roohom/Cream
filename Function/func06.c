// func06.c
// Created by roohom on 2018/11/8.
// 2018/11/8 20:17

// 说明：
/* 程序func.05具有影藏的危害性，如果打包sqrt函数作调用
 * 当（如果）函数sqrt接收到一个复数参数时，牛顿—拉弗森过程将永不收敛，
 * 函数将会陷入死循环，而给附加运行的程序带来负担。
 * 解决办法，最好是让sqrt函数自己内部设定检查参数机制，让其自主检查参数的正负性，避免复数带来的隐患。*/

#include <stdio.h>

//重写sqrt函数：

float absNum(float x)
{
    if(x<0)
        x = -x;
    return x;
}


float sqrt(float x)
{
    float e = 0.000001;
    float guess = 1.0;
    //float absNum(float x);

    if(x < 0){
        printf("Negative argument to squareRoot.\n");
        return -1.0;
    }
    while(absNum(guess*guess-x)>=e){
        guess = (x/guess + guess) / 2.0;
    }
    return guess;
}

int main(void)
{
    printf("%.6f", sqrt(-25));
}