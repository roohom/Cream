//
// Created by roohom on 2018/11/6.
//

#include <stdio.h>

main()
{
    int i, a[10];
    for(i=0;i<=9;i++)
    {
        a[i]=i;

    }
    for(i=9;i>=0;i--)
    {
        printf("%d\n", a[i]);
    }
}