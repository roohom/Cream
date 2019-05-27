// case18.cpp
// Author:roohom<roohom@qq.com>
// Created by roohom on 2019/5/26.
// 2019/5/26 23:11
//����������ʽ�洢�ṹ


#include <stdio.h>
#include <malloc.h>
#include <iostream>
using namespace std;

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

    printf("������ϣ�");

}