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
}LNode, *List;

/*用这种输出方式为什么不行？只打印出一串内存地址？？？
//输出链表的元素
int dispList(LNode *L)            //输出链表
{
    LNode *i;
    i = L;
    if (i->next== nullptr) return 0;
    do
    {
        printf("%d", i->data);
        i = i->next;
    }
    while(i == nullptr);
    printf("\n");
}
用这种输出方式为什么不行？只打印出一串内存地址？？？*/

int DisplayList(List l)
{
    List p = nullptr;
    p = l->next;
    int k = 0;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
        k++;
    }
    if (k == 0)
    {
        printf("链表为空");
        return false;
    }
    printf("\n");
    return 1;
}

//尾插法建立链表C
void tailCreatList(LNode *&C, int a[], int n){
    LNode *s,*r;                          //s用来指向新申请的节点，始终指向终端节点
    int i;
    C = (LNode *)malloc(sizeof(LNode));   //申请内存空间建立链表C
    C->next = nullptr;                        //表示链表为空
    r = C;                                 //r始终指向终端节点
    for(i = 0; i<n; ++i)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = a[i];
        r->next = s;
        r = r->next;
    }
    r->next = nullptr;                         //数组a中所有的元素都已经装入链表中，现在将链表的末尾指针域置为NULL
    printf("链表（尾插法）创建成功！\n");
}

//头插法建立链表C
void headCreatList(LNode *&C, int a[], int n)
{
    LNode *s;                               //s用来指向新申请的节点
    int i;
    C = (LNode *)malloc(sizeof(LNode));
    C->next = nullptr;                         //空
    for (i = 0; i < n; ++i) {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = a[i];
        /*头插法关键步骤*/
        s->next = C->next;                  //现在s所指向的新的节点的指针域也指向C指向的节点
        C->next = s;                        //C所指向的节点的指针域使命完成，将指针s与原先的C所指向的节点的指针域连接
    }
    printf("链表（头插法）创建成功！\n");

}

//查找链表C（带头节点）是否存在一个值为x的节点，若是则删除该节点，并返回1，否则返回0
int findAndDelElem(LNode *C, int x)
{
    LNode *p,*q;
    p = C;
    /*查找部分开始*/
    while(p->next!= nullptr){
        if(p->next->data==x) {
            break;
        }
        p = p->next;

    }
    /*查找部分结束*/
    if(p->next== nullptr)
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

int main() {
    LNode *C;
    LNode *L;
    printf("下面开始调用上面的函数\n");
    int a[7] = {1, 2, 3, 4, 5, 6, 7};
    int b[7] = {1, 2, 3, 4, 5, 6, 7};
    printf("(1)使用头插法建立链表C：\n");
    headCreatList(C, a, 7);
    printf("现在打印链表C：\n");
    DisplayList(C);
    printf("(2)使用尾插法建立链表L：\n");
    tailCreatList(L, b, 7);
    printf("现在打印链表L：\n");
    DisplayList(L);
    printf("(3)查找链表中是否有3这个值，有的话删除.\n");
    findAndDelElem(C, 3);
    printf("现在打印链表C：\n");
    DisplayList(C);
    findAndDelElem(L, 3);
    printf("现在打印链表L：\n");
    DisplayList(L);
    free(L);
    free(C);
}