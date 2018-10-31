//
// Created by lenovo on 2018/10/31 0031.
//

// 格式输入函数Scanf
#include <stdio.h>

// %[*][输入数据宽度][长度]类型

main()
{
    int a, b, c;
    printf("Enter a,b,c:\n");
    scanf("%d%d%d", &a,&b,&c);
    printf("a=%d,b=%d,c=%d",a, b, c);

}