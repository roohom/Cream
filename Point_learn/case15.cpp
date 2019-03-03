// case15.cpp
// Author:roohom<roohom@qq.com>
// Created by roohom on 2019/3/3.
// 2019/3/3 22:54

/*֪����KMP�㷨*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char *ch;
    int length;
}Str;



//���ĸ�ֵ����        ��������һ����
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


//���ȵõ�next[]����
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
        if (j == 0 || str.ch[i-1] == substr.ch[j-1]) { //�̲��ϵ��ж�������:(j == 0 || str.ch[i] == substr.ch[j]������֤�ڴ˳����в���
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
//�����������
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
    char l[]="ABABCABCACBAB";                 //����
    char m[]="ABCA";                          //ģʽ��
    int next[100];
    Str str,substr;
    printf("����������ģʽ��\n");
    strassign(str,l);
    strassign(substr,m);
    printf("���������������:\n");
    displayStr(str);
    printf("\n");
    displayStr(substr);
    printf("\n");
    printf("ִ��KMPƥ�����\n");
    getnext(substr,next);
    printf("��Ҫ�������в���ģʽ��������λ����:%d\n",KMP(str,substr,next));
}