// struct06.c
// Created by roohom on 2018/11/12.
// 2018/11/12 16:33

#include <stdio.h>

struct time
{
    int hour;
    int minutes;
    int seconds;
};

struct time updateTime(struct time now);

int main(void)
{
    struct time testTime[5] = {{11,59,59},{12,0,0},{1,29,59},{23,59,59},{19,17,27}};
    int i;

    for (i = 0; i < 5; ++i) {
        printf("Time is %.2i:%.2i:%.2i", testTime[i].hour,testTime[i].minutes,testTime[i].seconds);
        testTime[i] = updateTime(testTime[i]);
        printf("... one second later is %.2i:%.2i:%.2i\n",testTime[i].hour,testTime[i].minutes,testTime[i].seconds);
    }
}


struct time updateTime(struct time now)
{
    ++now.seconds;

    if(now.seconds==60){
        ++now.minutes;
        now.seconds = 0;
        if(now.minutes==60){
            ++now.hour;
            now.minutes=0;
            if(now.hour=24)
                now.hour=0;
        }
    }
    return now;
}