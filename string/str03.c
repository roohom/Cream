// str03.c
// Created by roohom on 2018/11/13.
// 2018/11/13 18:36


//Á¬½Ó×Ö·û´®£¬ÐÂ


#include <stdio.h>

void concat(char result[], const char str1[], const char str2[]);

int main(void)
{
    const char str1[] = "Study ";
    const char str2[] = "Hard!!!";

    char result[20];

    concat(result,str1,str2);

    printf("The combined two words is:\n");
    for (int i = 0; result[i] != '\0'; ++i) {
        printf("%c",result[i]);
    }
}


void concat(char result[], const char str1[], const char str2[])
{
    int i, j;
    for (i = 0; str1[i]!='\0'; ++i) {
        result[i] = str1[i];
    }
    for (j = 0; str2[j]!='\0' ; ++j) {
        result[i+j] = str2[j];
    }

    result[i+j] = '\0';
}