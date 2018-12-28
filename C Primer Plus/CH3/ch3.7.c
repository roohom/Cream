// ch3.7.c
// Created by roohom on 2018/12/28.
// 2018/12/28 18:23

#include <stdio.h>

int main(void)
{
    float aboat = 32000.0;
    double abet = 2.14e9;
    long double dip = 5.32e-5;

    printf("%f can be written %e\n", aboat, aboat);
    printf("And it's %a in hexadecimal, powers of 2 notation\n", aboat);
    printf("%f can be written %e\n",abet, abet);
    printf("%Lf can be written %Lf\n", dip, dip);

}