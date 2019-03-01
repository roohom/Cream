// case10.cpp
// Author:roohom<roohom@qq.com>
// Created by roohom on 2019/2/23.
// 2019/2/23 20:59

//��ջ�Ļ�������

#include <stdio.h>
#include <malloc.h>

typedef struct LNode
{
    int data;                             //������
    struct LNode *next;                   //ָ����
}LNode;

//��ջ�ĳ�ʼ��
void initStack(LNode *&lst)
{
    lst = (LNode *)malloc(sizeof(LNode));
    lst->next = nullptr;
    
}

//�ж�ջ�Ƿ�Ϊ��
int isEmptyStack(LNode *lst)
{
    if(lst->next== nullptr) {
        printf("ջ�ǿ�ջ\n");
        return 1;
    }else {
        printf("���ǿ�ջ\n");
        return 0;
    }
}

//��ջ����
void inStack(LNode *lst, int x)
{
    LNode *p;
    p = (LNode *)malloc(sizeof(LNode));
    p->next = nullptr;
    
    p->data = x;
    p->next = lst->next;
    lst->next = p;
    printf("������ջ��Ԫ����:%d\n",x);
}


//��ջ����
int outStack(LNode *lst, int &x)
{
    LNode *p;
    if(lst->next == nullptr)
        return 0;
    p = lst->next;
    x = p->data;
    lst->next = p->next;
    free(p);
    printf("���ڳ�ջ��Ԫ����:%d\n",x);
    return 1;
}


int main(){

    LNode *L;
    int x = 1;
    initStack(L);
    isEmptyStack(L);
    printf("���ڽ�����ջ����:\n");
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
    printf("������ϣ�");
}