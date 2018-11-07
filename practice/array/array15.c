//
// Created by roohom on 2018/11/7.
//

//字符串的比较
#include <stdio.h>
#include <string.h>

int main(void)
{
    int k;
    static st1[15],st2="C programming";
    printf("Enter a string:\n");
    gets(st1);
    k = strcmp(st1,st2);             //功能：按照ASCII码顺序比较两个数组中的字符串，并通过函数值返回比较结果。
    if(k==0) printf("st1=st2\n");
    if(k>0) printf("st1>st2\n");
    if(k<0) printf("st1<st2\n");

}