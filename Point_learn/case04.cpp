// case04.cpp
// Created by roohom on 2019/1/7.
// 2019/1/7 23:23

#include <stdio.h>
#include <malloc.h>
#define MaxSize 50
typedef char ElemType;

typedef struct
{
    ElemType elem[MaxSize];          //���˳����е�Ԫ��
    int length;                      //���˳���ĳ���
} SqList;

void InitList(SqList *&L)          //��ʼ�����Ա�����һ���յ����Ա�������������Ϊ0
{
    L=(SqList *)malloc(sizeof(SqList));
    L->length=0;
}

void DestroyList(SqList *L)        //�������Ա����ͷ����Ա���ռ�õ��ڴ�ռ�
{
    free(L);
}

int ListEmpty(SqList *L)           //�ж����Ա��Ƿ�Ϊ�� �����䳤���Ƿ�Ϊ0
{
    return(L->length==0);
}

int ListLength(SqList *L)          //�����Ա�ĳ���
{
    return(L->length);
}

void DispList(SqList *L)            //������Ա�
{
    int i;
    if (ListEmpty(L)) return;
    for (i=0;i<L->length;i++)
        printf("%c",L->elem[i]);
    printf("\n");
}

int GetElem(SqList *L,int i,ElemType &e)//�����Ա���ĳ������Ԫ�ص�ֵ
{
    if (i<1 || i>L->length)
        return 0;
    e=L->elem[i-1];
    return 1;
}

int LocateElem(SqList *L, ElemType e)//��Ԫ�ز��ң��ҵ����Ԫ��ֵ��ͬ��Ԫ�ز����������
{
    int i=0;
    while (i<L->length && L->elem[i]!=e) i++;
    if (i>=L->length)
        return 0;
    else
        return i+1;
}

int ListInsert(SqList *&L,int i,ElemType e)//��������Ԫ�أ��ڵ�i��λ���ϲ�����Ԫ�أ�ʹ�����Ԫ�����κ��ƣ����ǳ��ȼ�1��
{
    int j;
    if (i<1 || i>L->length+1)
        return 0;
    i--;                                 /*��˳���λ��ת��Ϊelem�±�*/
    for (j=L->length;j>i;j--)           /*��elem[i]������Ԫ�غ���һ��λ��*/
        L->elem[j]=L->elem[j-1];
    L->elem[i]=e;
    L->length++;                        /*˳�������1*/
    return 1;
}

int ListDelete(SqList *&L,int i,ElemType &e) //ɾ��ĳ��Ԫ�أ�ʹ�����Ԫ������ǰ�ƣ��������Ա�ĳ��ȼ�1��
{
    int j;
    if (i<1 || i>L->length)
        return 0;
    i--;                                /*��˳���λ��ת��Ϊelem�±�*/
    e=L->elem[i];
    for (j=i;j<L->length-1;j++)
        L->elem[j]=L->elem[j+1];
    L->length--;
    return 1;
}
int main()                            //����������ҪΪ���������ĵ���
{
    SqList *L;
    ElemType e;
    printf("(1)��ʼ��˳���L\n");
    InitList(L);
    printf("(2)���β���β�巨����a,b,c,d,eԪ��\n");
    ListInsert(L,1,'a');
    ListInsert(L,2,'b');
    ListInsert(L,3,'c');
    ListInsert(L,4,'d');
    ListInsert(L,5,'e');
    printf("(3)���˳���L:");
    DispList(L);
    printf("(4)˳���L����=%d\n",ListLength(L));
    printf("(5)˳���LΪ%s\n",(ListEmpty(L)?"��":"�ǿ�"));
    GetElem(L,3,e);
    printf("(6)˳���L�ĵ�3��Ԫ��=%c\n",e);
    printf("(7)Ԫ��a��λ��=%d\n",LocateElem(L,'a'));
    printf("(8)�ڵ�4��Ԫ��λ���ϲ���fԪ��\n");
    ListInsert(L,4,'f');
    printf("(9)���˳���L:");
    DispList(L);
    printf("(10)ɾ��L�ĵ�3��Ԫ��\n");
    ListDelete(L,3,e);
    printf("(11)���˳���L:");
    DispList(L);
    printf("(12)�ͷ�˳���L\n");
    DestroyList(L);
}
