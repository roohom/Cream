//
// Created by lenovo on 2018/10/30 0030.
//

#include <stdio.h>
#define N 80
int fun(char *s, char *t)
{
    int n=0; char *p, *r;
    while (*s)
    {
        p = s;
        r = t;
        while (*r)
            if (*r == *p)
            {
                r++;
                p++;

            }
            else break;
        if (*r == 0)
            n++;
        s++;
    }
    return n;

}

main()
{
    char a[N], b[N]; int m;
    printf("Enter string a:");
    gets(a);
    printf("Enter substring b:");
    gets(b);
    m = fun(a, b);
    printf("The result is : m=%d", m);

}