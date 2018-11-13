// str01.c
// Created by roohom on 2018/11/13.
// 2018/11/13 18:01

//连接两个字符串

#include <stdio.h>
void concat(char result[], const char str1[],int i, const char str2[],int j);

int main(void)
{
    const char str1[5] = {'T','e','s','t',' '};
    const char str2[6] = {'W','o','r','k','s','.'};
    char s3[11];
    int i;

    //定义的函数，用来连接两个字符串
    concat(s3,str1,5,str2,6);


    for (i = 0; i <11 ; ++i) {
        printf("%c",s3[i]);
    }
    printf("\n");
}


void concat(char result[], const char str1[],int i, const char str2[],int j)
{
    int m,n;
    for(m=0;m<i;++m){
        result[m] = str1[m];
    }

    for(n=0;n<j;++n)
    {
        result[i+n] = str2[n];
    }
}










