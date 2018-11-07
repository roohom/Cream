//
// Created by roohom on 2018/11/7.
//

//输出字符串的长度


#include <stdio.h>
#include <string.h>

int main()
{
    int k;
    static char st[] = "C programming";
    k = strlen(st);
    printf("The str st`s length is %d ", k);
}