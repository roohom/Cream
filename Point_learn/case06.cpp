// case06.cpp
// Created by roohom on 2019/1/9.
// 2019/1/9 23:07

//˫����Ļ�����������

#include <stdio.h>
#include <malloc.h>

typedef struct LNode{
    int data;
    struct LNode *prior;
    struct LNode *next;
}DLNode,*DList;

//���ÿ���ڵ������
int displayList(DLNode *L,int n)
{
    DLNode *p;
    p = L->next;
    int i = 1;
    if(p== nullptr){
        printf("����û����������");
        return 0;
    }
    while(p)
    {
        printf("%d", p->data);
        p = p->next;
        ++i;
        if(i<=n)
            continue;
        else
            break;
    }
    return 1;
}

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
    r->next = nullptr;

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

//����ڵ�
void insertElem(DLNode *&L,int e, int x)      //pΪ�����λ�ã�xΪ�����Ԫ��ֵ
{
    DLNode *p,*s;
    s = (DLNode *)malloc(sizeof(DLNode));     //������һ���ڵ��������Ҫ�����������Ԫ��
    s->data = x;
    s->prior = nullptr;                       //��ɶ������ݽڵ�ĳ�ʼ��
    DLNode *i;
    int j=1;
    i = L->next;                              //�ӳ�ʼ�ڵ㿪ʼ
    while(i!= nullptr)
    {
        if(e==j+1)
        {
            /*����ڵ㿪ʼ*/
            p = i;
            s->next = p->next;
            s->prior = p;
            p->next = s;
            s->next->prior = s;
        }
        ++j;
        i = i->next;
    }

}

//ɾ���ڵ�
void delListElem(DLNode *L,int x)
{
    DLNode *l;
    l = L;
    while(l->next!= nullptr)
    {
        if(l->next->data==x)
            break;
        l = l->next;
    }
    if(l->next== nullptr)
        return;
    else
    {
        /*ɾ�����ֿ�ʼ*/
        DLNode *p,*q;
        p = l;
        q = p->next;
        p->next = q->next;
        q->next->prior = p;
        free(q);
        /*ɾ�����ֽ���*/
    }
}

int main(){
    int a[] = {1,2,3,4,5,6,7};
    DLNode *L;
    printf("(1)ʹ��β�巨����˫����L\n");
    tailCreateList(L,a,7);
    printf("���ڴ�ӡ˫����L��\n");
    displayList(L,7);
    printf("\n");
    printf("(2)��˫����L�в���5\n");
    printf("����L��3��λ����:%d\n",findNode(L,5));
    printf("(3)���ڽ�˫������Ϊ5��Ԫ��ɾ��\n");
    delListElem(L,5);
    printf("���ڴ�ӡ˫����L:\n");
    displayList(L,7);
    printf("\n");
    printf("(4)�ڵ�2��λ�ò�������Ԫ��9\n");
    insertElem(L,2,9);
    printf("���ڴ�ӡ˫����L\n");
    displayList(L,7);

}




