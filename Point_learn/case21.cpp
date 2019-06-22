//
// Created by roohom on 19-6-22.
//

//����������
#include <stdio.h>
#include <malloc.h>
#include <iostream>
#include <search.h>

using namespace std;

#define maxsize 15


typedef struct TBTNode
{
    char data;
    int ltag, rtag;         //�������
    struct TBTNode *lchild;
    struct TBTNode *rchild;
}TBTNode;



void Visit(TBTNode *p)
{
    cout<<p->data<<endl;
}



//����������
void createBinaryTree(TBTNode *&p)
{
    char ch;
    cin>>ch;
    if(ch == '#')     //�������Ҷ�ӽڵ㣬�����������������ֱ�ֵΪ0
    {
        p = nullptr;
    }
    else
    {
        p = (TBTNode *)malloc(sizeof(TBTNode));
        p->data = ch;
        createBinaryTree(p->lchild);  //�ݹ鴴��������
        createBinaryTree(p->rchild);  //�ݹ鴴��������
    }
}


//ͨ����������Զ���������������
void InThread(TBTNode *p,TBTNode *&pre)
{
    if (p!= nullptr)
    {
        InThread(p->lchild,pre);               //�ݹ飬������������
        if(p->lchild!= nullptr)
        {
            p->lchild = pre;                   //������ǰ�ڵ��ǰ������
            p->ltag=1;
        }
        if(pre!=nullptr && pre->rchild==nullptr)//
        {
            pre->rchild = p;                   //������ǰ�ڵ�ĺ������
            pre->rtag = 1;
        }
        pre = p;                               //preָ��ǰ��p����Ϊp��Ҫָ�����һ���ڵ��ǰ���ڵ�ָʾָ��
        p= p->rchild;                          //pָ��һ���µĽڵ㣬��ʼ�ظ�����
        InThread(p->rchild,pre);                       //�ݹ飬������������
    }
}

//ͨ�����������������������������

void createInThread(TBTNode *root)
{
    TBTNode *pre = nullptr;
    if(root!= nullptr)
    {
        InThread(root,pre);
        pre->rchild = nullptr;
        pre->rtag = 1;
    }
}


//ǰ������������
void preThread(TBTNode *p,TBTNode *&pre)
{
    if(p!= nullptr)
    {
        if(p->lchild!= nullptr)
        {
            p->lchild = pre;
            p->ltag = 1;
        }
        if(pre!=nullptr && pre->rchild==nullptr)
        {
            pre->rchild=p;
            pre->rtag=1;
        }
        pre = p;
        if(p->ltag==0)
            preThread(p->lchild,pre);
        if(p->rtag==0)
            preThread(p->rchild,pre);

    }
}


void createPreThread(TBTNode *root)
{
    TBTNode *pre = nullptr;
    if(root!= nullptr)
    {
        preThread(root,pre);
        pre->rchild = nullptr;
        pre->rtag = 1;
    }
}


//��������������������
//����pΪ�������������������У����������µĵ�һ���ڵ�
TBTNode *First(TBTNode *p)
{
    while(p->ltag==0)
    {
        p=p->lchild;
    }
    return p;
}

//�������������������У��ڵ�p�������µĺ�̽ڵ�
TBTNode *Next(TBTNode *p)
{
    if(p->rtag==0)
        return First(p->rchild);
    else
        return p->rchild;
}

//��ǰ�������������Ļ�����ִ��ǰ�����

void preOrder(TBTNode *root)
{
    if(root!= nullptr)
    {
        TBTNode *p=root;
        while(p!=nullptr)
        {
            while(p->ltag==0)
            {
                Visit(p);
                p = p->lchild;
            }
            Visit(p);
            p= p->rchild;
        }
    }
}


//�����������������Ļ����ϣ��������

void InOrder(TBTNode *root)
{
    for(TBTNode *p=First(root);p!= nullptr;p=Next(p))
        Visit(p);
}



int main()
{
    TBTNode *root;

    printf("����������(δ������):\n");
    createBinaryTree(root);
    printf("�Դ����Ķ�������������������:\n");
    createInThread(root);
    printf("���������\n");
    InOrder(root);

    printf("----------------\n");

    printf("ʹ��ǰ����������������\n");
    createPreThread(root);
    preOrder(root);

    cout<<endl;
    cout<<"  "<<endl;

}