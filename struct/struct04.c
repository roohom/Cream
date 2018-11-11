// struct04.c
// Created by roohom on 2018/11/11.
// 2018/11/11 23:31

#include <stdio.h>
#include <stdbool.h>

struct date
{
    int month;
    int day;
    int year;
};

bool isLeapYear(struct date d);
int numberOfDays(struct date d);

struct date dateUpdate(struct date today)
{
    struct date tomorrow;
    printf("Plz enter today'date (mm dd yyyy):");
    scanf("%i%i%i", &today.month,&today.day,&today.year);

    
    if(today.day != numberOfDays(today)){              // 判断是不是月末，不是的话只在日上加一
        tomorrow.day = today.day + 1;
        tomorrow.month = today.month;
        tomorrow.year = today.year;
    }
    else if(today.month == 12)                                 // 判断是不是年末
    {
        tomorrow.day = 1;
        tomorrow.month = 1;
        tomorrow.year = today.year + 1;
    }
    else{                                                      // 判断是不是月末
        tomorrow.day = 1;
        tomorrow.month = today.month + 1;
        tomorrow.year = today.year;
    }
    return tomorrow;
    
}


int numberOfDays(struct date d)
{
    int days;
    
    const int daysPerMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    
    if(isLeapYear(d) && d.month == 2)
        days = 29;
    else
        days = daysPerMonth[d.month-1];

    return days;
}

bool isLeapYear(struct date d)
{
    bool leapYearFlag;
    if((d.year%4 == 0 && d.year % 100!=0) || d.year %400 ==0)
        leapYearFlag = true;
    else
        leapYearFlag = false;

    return leapYearFlag;
}

int main(void)
{
    struct date thisDay,nextDay;
    
    printf("Plz enter today's date(mm dd yyyy):");
    scanf("%i%i%i", &thisDay.month,&thisDay.day,&thisDay.year);
    
    nextDay = dateUpdate(thisDay);
    
    printf("Tomorrow's date is %i/%i/%.2i.\n",nextDay.month,nextDay.day,nextDay.year%100);
    
    
}

