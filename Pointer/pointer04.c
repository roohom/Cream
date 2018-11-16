// pointer04.c
// Created by roohom on 2018/11/16.
// 2018/11/16 16:32

//使用指针和结构体
#include <stdio.h>


int main(void)
{
    struct date
    {
        int month;
        int day;
        int year;
    };
    
    struct date today,*datePtr;
    datePtr = &today;
    
    datePtr->month = 11;
    datePtr->day =16;
    datePtr->year=2018;
    
    printf("Today's date is %i/%i/%.2i.\n",datePtr->month,datePtr->day,datePtr->year);
}
