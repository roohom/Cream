// pointer15.c
// Created by roohom on 2018/11/17.
// 2018/11/17 22:52

//用指针求字符串的长度

#include <stdio.h>

int stringLength(const char *string)
{
    const char *cptr = string;

    while(*cptr)
    {
        ++cptr;
    }

    return cptr-string;
}

int main(void)
{
    printf("%i ",stringLength("stringLength test"));
    printf("%i ",stringLength(""));
    printf("%i\n",stringLength("complete"));
}