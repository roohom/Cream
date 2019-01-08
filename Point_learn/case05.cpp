// case05.cpp
// Created by roohom on 2019/1/8.
// 2019/1/8 13:16
//关于单链表的基本操作


//第一次出错打印链表的时候只是打印出来一串内存地址，疑惑
#include <stdio.h>
#include <malloc.h>
//单链表节点定义
typedef struct LNode{
    int data;
    struct LNode *next;
}LNnode;


//输出链表的元素
void DispList(LNode *L)            //输出链表
{
    LNode *i;
    i = L->next;
    if (i==NULL) return ;
    do
    {
        printf("%d", L->data);
        i = L->next;
    }
    while(i==NULL);
    printf("\n");
}

//尾插法建立链表C
void tailCreatList(LNnode *&C, int a[], int n){
    LNnode *s,*r;                          //s用来指向新申请的节点，始终指向终端节点
    int i;
    C = (LNnode *)malloc(sizeof(LNode));   //申请内存空间建立链表C
    C->next = NULL;                        //表示链表为空
    r = C;                                 //r始终指向终端节点
    for(i = 0; i<n; ++i)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = a[i];
        r->next = s;
        r = r->next;
    }
    r->next = NULL;                         //数组a中所有的元素都已经装入链表中，现在将链表的末尾指针域置为NULL
}

//头插法建立链表C
void headCreatList(LNode *&C, int a[], int n)
{
    LNode *s;                               //s用来指向新申请的节点
    int i;
    C = (LNode *)malloc(sizeof(LNode));
    C->next = NULL;                         //空
    for (i = 0; i < n; ++i) {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = a[i];
        /*头插法关键步骤*/
        s->next = C->next;                  //现在s所指向的新的节点的指针域也指向C指向的节点
        C->next = s;                        //C所指向的节点的指针域使命完成，将指针s与原先的C所指向的节点的指针域连接
    }

}

//查找链表C（带头节点）是否存在一个值为x的节点，若是则删除该节点，并返回1，否则返回0
int findAndDelElem(LNode *C, int x)
{
    LNode *p,*q;
    p = C;
    /*查找部分开始*/
    while(p->next!=NULL){
        if(p->next->data==x) {
            break;
        }
        p = p->next;

    }
    /*查找部分结束*/
    if(p->next==NULL)
        return 0;
    else
    {
        /*删除部分开始*/
        q = p->next;
        p->next = p->next->next;
        free(q);
        /*删除部分结束*/
        return 1;
    }
}

int main()
{
    LNode *C;
    LNode *L;
    printf("下面开始调用上面的函数\n");
    int a[7] = {1,2,3,4,5,6,7};
    int b[7] = {7,6,5,4,3,2,1};
    printf("(1)使用头插法建立链表C：\n");
    headCreatList(C, a, 7);
    printf("现在打印链表C：\n");
    DispList(C);
    printf("(2)使用尾插法建立链表L：\n");
    tailCreatList(L, b, 7);
    printf("现在打印链表L：\n");
    DispList(L);
    printf("(3)查找链表中是否有3这个值，有的话删除.\n");
    findAndDelElem(C, 3);
    printf("现在打印链表C：\n");
    DispList(C);
    findAndDelElem(L, 3);
    printf("现在打印链表L：\n");
    DispList(L);
    printf("%d%d", L->next->data,L->next->next->data);
    printf("%d%d", C->next->data,C->next->next->data);
    free(L);
    free(C);


}
