//
// Created by roohom on 2018/11/7.
//

//�ַ����ıȽ�
#include <stdio.h>
#include <string.h>

int main(void)
{
    int k;
    static st1[15],st2="C programming";
    printf("Enter a string:\n");
    gets(st1);
    k = strcmp(st1,st2);             //���ܣ�����ASCII��˳��Ƚ����������е��ַ�������ͨ������ֵ���رȽϽ����
    if(k==0) printf("st1=st2\n");
    if(k>0) printf("st1>st2\n");
    if(k<0) printf("st1<st2\n");

}