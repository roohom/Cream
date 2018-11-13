// str04.c
// Created by roohom on 2018/11/13.
// 2018/11/13 19:09

//判断两给字符串是否相等

#include <stdio.h>
#include <stdbool.h>

bool equalString(const char str1[],const char str2[]);

int main(void)
{
    const char str1[] = "lemon";
    const char str2[] = "Samsung";

    printf("%i\n",equalString(str1,str2));

}

bool equalString(const char str1[],const char str2[])
{
    bool equalFlag;

    int i = 0;
    while(str1[i]==str2[i] && str2[i]!='\0' && str2[i] != '\0')
    {
        ++i;
    }
    if(str1[i] == '\0' && str2[i]=='\0')
        equalFlag = true;
    else
        equalFlag = false;

    return equalFlag;
}