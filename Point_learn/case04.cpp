// case04.cpp
// Created by roohom on 2019/1/7.
// 2019/1/7 23:23

#include <stdio.h>
#include <malloc.h>
#define MaxSize 50
typedef char ElemType;

typedef struct
{
    ElemType elem[MaxSize];          //存放顺序表中的元素
    int length;                      //存放顺序表的长度
} SqList;

void InitList(SqList *&L)          //初始化线性表，构造一个空的线性表，并将长度设置为0
{
    L=(SqList *)malloc(sizeof(SqList));
    L->length=0;
}

void DestroyList(SqList *L)        //销毁线性表，即释放线性表所占用的内存空间
{
    free(L);
}

int ListEmpty(SqList *L)           //判断线性表是否为空 即看其长度是否为0
{
    return(L->length==0);
}

int ListLength(SqList *L)          //求线性表的长度
{
    return(L->length);
}

void DispList(SqList *L)            //输出线性表
{
    int i;
    if (ListEmpty(L)) return;
    for (i=0;i<L->length;i++)
        printf("%c",L->elem[i]);
    printf("\n");
}

int GetElem(SqList *L,int i,ElemType &e)//求线性表中某个数据元素的值
{
    if (i<1 || i>L->length)
        return 0;
    e=L->elem[i-1];
    return 1;
}

int LocateElem(SqList *L, ElemType e)//按元素查找，找到与该元素值相同的元素并返回其序号
{
    int i=0;
    while (i<L->length && L->elem[i]!=e) i++;
    if (i>=L->length)
        return 0;
    else
        return i+1;
}

int ListInsert(SqList *&L,int i,ElemType e)//插入数据元素，在第i个位置上插入新元素，使后面的元素依次后移，并是长度加1；
{
    int j;
    if (i<1 || i>L->length+1)
        return 0;
    i--;                                 /*将顺序表位序转化为elem下标*/
    for (j=L->length;j>i;j--)           /*将elem[i]及后面元素后移一个位置*/
        L->elem[j]=L->elem[j-1];
    L->elem[i]=e;
    L->length++;                        /*顺序表长度增1*/
    return 1;
}

int ListDelete(SqList *&L,int i,ElemType &e) //删除某个元素，使后面的元素依次前移，并将线性表的长度减1；
{
    int j;
    if (i<1 || i>L->length)
        return 0;
    i--;                                /*将顺序表位序转化为elem下标*/
    e=L->elem[i];
    for (j=i;j<L->length-1;j++)
        L->elem[j]=L->elem[j+1];
    L->length--;
    return 1;
}
int main()                            //主函数，主要为各个函数的调用
{
    SqList *L;
    ElemType e;
    printf("(1)初始化顺序表L\n");
    InitList(L);
    printf("(2)依次采用尾插法插入a,b,c,d,e元素\n");
    ListInsert(L,1,'a');
    ListInsert(L,2,'b');
    ListInsert(L,3,'c');
    ListInsert(L,4,'d');
    ListInsert(L,5,'e');
    printf("(3)输出顺序表L:");
    DispList(L);
    printf("(4)顺序表L长度=%d\n",ListLength(L));
    printf("(5)顺序表L为%s\n",(ListEmpty(L)?"空":"非空"));
    GetElem(L,3,e);
    printf("(6)顺序表L的第3个元素=%c\n",e);
    printf("(7)元素a的位置=%d\n",LocateElem(L,'a'));
    printf("(8)在第4个元素位置上插入f元素\n");
    ListInsert(L,4,'f');
    printf("(9)输出顺序表L:");
    DispList(L);
    printf("(10)删除L的第3个元素\n");
    ListDelete(L,3,e);
    printf("(11)输出顺序表L:");
    DispList(L);
    printf("(12)释放顺序表L\n");
    DestroyList(L);
}
