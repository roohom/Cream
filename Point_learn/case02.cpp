// case02.cpp
// Created by roohom on 2019/1/6.
// 2019/1/6 22:59

#include <stdio.h>
#include <stdlib.h>

/*����ָ������õ�����*/

void swap1(int &a, int &b)     // ʹ����������
{
    int temp;
    temp = a;
    a = b;
    b = temp;

}

void swap2(int a, int b)        //��ʹ����������
{
    int temp;
    temp = a;
    a = b;
    b = temp;

}

int main(){
    int x,y,a,b;
    scanf("%d%d%d%d", &x, &y, &a, &b);
    swap1(x, y);             // �������͸ı�a��b��ֵ
    printf("  ʹ��Ӧ�����͵���swap����֮��a,b��ֵ��");
    printf("%d-----%d\n",x,y);
    swap2(a, b);               //��ʹ�������������ı�a��b��ֵ
    printf("��ʹ���������͵���swap����֮��a��b��ֵ��");
    printf("%d-----%d\n",a,b);
}