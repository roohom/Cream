//
// Created by roohom on 2018/11/7.
//
//字符串的复制

#include <stdio.h>
#include <string.h>

int main(void)
{
    char st1[]="C programming ",st2[]="C language";
    puts(st1);printf("\n");
    strcpy(st1,st2);                //把st2中的内容复制到st1中，并且覆盖st1中的内容。
    puts(st1);printf("\n");
}