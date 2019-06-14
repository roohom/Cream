// case18.cpp
// Author:roohom<roohom@qq.com>
// Created by roohom on 2019/5/26.
// 2019/5/26 23:11
//����������ʽ�洢�ṹ


#include <stdio.h>
#include <malloc.h>
#include <iostream>
using namespace std;
#define maxsize 15

typedef struct BTNode
{
    char data;

    struct BTNode *lchild;
    struct BTNode *rchild;
}BTNode, *BTnode;


void createBinaryTree(BTnode &p)
{
    char ch;
    cin>>ch;
    if(ch == '#')     //�������Ҷ�ӽڵ㣬�����������������ֱ�ֵΪ0
    {
        p = nullptr;
    }
    else
    {
        //p = (BTnode)malloc(sizeof(BTnode));          ���ܳɹ�����
        p = (BTNode *)malloc(sizeof(BTNode));
        //p = new BTNode;
        p->data = ch;
        createBinaryTree(p->lchild);  //�ݹ鴴��������
        createBinaryTree(p->rchild);  //�ݹ鴴��������
    }
}


int Visit(BTnode p)
{
    cout<<p->data<<" ";
}

//�������
void preorder(BTnode p)
{
    if(p!= nullptr)
    {
        //Visit(p);
        cout<<p->data<<" ";

        preorder(p->lchild);
        preorder(p->rchild);
    }
}

//�������
void inorder(BTNode *p)
{
    if(p!= nullptr)
    {
        inorder(p->lchild);
        Visit(p);
        inorder(p->rchild);
    }
}

//�������
void postorder(BTNode *p)
{
    if(p!= nullptr)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        Visit(p);
    }
}


//�����������
int getDepth(BTNode *p)
{
    int LD,RD;
    if(p== nullptr)
    {
        return 0;
    }
    else
    {
        LD = getDepth(p->lchild);
        RD = getDepth(p->rchild);
        return (LD>RD?LD:RD)+1;
    }
}

//ͳ�����Ľڵ���Ŀ
int i=0;
int getNode(BTnode p)
{
    if(p!= nullptr)
    {
        i++;
        getNode(p->rchild);
        getNode(p->lchild);
    }
    return i;
}

//������������е�k���ڵ��ֵ(k<=�ڵ���)
int n = 0;
void trave(BTnode p, int k)
{
    if(p!= nullptr)
    {
        ++n;
        if(k==n)
        {
            cout<<p->data<<endl;
            return;
        }
        trave(p->lchild, k);
        trave(p->rchild, k);
    }
}

//�ĳ�������ߺ�������
void trave1(BTnode p, int k)
{
    if(p!= nullptr)
    {
        trave(p->lchild, k);
        ++n;
        if(k==n)
        {
            cout<<p->data<<endl;
            return;
        }

        trave(p->rchild, k);
    }
}

void trave2(BTnode p, int k)
{
    if(p!= nullptr)
    {
        trave(p->lchild, k);
        trave(p->rchild, k);
        ++n;
        if(k==n)
        {
            cout<<p->data<<endl;
            return;
        }
        }
}

//�������Ĳ�α���

void level(BTnode p)
{
    int front,rear;
    BTnode que[maxsize];
    front = rear =0;
    BTnode q;
    if(p!= nullptr)
    {
        rear = (rear+1)%maxsize;
        que[rear] = p;
        while(front!=rear)
        {
            front = (front+1)%maxsize;
            q = que[front];
            Visit(q);
            if(q->lchild!= nullptr)
            {
                rear = (rear+1)%maxsize;
                que[rear]=q->lchild;
            }
            if(q->rchild!=nullptr)
            {
                rear = (rear+1)%maxsize;
                que[rear] = q->rchild;
            }
        }
    }
}


int main()
{
    int i =0;
    printf("Let`s begin!\n");
    BTnode root;
    createBinaryTree(root);
    printf("�����������ɹ�\n");
    cout<<endl;

    printf("����������ʶ�������ÿ���ڵ㣺\n");
    preorder(root);
    cout<<endl;

    printf("����������ʶ�������ÿ���ڵ㣺\n");
    inorder(root);
    cout<<endl;

    printf("����������ʶ�������ÿ���ڵ㣺\n");
    postorder(root);
    cout<<endl;

    printf("��������������:\n");
    printf("��������ǣ�%d\n",getDepth(root));

    printf("ͳ�����Ľڵ���ĿΪ:%d\n",getNode(root));

    printf("����������Ҫ�ĵ�k���ڵ�:");
    int k;
    cin>>k;
    printf("���ǲ�����������õ��Ľ��:" );
    trave(root,k);

    printf("����ʹ�ò�α�����ӡ�������ĸ����ڵ�:\n");
    level(root);

    printf("������ϣ�");

}