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

//��ʼ��˳�������˳���ĳ�������Ϊ0
void initList(SqList *&L){
    L = (SqList *)malloc(sizeof(SqList));
    L->length=0;
}

//�ж�˳���ĳ���
int GetLen(SqList *L){
    return (L->length);
}

void DestroyList(SqList *L)        //�������Ա����ͷ����Ա���ռ�õ��ڴ�ռ�
{
    free(L);
}

//β�巨��˳����м�������Ԫ��
void insertElem1(SqList &L, char x){
    int i;
    for (i = GetLen(&L)-1; i < L.length; ++i) {
        L.data[i+1] = x;
    }
    ++(L.length);

}

//��ָ��λ�ò����ƶ�����Ԫ�أ���˳���ĵ�p��λ�ò����µ�Ԫ��e
int insertElem2(SqList &L, int p, char e)
{
    int i;
    if(p<0 || p > L.length || L.length==MaxSize)
    {
        return 0;
    }
    for (i = L.length-1; i >=p ; --i) {
        L.data[i+1] = L.data[i];               //�Ƚ���p��λ��֮���Ԫ�ذ����������ƶ�һ��λ�ã�����ǰһ��Ԫ�ص�ֵ�����ں�һ��Ԫ����
    }
    L.data[p] = e;                             //��p��λ�õ�ֵ��Ϊe
    ++(L.length);
    return 1;
}

//���˳���ĸ�������Ԫ��
int OutputElem(SqList *L){
    int i;
    for(i=0; i<L->length; i++)
        printf("%c", L->data[i]);
    printf("\n");
}

//��Ԫ��ֵ���ң���˳����в��ҵ�һ��Ԫ��ֵ����e��Ԫ�أ����������±�
int findElem(SqList L, char e){
    int i;
    for(i=0; i < L.length; ++i)
    {
        if(L.data[i] == e)
            return i;
    }
    return -1;
}

//ɾ��˳������±�Ϊp��ĳ��Ԫ�أ����ú���һ��Ԫ�ظ�����ǰһ��Ԫ���ϣ�Ҳ���Ǵ�pλ�ÿ�ʼ�����Ԫ�ذ�����ǰ�ƶ�һ��λ��
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

int main()   //��������ڣ���ʼ���úͲ��Ը�������
{
    //�����ǽ���˳���
    SqList *L;
    char e;
    printf("(1)��ʼ��˳���L\n");
    initList(L);
    printf("(2)ʹ��β�巨��ĩβ���β���Ԫ��a,b,c\n");
    insertElem1(*L, 'a');
    insertElem1(*L, 'b');
    insertElem1(*L, 'c');
    printf("(3)���˳���\n");
    OutputElem(L);
    printf("(4)ʹ��ָ��λ�ò������Ԫ��d,e,f\n");
    insertElem2(*L,0, 'd');
    insertElem2(*L,1, 'e');
    insertElem2(*L,2, 'f');
    printf("(5)���˳���\n");
    OutputElem(L);
    printf("(6)˳�����Ԫ��'c'�����=%d\n", findElem(*L, 'c'));
    printf("(7)����5��λ�õ�Ԫ��ɾ��\n");
    deleteElem(L, 5, e);
    printf("(8)�����ٴ����˳����Ԫ�أ�\n");
    OutputElem(L);
    printf("(9)�ͷ�˳���L\n");
    DestroyList(L);
}
