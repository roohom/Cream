// case01.cpp
// Author:roohom<roohom@qq.com>
// Created by roohom on 2019/1/11.
// 2019/1/11 22:10


#include <stdio.h>
#include <stdlib.h>

/*����ָ������õ�����*/

void swap1(int *a, int *b)     // ʹ��ָ������
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;

}

void swap2(int &a, int &b)     //ʹ����������
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void swap3(int a, int b)        //��ʹ����������
{
    int temp;
    temp = a;
    a = b;
    b = temp;

}

int main(){

    int x=1,y=2;
    int a=1,b=2;
    int c=1,d=2;
    swap1(&x, &y);             // ָ�����͸ı�a��b��ֵ
    printf("  ʹ��ָ�����͵���swap����֮��a,b��ֵ��");
    printf("%d-----%d\n",x,y);
    swap2(a, b);               // �������͸ı�a��b��ֵ
    printf("  ʹ���������͵���swap����֮��a,b��ֵ��");
    printf("%d-----%d\n",x,y);
    swap3(a, b);               //��ʹ�������������ı�ab��ֵ
    printf("��ʹ���������͵���swap����֮��a��b��ֵ��");
    printf("%d-----%d\n",c,d);
}

// д���˱������������ϲ�֪��C������û������,C++�в�������  �ֶ���ͷ
/*Clion�������г���Ī������*/
//D:\Clion Projects\Cream\Point_learn\case01.c:9:16: error: expected ';', ',' or ')' before '&' token
// void swap1(int &a, int &b)     // 使用引用类型
