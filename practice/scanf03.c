//
// Created by roohom on 2018/10/31 0031.
//

#include <stdio.h>

main()
{
    int i;
    long l;
    float f;
    double d;
    char c;
    printf("\nint:%d字节\nlong:%d字节\nfloat:%d字节\ndouble:%d字节\nchar:%d字节\n",
            sizeof(i), sizeof(l), sizeof(f), sizeof(d), sizeof(c));
}