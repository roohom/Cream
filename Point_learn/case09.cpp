// case09.cpp
// Author:roohom<roohom@qq.com>
// Created by roohom on 2019/2/23.
// 2019/2/23 20:07

//˳��ӵĻ�������


#include <stdio.h>
#include <malloc.h>
#define maxsize 100

//����һ��˳��ջ
typedef struct {
    int data[maxsize];
    int top;
}SqStack;

//ջ�ĳ�ʼ��
void initStack(SqStack &st)
{
    st.top=-1;
}

//ջ������
void delStack(SqStack &st)
{
    st.top=-1;
}

//�ж�ջ�Ƿ�Ϊ��

int isEmptyStack(SqStack &st)
{
    if(st.top==-1)
    {
        return 1;
    }
    else
        return 0;
}

//��ջ����

int inStack(SqStack &st, int x)
{
    if (maxsize - 1 == st.top)             //ջ���˼�����ջ�ͻ�����
        return 0;
    ++(st.top);
    st.data[st.top]=x;
    return 1;
}

//��ջ����
int outStack(SqStack &st,int m)
{
    if(st.top==-1)                         //ջ���˼�����ս�ͻ�����
        return 0;
    m = st.data[st.top];
    --st.top;
    printf("��ջ��Ԫ��Ϊ:%d\n",m);
    return 1;
}

int main(){
    SqStack L;
    initStack(L);
    printf("��Ԫ��1��2��3��4��5��ջ:\n");
    inStack(L,1);
    inStack(L,2);
    inStack(L,3);
    inStack(L,4);
    inStack(L,5);
    printf("��ջ��ϣ����ڼ��ջ�Ƿ�Ϊ��,�����:\n");
    if(isEmptyStack(L)==0)
        printf("��\n");
    else
        printf("��\n");
    printf("���ڽ��г�ջ����:\n");
    outStack(L,0);
    outStack(L,0);
    outStack(L,0);
    printf("������ϣ�\n");
    delStack(L);
}