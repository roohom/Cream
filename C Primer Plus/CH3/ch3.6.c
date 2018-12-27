// ch3.6.c
// Created by roohom on 2018/12/27.
// 2018/12/27 17:23

#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    int32_t me32;    //me32是一个32位有符号整形变量

    me32 = 45933945;
    printf("First, assume int32_t is int:");
    printf("me32 = %d\n", me32);
    printf("Next, let's not make any assumptions.\n");
    printf("Instead, use a \"macro\" from inttypes.h:");
    printf("me32 = %" PRId32 "\n",me32);

}
