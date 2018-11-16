// pointer13.c
// Created by roohom on 2018/11/16.
// 2018/11/16 21:07


//CopyString的指针版本
//每当在C语言中使用常量字符串时，生成的都是指向该字符串的指针。
//---------------------------------------------------
// char *textPtr                   |
//                                  > 字符指针，有效写法
//textPtr = "A character string"   |
//---------------------------------------------------
//char text[80]                    |
//                                  > 字符数组，无效写法
//text = "This is not valid"       |
//---------------------------------------------------

#include <stdio.h>

void copyString(char *to,char *from)
{
    for (;*from != '\0'; ++from,++to) {
        *to = *from;
    }
    *to = '\0';
}

int main(void)
{
    char str1[] = "A string to copied.";
    char str2[50];

    copyString(str2,str1);
    printf("%s\n",str2);

    copyString(str2,"So is this.");
    printf("%s\n",str2);

}