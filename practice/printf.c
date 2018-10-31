//
// Created by lenovo on 2018/10/31 0031.
//

#include <stdio.h>


// printf函数
// 格式字符串
//      %[标志][输出最小宽度][.精度][长度]类型

main()
{
    int a = 65, b =66;
    printf("%d, %d\n", a, b);
    printf("%o, %o\n", a, b);
    printf("%x, %x\n", a, b);
    printf("%d, %d\n", a, b);
    printf("%c, %c\n", a, b);
    printf("a=%d, b=%d\n", a, b);
    printf("-------------------\n");
    int c=15;
    float d = 123.1234567;
    double e= 12345678.1234567;
    char f = 'p';
    printf("c=%d, %5d, %o, %x\n", c, c, c, c);
    printf("d=%f, %lf, %5.4lf, %e\n", d,d,d,d);
    printf("e=%lf,%f,%8.4lf\n", e,e,e);
    printf("f=%c, %8c\n", f,f);
}