//
// Created by roohom on 19-6-22.
//

//线索二叉树
#include <stdio.h>
#include <malloc.h>
#include <iostream>
#include <search.h>

using namespace std;

#define maxsize 15


typedef struct TBTNode
{
    char data;
    int ltag, rtag;         //线索标记
    struct TBTNode *lchild;
    struct TBTNode *rchild;
}TBTNode;



void Visit(TBTNode *p)
{
    cout<<p->data<<endl;
}



//建立二叉树
void createBinaryTree(TBTNode *&p)
{
    char ch;
    cin>>ch;
    if(ch == '#')     //如果到了叶子节点，接下来的左、右子树分别赋值为0
    {
        p = nullptr;
    }
    else
    {
        p = (TBTNode *)malloc(sizeof(TBTNode));
        p->data = ch;
        createBinaryTree(p->lchild);  //递归创建左子树
        createBinaryTree(p->rchild);  //递归创建右子树
    }
}


//通过中序遍历对二叉树进行线索化
void InThread(TBTNode *p,TBTNode *&pre)
{
    if (p!= nullptr)
    {
        InThread(p->lchild,pre);               //递归，左子树线索化
        if(p->lchild!= nullptr)
        {
            p->lchild = pre;                   //建立当前节点的前驱线索
            p->ltag=1;
        }
        if(pre!=nullptr && pre->rchild==nullptr)//
        {
            pre->rchild = p;                   //建立当前节点的后继线索
            pre->rtag = 1;
        }
        pre = p;                               //pre指向当前的p，作为p将要指向的下一个节点的前驱节点指示指针
        p= p->rchild;                          //p指向一个新的节点，开始重复操作
        InThread(p->rchild,pre);                       //递归，右子树线索化
    }
}

//通过中序遍历建立中序线索化二叉树

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


//前序线索二叉树
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


//遍历中序线索化二叉树
//求以p为根的中序线索二叉树中，中序序列下的第一个节点
TBTNode *First(TBTNode *p)
{
    while(p->ltag==0)
    {
        p=p->lchild;
    }
    return p;
}

//求在中序线索二叉树中，节点p在中序下的后继节点
TBTNode *Next(TBTNode *p)
{
    if(p->rtag==0)
        return First(p->rchild);
    else
        return p->rchild;
}

//在前序线索二叉树的基础上执行前序遍历

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


//在中序线索二叉树的基础上，中序遍历

void InOrder(TBTNode *root)
{
    for(TBTNode *p=First(root);p!= nullptr;p=Next(p))
        Visit(p);
}



int main()
{
    TBTNode *root;

    printf("创建二叉树(未线索化):\n");
    createBinaryTree(root);
    printf("对创建的二叉树进行中序线索化:\n");
    createInThread(root);
    printf("中序遍历：\n");
    InOrder(root);

    printf("----------------\n");

    printf("使用前序线索化二叉树：\n");
    createPreThread(root);
    preOrder(root);

    cout<<endl;
    cout<<"  "<<endl;

}