// ch4.3.c
// Created by roohom on 2018/12/31.
// 2018/12/31 2:59
#include <stdio.h>
#include <string.h>
#define PRAISE "You are an extraordinary being."

int main(void)
{
    char name[40];
    
    printf("What's your name?\n");
    scanf("%s", name);
    printf("Hello %s. %s\n", name, PRAISE);
    printf("Your name of %u letters occupies %u memory cells.\n",strlen(name), sizeof(name));
    
    printf("The phase of praise has %u letters.\n", strlen(PRAISE));
    printf("and occupies %u memory cells.\n", sizeof PRAISE);
    
}
