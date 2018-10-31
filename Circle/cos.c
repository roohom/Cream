//
// Created by lenovo on 2018/10/30 0030.
//

#include <stdio.h>
#include <math.h>

int main()
{
    double x, s;
    printf("Enter a number:\n");
    scanf("%lf", &x);
    s = cos(x);
    printf("cosine of %lf is %lf\n", x, s);
}