// ch3.5.c
// Created by roohom on 2018/12/27.
// 2018/12/27 11:28

//显示字符的编码符号

#include <stdio.h>

int main(void)
{
    char ch;
    printf("Please enter a character here:\n");
    scanf("%c", &ch);
    printf("The code for %c is %d.\n", ch, ch);
    
}