// practice01.c
// Created by roohom on 2018/11/12.
// 2018/11/12 17:06

//������1900��3��1��֮�����������֮����������
// f(year, month) = year - 1 ��month<=2
//                  year     ����
// g(month) = month + 13     ��month<=2
//            month + 1      ����

// �������ԣ����������ʼ���ںͽ�ֹ���ڵ���������ͬ�����Ľ��������18
// Ҫʹ����õ������������ʼ�ͽ������ڶ�������ͬһ�꣬����8/8/2018��8/22/2018
#include <stdio.h>
struct date
{
    int month;
    int day;
    int year;
};
struct date start,end;
int f(struct date d);
int g(struct date d);
int count(int s, struct date d);


int main(void)
{
    int m,n,r;
    /*
    printf("Plz enter the start day:\n");
    scanf("%i%i%i",&start.month, &start.day, &start.year);
    printf("Plz enter the  end  day:\n");
    scanf("%i%i%i",&end.month, &end.day, &end.year);
     */
    start = (struct date){8,8,2004};                      //��ʼ����
    end = (struct date){8,22,2004};                       //��������

    f(start);
    g(start);
    m = count(r=0, start);

    f(end);
    g(end);
    n = count(r=1,end);
    printf("Days from %i/%i/%i to %i/%i/%i is %i .",start.month,start.day,start.year, end.month,end.day,end.year,(n-m));

}

int count(int s, struct date d)
{
    if(s==0){
        return (1461 * f(d) / 4 + (153 * g(d)) / 5 + 3);
    }
    else if(s==1){
        return (1461 * f(d) / 4 + (153 * g(d)) / 5 + 21);
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









