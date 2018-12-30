// ch4.2.c
// Created by roohom on 2018/12/31.
// 2018/12/31 2:55

#include <stdio.h>
#define PRAISE "You are an extraordinary being."

int main(void)
{
    char name[40];

    printf("What's your name?\n");
    scanf("%s", name);
    printf("Hello %s. %s\n", name, PRAISE);

}