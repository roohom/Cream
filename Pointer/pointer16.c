// pointer16.c
// Created by roohom on 2018/11/18.
// 2018/11/18 11:28
#include <stdio.h>

int main(void)
{
    char *message = ("Programming in C is fun.\n");
    char message1[] = "You said it.\n";
    int x = 100;

    //判断以下各组打印输出是否有效，每组printf()调用产生的输出是否相同；
    /***第一组***/
    printf("Programming in C is fun.\n");
    printf("%s","Programming in C is fun.\n");
    printf("%s",message);
    printf(message);

    printf("----------");
    /***第二组***/
    printf("You said is.\n");
    printf("%s",message1);
    printf(message1);
    printf("%s",&message1[0]);

    printf("----------");
    /***第三组***/

    printf("Said it.\n");
    printf(message1+4);
    printf("%s",message1+2);
    printf("%s",&message1[4]);
    printf("----------");
    /***第四组***/

    printf("x = %i\n",x);


}
