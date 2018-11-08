// func03.c
// Created by roohom on 2018/11/8.
// 2018/11/8 19:01

//计算两个数的最大公约数并返回结果

#include <stdlib.h>
#include <stdio.h>

int gcd(int m ,int n)
{
    int temp;
    while(n != 0){
        temp = m%n;
        m = n;
        n = temp;
    }
    return m;

}
int main(void)
{
    int result;
    result = gcd(150,35);
    printf("The gcd of 150 and 35 is %i\n", result);

    result = gcd(1026, 405);
    printf("The gcd of 1026 and 405 is %i\n", result);

    printf("The gcd of 83 and 240 is %i\n",gcd(83, 240));
}

