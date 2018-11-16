// pointer14.c
// Created by roohom on 2018/11/16.
// 2018/11/16 21:26

//CopyString的修订版本

#include <stdio.h>

void copyString(char *to, char *from)
{
    while(*from)
    {
        *to++=*from++;
    }
    *to = '\0';
}
int main(void)
{
    char str1[] = "A string to be copied.";
    char str2[50];
    
    copyString(str2,str1);
    printf("%s\n",str2);
    
    copyString(str2,"So is this.");
    printf("%s\n",str2);
}
