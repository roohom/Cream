// timeUpdate.c
// Created by roohom on 2018/11/12.
// 2018/11/12 0:08

//每一秒更新一次时间

#include <stdio.h>

struct time
{
    int hour;
    int seconds;
    int minutes;
};
struct time timeUpdate(struct time now);


int main(void)
{
    struct time currentTime, nextTime;

    printf("Enter the time(hh:mm:ss):");
    scanf("%i:%i:%i", &currentTime.hour,&currentTime.minutes,&currentTime.seconds);


    nextTime = timeUpdate(currentTime);

    printf("Update time is %.2i:%.2i:%.2i\n", nextTime.hour,nextTime.minutes,nextTime.seconds);

}


struct time timeUpdate(struct time now)
{
    ++now.seconds;
    if(now.seconds==60)
    {
        now.seconds=0;
        ++now.minutes;
        if(now.minutes == 60)
        {
            now.minutes = 0;
            ++now.hour;
            if(now.hour==24){
                now.hour=0;
            }
        }

    }
    return now;
}
