// enumeration.c
// Created by roohom on 2018/11/18.
// 2018/11/18 16:21

/******使用枚举类型打印一个月的天数******/

#include <stdio.h>

int main(void)
{
    enum month{January=1,February,March,April,May,June,
            July,August,September,October,November,December};
    enum month aMonth;
    int days;


    printf("Enter month number here:\n");
    scanf("%i",&aMonth);

    switch (aMonth){
        case January:
        case March:
        case May:
        case July:
        case August:
        case October:
        case December:
            days = 31;
            break;
        case April:
        case June:
        case September:
        case November:
            days = 30;
            break;
        case February:
            days = 28;
            break;
        default:
            printf("Bad month number\n");
            days = 0;
            break;
    }
    if(days!=0)
    {
        printf("Number of days is %i\n",days);
    }
    if(aMonth == February)
    {
        printf("...or 29 if ti is a leap year.\n");
    }

}