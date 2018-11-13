// str02.c
// Created by roohom on 2018/11/13.
// 2018/11/13 18:27

//计算一个字符串中的字符个数

#include <stdio.h>

int stringLen(const char s[]);

int main(void)
{
    const char str1[] = "Lemon";
    const char str2[] = "apple";
    printf("str1's length is %i\n", stringLen(str1));
    printf("str2's length is %i\n", stringLen(str2));
}

int stringLen(const char s[])
{
    int count = 0;
    for (int i = 0; s[i] != '\0' ; ++i) {
        ++count;
    }
    return count;
}
