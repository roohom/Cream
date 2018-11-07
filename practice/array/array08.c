//
// Created by roohom on 2018/11/7.
//
//字符数组的引用

#include <stdio.h>

int main(void)
{
    int i,j;
    char a[][5]={{'B','A','S','I','C'},{'d','B','A','S','E'}};
    for (i = 0; i <2 ; i++) {
        for (j = 0; j < 5; j++) {
            printf("%4c",a[i][j]);      //%4d打印ASCII值，%4c则打印中文字符
        }
        printf("\n");
    }
}
