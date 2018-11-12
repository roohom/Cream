// practice01.c
// Created by roohom on 2018/11/12.
// 2018/11/12 17:06

//计算自1900年3月1日之后的任意两天之间相差的天数
// f(year, month) = year - 1 若month<=2
//                  year     否则
// g(month) = month + 13     若month<=2
//            month + 1      否则


#include <stdio.h>
struct date
{
    int month;
    int day;
    int year;
};

int f(struct date d);
int g(struct date d);
long int count(int s);

int main(void)
{
    struct date start,end;
    int m,n,r;

    start = (struct date){8, 8, 2004};
    end = (struct date){2, 22, 2005};
    f(start);
    g(start);
    m = count(r=0);
    printf("%d\n", m);

    f(end);
    g(end);
    n = count(r=1);
    printf("%d\n",n);
    printf("Days from %i/%i/%i to %i/%i/%i is %i .",start.month,start.day,start.year, end.month,end.day,end.year,(n-m));

}

long int count(int s)
{
    long int l;
    if(s==0){
        l = 1461 * (int)f / 4 + (153 * (int)g) / 5 + 3;
        printf("这是N1的值：");
        printf("%i\n",l);
        return l;
    }
    else if(s==1){
        l= 1461 * (int)f / 4 + (153 * (int)g) / 5 + 21;
        printf("这是N2的值：");
        printf("%i\n",l);
        return l;
    }


}

int f(struct date d)
{
    if(d.month<=2)
        return d.year-1;
    else
        return d.year;
}

int g(struct date d)
{
    if(d.month<=2)
        return d.month+13;
    else
        return d.month+1;
}









