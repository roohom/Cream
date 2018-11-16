// str11.c
// Created by roohom on 2018/11/16.
// 2018/11/16 16:11

// 将字符串转换为对应的整数
#include <stdio.h>

int str_to_int(const char string[])
{
    int i,intValue,result = 0;

    for (i = 0; string[i]>='0' && string[i]<='9'; ++i) {
        intValue=string[i]-'0';
        result = result*10+intValue;
    }
    return result;
}

int main(void)
{
    printf("%i\n",str_to_int("245"));
    printf("%i\n",str_to_int("100")+25);
    printf("%i\n",str_to_int("13x5"));
}