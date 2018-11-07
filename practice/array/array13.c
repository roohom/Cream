//
// Created by roohom on 2018/11/7.
//

//字符串的连接
#include <stdio.h>
#include <string.h>

int main(void)
{
    static char st1[30]="My name is ";
    int st2[10];
    printf("Enter your name:\n");
    gets(st2);
    strcat(st1,st2);      //字符串连接
    puts(st1);
}
