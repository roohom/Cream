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

//初始化链队
void initQueue(LiQueue *&lqu)
{
    lqu = (LiQueue *)malloc(sizeof(LiQueue));
    lqu->front = lqu->rear= nullptr;
}

//判断队空
int isQueueEmpty(LiQueue *lqu)
{
    if(lqu->rear==NULL||lqu->front==NULL)
    {
        printf("链队为空！\n");
        return 1;
    } else {
        printf("链队不为空！\n");
        return 0;
    }
}


//入队

int enQueue(LiQueue *lqu,int x)
{
    QNode *p;
    p = (QNode *)malloc(sizeof(QNode));
    p->data = x;
    printf("现在入队的元素是:%d\n",x);
    p->next = NULL;
    if(lqu->rear==NULL)                     //若队列为空，则新入队的是队首节点，也是队尾节点
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

//出队

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
    printf("现在出队的元素是:%d\n",x);
    free(p);
    return 1;
}


int main()
{
    LiQueue *L;
    int x = 0;
    printf("初始化链队:\n");
    initQueue(L);
    printf("现在检查链队是否为空:\n");
    isQueueEmpty(L);
    enQueue(L,1);
    enQueue(L,2);
    enQueue(L,3);
    enQueue(L,4);
    enQueue(L,5);
    printf("再次检查队列是否为空:\n");
    isQueueEmpty(L);
    deQueue(L, x);
    deQueue(L, x);
    deQueue(L, x);
    deQueue(L, x);
    deQueue(L, x);
    printf("再次检查队列是否为空:\n");
    isQueueEmpty(L);
}