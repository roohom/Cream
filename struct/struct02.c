// struct02.c
// Created by roohom on 2018/11/11.
// 2018/11/11 20:33

//确定明天的日期

#include <stdio.h>


int main(void)
{
    struct date
    {
        int month;
        int day;
        int year;
    };
    struct date today,tomorow;

    const int daysPerMonth[12] = {31,28,31,30,31,30,
                                  31,31,30,31,30,31};

    printf("Plz enter today'date (mm dd yyyy):");
    scanf("%i%i%i", &today.month,&today.day,&today.year);

    if(today.day != daysPerMonth[today.month-1]){              // 判断是不是月末，不是的话只在日上加一
        tomorow.day = today.day + 1;
        tomorow.month = today.month;
        tomorow.year = today.year;
    }
    else if(today.month == 12)                                 // 判断是不是年末
    {
        tomorow.day = 1;
        tomorow.month = 1;
        tomorow.year = today.year + 1;
    }
    else{                                                      // 判断是不是月末
        tomorow.day = 1;
        tomorow.month = today.month + 1;
        tomorow.year = today.year;
    }


    printf("Tomorrow's date is %i %i %.2i.\n", tomorow.month, tomorow.day, tomorow.year);


}