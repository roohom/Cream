// str08.c
// Created by roohom on 2018/11/13.
// 2018/11/13 20:50

//计算一段文本中的单词个数

#include <stdbool.h>
#include <stdio.h>

bool alphabetic(const char c)
{
    if((c>='a' && c<='z') || (c>='A' && c<='Z'))
        return true;
    else
        return false;
}

void readLine(char buffer[])
{
    char character;
    int i =0;

    do
    {
        character = getchar();
        buffer[i] = character;
        ++i;
    }
    while(character != '\n');

    buffer[i-1] = '\0';
}

int countWords(const char string[])
{
    int i,wordCount = 0;
    bool flag = true;

    for(i=0;string[i]!='\0';++i)
    {
        if(alphabetic(string[i]))
        {
            if(flag)
            {
                ++wordCount;
                flag = false;
            }
        }
        else
            flag = true;
    }
    return wordCount;
}

int main(void)
{
    char string[81];
    int totalWords = 0;

    bool endOfString = false;

    printf("It can count the words you type in,just type here.\n");
    printf("When you are done, hit the enter ker.\n");

    while(!endOfString)
    {
        readLine(string);

        if(string[0] == '\0')
        {
            endOfString = true;

        }
        else
        {
            totalWords += countWords(string);
        }
    }

    printf("\nThere are %i words in the above tex.\n",totalWords);
}


