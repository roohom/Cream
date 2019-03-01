// case10.cpp
// Author:roohom<roohom@qq.com>
// Created by roohom on 2019/2/23.
// 2019/2/23 20:59

//链栈的基本操作

#include <stdio.h>
#include <malloc.h>

typedef struct LNode
{
    int data;                             //数据域
    struct LNode *next;                   //指针域
}LNode;

//链栈的初始化
void initStack(LNode *&lst)
{
    lst = (LNode *)malloc(sizeof(LNode));
    lst->next = nullptr;
    
}

//判断栈是否为空
int isEmptyStack(LNode *lst)
{
    if(lst->next== nullptr) {
        printf("栈是空栈\n");
        return 1;
    }else {
        printf("不是空栈\n");
        return 0;
    }
}

//入栈操作
void inStack(LNode *lst, int x)
{
    LNode *p;
    p = (LNode *)malloc(sizeof(LNode));
    p->next = nullptr;
    
    p->data = x;
    p->next = lst->next;
    lst->next = p;
    printf("现在入栈的元素是:%d\n",x);
}


//出栈操作
int outStack(LNode *lst, int &x)
{
    LNode *p;
    if(lst->next == nullptr)
        return 0;
    p = lst->next;
    x = p->data;
    lst->next = p->next;
    free(p);
    printf("现在出栈的元素是:%d\n",x);
    return 1;
}


int main(){

    LNode *L;
    int x = 1;
    initStack(L);
    isEmptyStack(L);
    printf("现在进行入栈操作:\n");
    inStack(L,1);
    inStack(L,2);
    inStack(L,3);
    inStack(L,4);
    inStack(L,5);
    isEmptyStack(L);
    outStack(L,x);
    outStack(L,x);
    outStack(L,x);
    outStack(L,x);
    outStack(L,x);
    isEmptyStack(L);
    printf("操作完毕！");
}