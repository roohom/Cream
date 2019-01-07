// case03.cpp
// Created by roohom on 2019/1/7.
// 2019/1/7 22:02

#include <stdio.h>
#include <malloc.h>
//#include <iostream>
//using namespace std;
#define MaxSize 100

typedef struct {
    char data[MaxSize];
    int length;
} SqList;

//初始化顺序表，并将顺序表的长度设置为0
void initList(SqList *&L){
    L = (SqList *)malloc(sizeof(SqList));
    L->length=0;
}

//判断顺序表的长度
int GetLen(SqList *L){
    return (L->length);
}

void DestroyList(SqList *L)        //销毁线性表，即释放线性表所占用的内存空间
{
    free(L);
}

//尾插法在顺序表中加入数据元素
void insertElem1(SqList &L, char x){
    int i;
    for (i = GetLen(&L)-1; i < L.length; ++i) {
        L.data[i+1] = x;
    }
    ++(L.length);

}

//在指定位置插入制定数据元素，在顺序表的第p个位置插入新的元素e
int insertElem2(SqList &L, int p, char e)
{
    int i;
    if(p<0 || p > L.length || L.length==MaxSize)
    {
        return 0;
    }
    for (i = L.length-1; i >=p ; --i) {
        L.data[i+1] = L.data[i];               //先将第p个位置之后的元素挨个儿往后移动一个位置，即将前一个元素的值覆盖在后一个元素上
    }
    L.data[p] = e;                             //第p个位置的值设为e
    ++(L.length);
    return 1;
}

//输出顺序表的各个数据元素
int OutputElem(SqList *L){
    int i;
    for(i=0; i<L->length; i++)
        printf("%c", L->data[i]);
    printf("\n");
}

//按元素值查找，在顺序表中查找第一个元素值等于e的元素，并返回其下标
int findElem(SqList L, char e){
    int i;
    for(i=0; i < L.length; ++i)
    {
        if(L.data[i] == e)
            return i;
    }
    return -1;
}

//删除顺序表中下标为p的某个元素，即用后面一个元素覆盖在前一个元素上，也就是从p位置开始后面的元素挨个儿前移动一个位置
int deleteElem(SqList *&L, int p, char &e)
{
    int i;
    if(p<0 || p > L->length ){
        return 0;
    }
    e = L->data[p];
    for (i = p; i < L->length-1; i++) {
        L->data[i] = L->data[i+1];
    }
    --(L->length);
    return 1;
}

int main()   //主函数入口，开始调用和测试各个函数
{
    //首先是建立顺序表
    SqList *L;
    char e;
    printf("(1)初始化顺序表L\n");
    initList(L);
    printf("(2)使用尾插法在末尾依次插入元素a,b,c\n");
    insertElem1(*L, 'a');
    insertElem1(*L, 'b');
    insertElem1(*L, 'c');
    printf("(3)输出顺序表：\n");
    OutputElem(L);
    printf("(4)使用指定位置插入插入元素d,e,f\n");
    insertElem2(*L,0, 'd');
    insertElem2(*L,1, 'e');
    insertElem2(*L,2, 'f');
    printf("(5)输出顺序表：\n");
    OutputElem(L);
    printf("(6)顺序表中元素'c'的序号=%d\n", findElem(*L, 'c'));
    printf("(7)将第5个位置的元素删除\n");
    deleteElem(L, 5, e);
    printf("(8)现在再次输出顺序表各元素：\n");
    OutputElem(L);
    printf("(9)释放顺序表L\n");
    DestroyList(L);
}
