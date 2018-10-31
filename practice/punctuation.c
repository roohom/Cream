//
// Created by lenovo on 2018/10/31 0031.
//

#include <stdio.h>

main()
{
    int a=4, b=8, c=12, x, y, m;
    y = (a+b),(x=b+c);            // 先计算a+b，再计算b+c， 再计算x=b+c，x=b+c为最后的比表达式，逗号表达式等于最后一个表达式的结果
    printf("y=%d,x=%d\n", y, x);
    m = (x=a+b), (b+c);           // 先计算a+b，再计算b+c， 再计算x=a+b，x=a+b为最后的比表达式，逗号表达式等于最后一个表达式的结果
    printf("y=%d,x=%d\n", y, x);


}