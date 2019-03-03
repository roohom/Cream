// case15.cpp
// Author:roohom<roohom@qq.com>
// Created by roohom on 2019/3/3.
// 2019/3/3 22:54

/*知名的KMP算法*/

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


//首先得到next[]数组
void getnext(Str substr, int next[])
{
    int i=1,j=0;
    next[1]=0;
    while(i<substr.length)
    {
        if(j==0||substr.ch[i]==substr.ch[j])
        {
            ++i;
            ++j;
            next[i]=j;
        }
        else
            j = next[j];
    }
}

int KMP(Str str,Str substr,int next[])
{
    int i=1,j=1;
    while(i<=str.length && j<=substr.length) {
        if (j == 0 || str.ch[i-1] == substr.ch[j-1]) { //教材上的判断条件是:(j == 0 || str.ch[i] == substr.ch[j]）经验证在此程序中不行
            ++i;
            ++j;
        } else {
            j = next[j];
        }
    }
    if(j>substr.length)
    {
        return i-substr.length;
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


int main()
{
    //        123456789ABCD
    char l[]="ABABCABCACBAB";                 //主串
    char m[]="ABCA";                          //模式串
    int next[100];
    Str str,substr;
    printf("构建主串和模式串\n");
    strassign(str,l);
    strassign(substr,m);
    printf("输出两个串的内容:\n");
    displayStr(str);
    printf("\n");
    displayStr(substr);
    printf("\n");
    printf("执行KMP匹配过程\n");
    getnext(substr,next);
    printf("所要在主串中查找模式串的索引位置是:%d\n",KMP(str,substr,next));
}