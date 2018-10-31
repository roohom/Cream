//
// Created by lenovo on 2018/10/31 0031.
//

#include <stdio.h>

// getchar()函数（键盘输入函数），只接受单个字符，多个字符只接受第一个


main()
{
    int c;
    printf("Enter a character:");
    c = getchar();
    printf("%c -----> hex%x\n", c, c);

}