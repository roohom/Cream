// case01.cpp
// Author:roohom<roohom@qq.com>
// Created by roohom on 2019/1/11.
// 2019/1/11 22:10


#include <stdio.h>
#include <stdlib.h>

/*关于指针何引用的区别*/

void swap1(int *a, int *b)     // 使用指针类型
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;

}

void swap2(int &a, int &b)     //使用引用类型
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void swap3(int a, int b)        //不使用引用类型
{
    int temp;
    temp = a;
    a = b;
    b = temp;

}

int main(){

    int x=1,y=2;
    int a=1,b=2;
    int c=1,d=2;
    swap1(&x, &y);             // 指针类型改变a，b的值
    printf("  使用指针类型调用swap函数之后a,b的值：");
    printf("%d-----%d\n",x,y);
    swap2(a, b);               // 引用类型改变a，b的值
    printf("  使用引用类型调用swap函数之后a,b的值：");
    printf("%d-----%d\n",x,y);
    swap3(a, b);               //不使用引用类型来改变ab的值
    printf("不使用引用类型调用swap函数之后a，b的值：");
    printf("%d-----%d\n",c,d);
}

// 写完了编译出错查阅资料才知道C语言中没有引用,C++中才有引用  手动狗头
/*Clion编译运行出现莫名错误：*/
//D:\Clion Projects\Cream\Point_learn\case01.c:9:16: error: expected ';', ',' or ')' before '&' token
// void swap1(int &a, int &b)     // 浣跨敤寮曠敤绫诲瀷
