// struct03.c
// Created by roohom on 2018/11/11.
// 2018/11/11 21:08

// ��һ��������Ż��������ж��Ƿ�����������

#include <stdio.h>
#include <stdbool.h>
//ȷ�����������



struct date{
    int day;
    int month;
    int year;
};

int numberOfDays(struct date d);                      // ����������������strut date֮ǰ���򱨴�
int isLeapYear(struct date d);                        // ����������������strut date֮ǰ���򱨴�

int main(void)
{

    struct date today, tomorow;


    printf("Plz enter today'date (mm dd yyyy):");
    scanf("%i%i%i", &today.month,&today.day,&today.year);

    if(today.day != numberOfDays(today)){              // �ж��ǲ�����ĩ�����ǵĻ�ֻ�����ϼ�һ
        tomorow.day = today.day + 1;
        tomorow.month = today.month;
        tomorow.year = today.year;
    }
    else if(today.month == 12)                                 // �ж��ǲ�����ĩ
    {
        tomorow.day = 1;
        tomorow.month = 1;
        tomorow.year = today.year + 1;
    }
    else{                                                      // �ж��ǲ�����ĩ
        tomorow.day = 1;
        tomorow.month = today.month + 1;
        tomorow.year = today.year;
    }


    printf("Tomorrow's date is %i %i %.2i.\n", tomorow.month, tomorow.day, tomorow.year);
}

int numberOfDays(struct date d)
{
    int days;

    const int daysPerMonth[12] = {31,28,31,30,31,30,
                                  31,31,30,31,30,31};

    if(isLeapYear(d) && d.month == 2)
        days = 29;
    else
        days = daysPerMonth[d.month -1];

    return days;
}

int isLeapYear(struct date d)
{
    int leapYearFlag;
    leapYearFlag = (d.year % 4 == 0 && d.year % 100 != 0) || d.year & 400 == 0 ? 1 : 0;

    return leapYearFlag;
}