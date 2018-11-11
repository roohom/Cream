// struct01.c
// Created by roohom on 2018/11/11.
// 2018/11/11 20:06


//演示一个结构体


#include <stdio.h>

int main(void)
{
    struct date
    {
        int month;
        int day;
        int year;
    };
    struct date today;

    today.month = 11;
    today.day = 11;
    today.year = 2018;


    printf("Today's date is %i/%i/%.2i\n", today.month, today.day,today.year%100);

}