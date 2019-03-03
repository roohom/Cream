// case14.cpp
// Author:roohom<roohom@qq.com>
// Created by roohom on 2019/3/3.
// 2019/3/3 20:34

//����ģʽƥ���㷨
/*��ģʽƥ���㷨*/

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

//��ģʽƥ��

int index(Str str,Str substr)
{
    //Ps:���ﴮ�е��ַ��洢λ����1~length
    int i=1,j=1,k=i;
    while(i<=str.length && j<=substr.length)
    {
        if(str.ch[i-1]==substr.ch[j-1]) ///�̲��ϵ��ж�������:(str.ch[i] == substr.ch[j]������֤�ڴ˳����в���
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


//�����������
int displayStr(Str &str)
{
    if(!str.ch)
        return 0;
    else
        printf("%s", str.ch);
}


int main(){
    //        123456789ABCD
    char l[]="ABABCABCACBAB";                 //����
    char m[]="BABC";                          //ģʽ��
    Str main_str,substr;
    printf("����������ģʽ��\n");
    strassign(main_str,l);
    strassign(substr,m);
    printf("���������������:\n");
    displayStr(main_str);
    printf("\n");
    displayStr(substr);
    printf("\n");
    printf("ִ�м�ģʽƥ�����\n");
    printf("��Ҫ�������в���ģʽ��������λ����:%d\n",index(main_str,substr));
    
    
}

/*
����������ģʽ��
���������������:
ABABCABCACBAB
  ABCA
ִ��KMPƥ�����
��Ҫ�������в���ģʽ��������λ����:3
*/