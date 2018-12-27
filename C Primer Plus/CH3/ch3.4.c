// ch3.4.c
// Created by roohom on 2018/12/27.
// 2018/12/27 11:18

#include <stdio.h>

int main(void){
    unsigned int un = 3000000000;
    short end = 200;
    long big = 65537;
    long long verybig = 12345678908642;

    printf("un = %u and not %d\n", un, un);
    printf("end = %hd and %d\n", end, end);
    printf("big = %ld and not %hd\n", big, big);
    printf("verybig = %lld and not %ld\n",verybig, verybig);

}