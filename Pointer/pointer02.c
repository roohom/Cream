// pointer02.c
// Created by roohom on 2018/11/16.
// 2018/11/16 16:24
#include <stdio.h>

int main(void)
{
    char c = 'Q';
    char *char_pointer = &c;

    printf("%c ---- %c\n",c,*char_pointer);

    c = '/';
    printf("%c ---- %c\n",c,*char_pointer);

    *char_pointer = '(';
    printf("%c ---- %c\n",c,*char_pointer);
}
