// case06.cpp
// Created by roohom on 2019/1/9.
// 2019/1/9 23:07

#include <stdio.h>
#include <malloc.h>

typedef struct DLNode{
    int data;
    struct DLNode *prior;
    struct DLNode *next;
}DLNode,*DList;

//���ÿ���ڵ������


//����β�巨����˫����
void tailCreateList(DLNode *&L, int a[], int n)
{
    DLNode *s,*r;
    int i;
    L = (DLNode *)malloc(sizeof(DLNode));
    L->prior = nullptr;
    L->next = nullptr;
    r = L;
    for (i = 0; i < n; ++i) {
        s = (DLNode *)malloc(sizeof(DLNode));
        s->data = a[i];
        r->next = s;
        s->prior = r;
        r = s;
    }

}

//���ҽڵ�

int findNode(DLNode *C,int x)
{
    int i=0;
    DLNode *p = C->next;
    while(p!= nullptr)
    {
        ++i;
        if(p->data==x)
        {
            break;
        }
        p = p->next;
    }
    return i;
}

int main(){
    int a[] = {1,2,3,4,5,6,7};
    DLNode *L;
    printf("(1)ʹ��β�巨����˫����L��\n");
    tailCreateList(L,a,7);
    printf("(2)��˫����L�в���5\n");
    printf("����L��3��λ����:%d\n",findNode(L,5));

}




