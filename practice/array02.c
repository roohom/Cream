//
// Created by roohom on 2018/11/6.
//

#include <stdio.h>

main()
{
    int i,a[10];
    for(i=0;i<=10;i++)
    {
        a[i]=2*i+1;

    }
    for(i=0;i<=9;i++)
    {
        printf("%d  ",a[i]);
    }
    printf("\n%d %d\n", a[2], a[8]);
}