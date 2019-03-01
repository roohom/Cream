// case12.cpp
// Author:roohom<roohom@qq.com>
// Created by roohom on 2019/2/26.
// 2019/2/26 18:47

#include <stdio.h>
#include <malloc.h>

typedef struct QNode
{
    int data;
    struct QNode *next;
}QNode;

typedef struct 
{
    QNode *front;
    QNode *rear;
}LiQueue;

//��ʼ������
void initQueue(LiQueue *&lqu)
{
    lqu = (LiQueue *)malloc(sizeof(LiQueue));
    lqu->front = lqu->rear= nullptr;
}

//�ж϶ӿ�
int isQueueEmpty(LiQueue *lqu)
{
    if(lqu->rear==NULL||lqu->front==NULL)
    {
        printf("����Ϊ�գ�\n");
        return 1;
    } else {
        printf("���Ӳ�Ϊ�գ�\n");
        return 0;
    }
}


//���

int enQueue(LiQueue *lqu,int x)
{
    QNode *p;
    p = (QNode *)malloc(sizeof(QNode));
    p->data = x;
    printf("������ӵ�Ԫ����:%d\n",x);
    p->next = NULL;
    if(lqu->rear==NULL)                     //������Ϊ�գ�������ӵ��Ƕ��׽ڵ㣬Ҳ�Ƕ�β�ڵ�
    {
        lqu->front = p;
        lqu->rear = p;
    }
    else
    {
        lqu->rear ->next = p;
        lqu->rear = p;
    }
    
}

//����

int deQueue(LiQueue *lqu, int &x) {
    QNode *p;
    if(lqu->rear == NULL)
        return 0;
    else {
        p = lqu->front;

    }
    if(lqu->front == lqu->rear)
    {
        lqu->front = lqu->rear = NULL;
    }else
        lqu->front=lqu->rear->next;
    x = p->data;
    printf("���ڳ��ӵ�Ԫ����:%d\n",x);
    free(p);
    return 1;
}


int main()
{
    LiQueue *L;
    int x = 0;
    printf("��ʼ������:\n");
    initQueue(L);
    printf("���ڼ�������Ƿ�Ϊ��:\n");
    isQueueEmpty(L);
    enQueue(L,1);
    enQueue(L,2);
    enQueue(L,3);
    enQueue(L,4);
    enQueue(L,5);
    printf("�ٴμ������Ƿ�Ϊ��:\n");
    isQueueEmpty(L);
    deQueue(L, x);
    deQueue(L, x);
    deQueue(L, x);
    deQueue(L, x);
    deQueue(L, x);
    printf("�ٴμ������Ƿ�Ϊ��:\n");
    isQueueEmpty(L);
}