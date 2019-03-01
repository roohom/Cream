// case11.cpp
// Author:roohom<roohom@qq.com>
// Created by roohom on 2019/2/24.
// 2019/2/24 10:35

//顺序队的基本操作

#include <stdio.h>
#include <malloc.h>
#define maxsize 100

typedef struct
{
    int data[maxsize];
    int front;
    int rear;
}SqQueue;

//初始化顺序队
void initQueue(SqQueue &qu)
{
    qu.front = qu.rear = 0;             //队首和队尾重合并且指向0
    printf("初始化完成！\n");
}

//判断队空
int isEmptyQueue(SqQueue &qu)
{
    if(qu.front==qu.rear)
    {
        printf("顺序队为空！\n");
        return 1;
    }
    else {
        printf("顺序队不为空！\n");
        return 0;
    }
}

//入队操作
int in_Queue(SqQueue &qu, int x)
{
    if((qu.rear+1)%maxsize==qu.front)                  //判断队满，如果队满则不能继续入队
        return 0;
    qu.rear = (qu.rear+1)%maxsize;
    qu.data[qu.rear] = x;
    printf("现在入队的是:%d\n",x);
    return 1;
}

//出对操作
int out_Queue(SqQueue &qu, int &x)
{
    if(qu.rear == qu.front)                            //如果队空则不能出队
        return 0;
    qu.front = (qu.front+1)%maxsize;
    x = qu.data[qu.front];
    printf("现在出队的是:%d\n",x);
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