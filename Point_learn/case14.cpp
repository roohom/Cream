// case14.cpp
// Author:roohom<roohom@qq.com>
// Created by roohom on 2019/3/3.
// 2019/3/3 20:34

//串的模式匹配算法
/*简单模式匹配算法*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char *ch;
    int length;
}Str;



//串的赋值操作        用来构建一个串
int strassign(Str &str, char *ch)
{
    if(str.ch)
        free(str.ch);
    int len = 0;
    char *c = ch;
    while(*c)                  //求串的长度
    {
        ++len;
        ++c;
    }

    if(len == 0)
    {
        str.ch = nullptr;
        str.length = 0;
        return 1;
    }
    else
    {
        str.ch = (char *)malloc(sizeof(char)*(len+1));
        if(str.ch== nullptr)
            return 0;
        else
        {
            c = ch;
            for (int i = 0; i <=len ; ++i,++c)
                str.ch[i] = *c;
            str.length = len;
            return 1;

        }
    }

}

//简单模式匹配

int index(Str str,Str substr)
{
    //Ps:这里串中的字符存储位置是1~length
    int i=1,j=1,k=i;
    while(i<=str.length && j<=substr.length)
    {
        if(str.ch[i-1]==substr.ch[j-1]) ///教材上的判断条件是:(str.ch[i] == substr.ch[j]）经验证在此程序中不行
        {
            ++i;
            ++j;
        }
        else
        {
            j=1;
            i=++k;
        }
    }
    
    if(j>substr.length)
    {
        return k;
    }
    else
        return 0;
    
}


//输出串的内容
int displayStr(Str &str)
{
    if(!str.ch)
        return 0;
    else
        printf("%s", str.ch);
}


int main(){
    //        123456789ABCD
    char l[]="ABABCABCACBAB";                 //主串
    char m[]="BABC";                          //模式串
    Str main_str,substr;
    printf("构建主串和模式串\n");
    strassign(main_str,l);
    strassign(substr,m);
    printf("输出两个串的内容:\n");
    displayStr(main_str);
    printf("\n");
    displayStr(substr);
    printf("\n");
    printf("执行简单模式匹配过程\n");
    printf("所要在主串中查找模式串的索引位置是:%d\n",index(main_str,substr));
    
    
}

/*
构建主串和模式串
输出两个串的内容:
ABABCABCACBAB
  ABCA
执行KMP匹配过程
所要在主串中查找模式串的索引位置是:3
*/