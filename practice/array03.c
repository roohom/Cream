//
// Created by roohom on 2018/11/6.
//
//从键盘输入十个整数，并输出其中最大的数
#include <stdio.h>

main()
{
    int i,max,a[10];
    printf("Enter 10 numbers here:\n");
    for(i=0;i<10;i++)
    {
        scanf("%d", &a[i]);
    }
    max = a[0];
    for(i=0;i<9;i++)
    {
        if(a[i+1]>max)
            max=a[i+1];
    }
    printf("%d", max);
}
