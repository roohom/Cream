// str05.c
// Created by roohom on 2018/11/13.
// 2018/11/13 19:56

//演示 %s scanf格式字符

#include <stdio.h>

int main(void)
{
    char s1[81],s2[81],s3[81];
    
    printf("Enter text here:\n");
    
    scanf("%s%s%s",s1,s2,s3);
    
    printf("\ns1= %s\ns2= %s\ns3= %s\n",s1,s2,s3);
    
}
