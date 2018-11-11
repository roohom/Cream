// func14.c
// Created by roohom on 2018/11/11.
// 2018/11/11 17:08

//自动变量与静态变量

#include <stdio.h>

void auto_static(void)
{
    int autoVar = 1;
    static int staticVar = 1;
    printf("automatic = %i , static = %i\n", autoVar, staticVar);
    
    ++autoVar;                    // 自动变量， this value is never used
    ++staticVar;                  // 静态变量
}

int main(void)
{
    int i;
    for (i = 0; i < 5; i++) {
        auto_static();
    }
}