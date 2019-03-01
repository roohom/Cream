// case13.cpp
// Author:roohom<roohom@qq.com>
// Created by roohom on 2019/3/1.
// 2019/3/1 19:47

#include <stdio.h>
#include <malloc.h>
#define maxSize 100

//����˳��洢�ṹ��
typedef struct {
    char str[maxSize+1];
    int length;
}String;

//�䳤����洢��ʾ
typedef struct 
{
    char *ch;
    int length;
}Str;

//���ĸ�ֵ����
int strassign(Str &str, char *ch)
{
    if(str.ch)
        free(str.ch);
    int len = 0;
    char *c = ch;
    while(*c)                  //�󴮵ĳ���
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



//ȡ���ĳ���
int strLength(Str str)
{
    return str.length;                        //ͨ����������length��Ա�Ľṹ�����洢���ĳ��ȣ��Ӷ�����һ�����ɵõ����ĳ��ȣ���ʱ�临�Ӷȴ�O(n)��ΪO(1)
}

//���ıȽϲ���
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

//�������Ӳ���
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

//���Ӵ�substring
int substring(Str &substr, Str str,int pos, int len)
{
    if(pos<0||pos>=str.length||len<0||len>str.length-pos) {
        printf("pos����lenԽ���ˣ�");
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

//����ղ���

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

//�����������
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
    printf("Ϊstr����ֵ:\n");
    strassign(str,l);
    displayStr(str);
    printf("Ϊs1����ֵ:\n");
    strassign(s1,m);
    displayStr(s1);
    printf("\n");
    printf("Ϊs2����ֵ:\n");
    strassign(s2,n);
    displayStr(s2);
    printf("\n");
    printf("���Ӵ�s1��s2:\n");
    concatnate(newStr,s1,s2);
    displayStr(newStr);
    printf("��str�����Ӵ�:\n");
    substring(substr,str,4,2);
    displayStr(substr);
    printf("\n");
    printf("���ıȽϣ��Ƚϴ�s1��s2:\n");
    strCompare(s1,s2);
    printf("%d\n", strCompare(s1,s2));
    printf("������մ�str:\n");
    clearStr(str);
    displayStr(str);
    
}