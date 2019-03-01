// case11.cpp
// Author:roohom<roohom@qq.com>
// Created by roohom on 2019/2/24.
// 2019/2/24 10:35

//˳��ӵĻ�������

#include <stdio.h>
#include <malloc.h>
#define maxsize 100

typedef struct
{
    int data[maxsize];
    int front;
    int rear;
}SqQueue;

//��ʼ��˳���
void initQueue(SqQueue &qu)
{
    qu.front = qu.rear = 0;             //���׺Ͷ�β�غϲ���ָ��0
    printf("��ʼ����ɣ�\n");
}

//�ж϶ӿ�
int isEmptyQueue(SqQueue &qu)
{
    if(qu.front==qu.rear)
    {
        printf("˳���Ϊ�գ�\n");
        return 1;
    }
    else {
        printf("˳��Ӳ�Ϊ�գ�\n");
        return 0;
    }
}

//��Ӳ���
int in_Queue(SqQueue &qu, int x)
{
    if((qu.rear+1)%maxsize==qu.front)                  //�ж϶���������������ܼ������
        return 0;
    qu.rear = (qu.rear+1)%maxsize;
    qu.data[qu.rear] = x;
    printf("������ӵ���:%d\n",x);
    return 1;
}

//���Բ���
int out_Queue(SqQueue &qu, int &x)
{
    if(qu.rear == qu.front)                            //����ӿ����ܳ���
        return 0;
    qu.front = (qu.front+1)%maxsize;
    x = qu.data[qu.front];
    printf("���ڳ��ӵ���:%d\n",x);
    return 1;
}


int main()
{
    SqQueue L;
    int x = 1;
    initQueue(L);
    isEmptyQueue(L);
    in_Queue(L,1);
    in_Queue(L,2);
    in_Queue(L,3);
    in_Queue(L,4);
    in_Queue(L,5);
    isEmptyQueue(L);
    out_Queue(L,x);
    out_Queue(L,x);
    out_Queue(L,x);
    out_Queue(L,x);
    out_Queue(L,x);
    isEmptyQueue(L);

}