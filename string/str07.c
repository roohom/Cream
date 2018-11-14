// str07.c
// Created by roohom on 2018/11/13.
// 2018/11/13 20:37

//计算单词个数

#include <stdio.h>
#include <stdbool.h>

bool alphabetic(const char c)
{
    if((c>='a' && c<='z') || (c>='A' && c <= 'Z'))
        return true;
    else
        return false;
}

int countWords(const char string[])
{
    int i, wordCount = 0;
    bool flag = true;

    for (i = 0; string[i]!='\0'; ++i) {
        if(alphabetic(string[i]))
        {
            if(flag)
            {
                ++wordCount;
                flag = false;
            }

        }
        else
        {
            flag = true;
        }
        
    }
    return wordCount;
}

int main(void)
{
    const char string1[] = "Plz work harder!";
    const char string2[] = "Plz study every day!";
    
    printf("%s  ---  words = %i\n",string1,countWords(string1));
    printf("%s  ---  words = %i\n",string2,countWords(string2));
}
