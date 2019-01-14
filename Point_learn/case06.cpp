// case06.cpp
// Created by roohom on 2019/1/9.
// 2019/1/9 23:07

//双链表的基本操作案例

#include <stdio.h>
#include <malloc.h>

typedef struct LNode{
    int data;
    struct LNode *prior;
    struct LNode *next;
}DLNode,*DList;

//输出每个节点的数据
int displayList(DLNode *L,int n)
{
    DLNode *p;
    p = L->next;
    int i = 1;
    if(p== nullptr){
        printf("后面没有数据啦！");
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

//采用尾插法建立双链表
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

//查找节点

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

//插入节点
void insertElem(DLNode *&L,int e, int x)      //p为插入的位置，x为插入的元素值
{
    DLNode *p,*s;
    s = (DLNode *)malloc(sizeof(DLNode));     //新申请一个节点用来存放要插入的新数据元素
    s->data = x;
    s->prior = nullptr;                       //完成对新数据节点的初始化
    DLNode *i;
    int j=1;
    i = L->next;                              //从初始节点开始
    while(i!= nullptr)
    {
        if(e==j+1)
        {
            /*插入节点开始*/
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

//删除节点
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
        /*删除部分开始*/
        DLNode *p,*q;
        p = l;
        q = p->next;
        p->next = q->next;
        q->next->prior = p;
        free(q);
        /*删除部分结束*/
    }
}

int main(){
    int a[] = {1,2,3,4,5,6,7};
    DLNode *L;
    printf("(1)使用尾插法建立双链表L\n");
    tailCreateList(L,a,7);
    printf("现在打印双链表L：\n");
    displayList(L,7);
    printf("\n");
    printf("(2)在双链表L中查找5\n");
    printf("链表L中3的位置是:%d\n",findNode(L,5));
    printf("(3)现在将双链表中为5的元素删除\n");
    delListElem(L,5);
    printf("现在打印双链表L:\n");
    displayList(L,7);
    printf("\n");
    printf("(4)在第2个位置插入数据元素9\n");
    insertElem(L,2,9);
    printf("现在打印双链表L\n");
    displayList(L,7);

}




