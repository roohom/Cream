//
// Created by roohom on 2018/11/6.
//
//从键盘上输入十个整数，并按照从大到小的顺序排列并输出
#include <stdio.h>

main()
{
    int i,j,p,q,s,a[10];
    printf("Enter 10 numbers here:\n");
    for(i=0;i<=10;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<=10;i++) {
        p = i;
        q = a[i];
        for (j = i + 1; j <= 10; j++) {
            if (a[j] > q) {
                q = a[j];
                p = j;
            }
        }
        if (i != p) {
            s = a[i];
            a[i] = a[p];
            a[p] = s;
        }
        printf("%d", a[i]);
    }
}