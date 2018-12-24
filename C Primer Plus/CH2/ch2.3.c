// ch2.3.c
// Created by roohom on 2018/12/24.
// 2018/12/24 19:49

#include <stdio.h>
void butler(void);

int main(void)
{
    printf("I will summon the butler function.\n");
    butler();
    printf("Yes, Bring me some tea and writeable DVDs.\n");
    
}

void butler(void)
{
    printf("You rang, sir?\n");
}