// case05.cpp
// Created by roohom on 2019/1/8.
// 2019/1/8 13:16
//���ڵ�����Ļ�������


//��һ�γ����ӡ�����ʱ��ֻ�Ǵ�ӡ����һ���ڴ��ַ���ɻ�
#include <stdio.h>
#include <malloc.h>
//������ڵ㶨��
typedef struct LNode{
    int data;
    struct LNode *next;
}LNnode;


//��������Ԫ��
void DispList(LNode *L)            //�������
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

//β�巨��������C
void tailCreatList(LNnode *&C, int a[], int n){
    LNnode *s,*r;                          //s����ָ��������Ľڵ㣬ʼ��ָ���ն˽ڵ�
    int i;
    C = (LNnode *)malloc(sizeof(LNode));   //�����ڴ�ռ佨������C
    C->next = NULL;                        //��ʾ����Ϊ��
    r = C;                                 //rʼ��ָ���ն˽ڵ�
    for(i = 0; i<n; ++i)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = a[i];
        r->next = s;
        r = r->next;
    }
    r->next = NULL;                         //����a�����е�Ԫ�ض��Ѿ�װ�������У����ڽ������ĩβָ������ΪNULL
}

//ͷ�巨��������C
void headCreatList(LNode *&C, int a[], int n)
{
    LNode *s;                               //s����ָ��������Ľڵ�
    int i;
    C = (LNode *)malloc(sizeof(LNode));
    C->next = NULL;                         //��
    for (i = 0; i < n; ++i) {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = a[i];
        /*ͷ�巨�ؼ�����*/
        s->next = C->next;                  //����s��ָ����µĽڵ��ָ����Ҳָ��Cָ��Ľڵ�
        C->next = s;                        //C��ָ��Ľڵ��ָ����ʹ����ɣ���ָ��s��ԭ�ȵ�C��ָ��Ľڵ��ָ��������
    }

}

//��������C����ͷ�ڵ㣩�Ƿ����һ��ֵΪx�Ľڵ㣬������ɾ���ýڵ㣬������1�����򷵻�0
int findAndDelElem(LNode *C, int x)
{
    LNode *p,*q;
    p = C;
    /*���Ҳ��ֿ�ʼ*/
    while(p->next!=NULL){
        if(p->next->data==x) {
            break;
        }
        p = p->next;

    }
    /*���Ҳ��ֽ���*/
    if(p->next==NULL)
        return 0;
    else
    {
        /*ɾ�����ֿ�ʼ*/
        q = p->next;
        p->next = p->next->next;
        free(q);
        /*ɾ�����ֽ���*/
        return 1;
    }
}

int main()
{
    LNode *C;
    LNode *L;
    printf("���濪ʼ��������ĺ���\n");
    int a[7] = {1,2,3,4,5,6,7};
    int b[7] = {7,6,5,4,3,2,1};
    printf("(1)ʹ��ͷ�巨��������C��\n");
    headCreatList(C, a, 7);
    printf("���ڴ�ӡ����C��\n");
    DispList(C);
    printf("(2)ʹ��β�巨��������L��\n");
    tailCreatList(L, b, 7);
    printf("���ڴ�ӡ����L��\n");
    DispList(L);
    printf("(3)�����������Ƿ���3���ֵ���еĻ�ɾ��.\n");
    findAndDelElem(C, 3);
    printf("���ڴ�ӡ����C��\n");
    DispList(C);
    findAndDelElem(L, 3);
    printf("���ڴ�ӡ����L��\n");
    DispList(L);
    printf("%d%d", L->next->data,L->next->next->data);
    printf("%d%d", C->next->data,C->next->next->data);
    free(L);
    free(C);


}
