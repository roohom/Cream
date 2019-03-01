// case13.cpp
// Author:roohom<roohom@qq.com>
// Created by roohom on 2019/3/1.
// 2019/3/1 19:47

#include <stdio.h>
#include <malloc.h>
#define maxSize 100

//定长顺序存储结构体
typedef struct {
    char str[maxSize+1];
    int length;
}String;

//变长分配存储表示
typedef struct 
{
    char *ch;
    int length;
}Str;

//串的赋值操作
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



//取串的长度
int strLength(Str str)
{
    return str.length;                        //通过构建带有length成员的结构体来存储串的长度，从而可以一步即可得到串的长度，将时间复杂度从O(n)变为O(1)
}

//串的比较操作
int strCompare(Str s1, Str s2)
{
    for(int i=0;i<s1.length && i<s2.length; ++i)
    {
        if(s1.ch[i] == s2.ch[i])
        {
            return (s1.ch[i]-s2.ch[i]);
        }
        else
            return (s1.length-s2.length);
    }
}

//串的连接操作
int concatnate(Str &str, Str &str1, Str &str2)
{
    if(str.ch){
        free(str.ch);
        str.ch = nullptr;
    }
    str.ch = (char *)malloc(sizeof(char) * (str1.length+str2.length+1));
    if(str.ch== nullptr)
        return 0;
    int i = 0;
    while(i<str1.length)
    {
        str.ch[i]=str1.ch[i];
        ++i;
    }
    int j=0;
    while(j<str2.length)
    {
        str.ch[i+j] = str2.ch[j];
        ++j;
    }
    str.length = str1.length+str2.length;
    return 1;
}

//求子串substring
int substring(Str &substr, Str str,int pos, int len)
{
    if(pos<0||pos>=str.length||len<0||len>str.length-pos) {
        printf("pos或者len越界了！");
        return 0;
    }
    if(substr.ch)
    {
        free(substr.ch);
        substr.ch = nullptr;
    }
    if(len==0)
    {
        substr.ch= nullptr;
        substr.length = 0;
        return 1;
    } else
    {
        substr.ch=(char *)malloc(sizeof(char)*len+1);
        int i=pos;
        int j=0;
        while(i<pos+len)
        {
            substr.ch[j] = str.ch[i];
            ++i;
            ++j;
        }
        substr.ch[j] = '\0';
        substr.length = len;
        return 1;
    }
}

//串清空操作

int clearStr(Str &str)
{
    if(str.ch)
    {
        free(str.ch);
        str.ch = nullptr;
    }
    str.length = 0;
    return 1;
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
    char l[] = "ABCACBCAB\n";
    char m[] = "DEFDFEFED";
    char n[] = "OOOOOOOOO\n";
    Str str,s1,s2,newStr, substr;
    printf("为str串赋值:\n");
    strassign(str,l);
    displayStr(str);
    printf("为s1串赋值:\n");
    strassign(s1,m);
    displayStr(s1);
    printf("\n");
    printf("为s2串赋值:\n");
    strassign(s2,n);
    displayStr(s2);
    printf("\n");
    printf("连接串s1和s2:\n");
    concatnate(newStr,s1,s2);
    displayStr(newStr);
    printf("求str串的子串:\n");
    substring(substr,str,4,2);
    displayStr(substr);
    printf("\n");
    printf("串的比较，比较串s1和s2:\n");
    strCompare(s1,s2);
    printf("%d\n", strCompare(s1,s2));
    printf("现在清空串str:\n");
    clearStr(str);
    displayStr(str);
    
}