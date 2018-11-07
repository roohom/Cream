//
// Created by roohom on 2018/11/7.
//
//中间带有空格的字符串的输入/输出
#include <stdio.h>

int main(void)
{
    char st1[6],st2[6],st3[6],st4[6];
    printf("Enter a string:\n");
    scanf("%s%s%s%s", st1,st2,st3,st4);            //scanf的各输入项必须是以地址方式出现，如&st1，但在此却使用st1是因为
                                                   //C语言中规定，数组名代表数组的首地址，是个地址常量。整个数组是以首地址开头的内存单元。
    printf("%s %s %s %s\n", st1, st2, st3, st4);
    
}