// case18.cpp
// Author:roohom<roohom@qq.com>
// Created by roohom on 2019/5/26.
// 2019/5/26 23:11
//二叉树的链式存储结构


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
    if(ch == '#')     //如果到了叶子节点，接下来的左、右子树分别赋值为0
    {
        p = nullptr;
    }
    else
    {
        //p = (BTnode)malloc(sizeof(BTnode));          不能成功运行
        p = (BTNode *)malloc(sizeof(BTNode));
        //p = new BTNode;
        p->data = ch;
        createBinaryTree(p->lchild);  //递归创建左子树
        createBinaryTree(p->rchild);  //递归创建右子树
    }
}


int Visit(BTnode p)
{
    cout<<p->data<<" ";
}

//先序遍历
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

//后序遍历
void inorder(BTNode *p)
{
    if(p!= nullptr)
    {
        inorder(p->lchild);
        Visit(p);
        inorder(p->rchild);
    }
}

//后序遍历
void postorder(BTNode *p)
{
    if(p!= nullptr)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        Visit(p);
    }
}



int main()
{
    printf("Let`s begin!\n");
    BTnode root;
    createBinaryTree(root);
    printf("二叉树建立成功\n");
    cout<<endl;

    printf("先序遍历访问二叉树的每个节点：\n");
    preorder(root);
    cout<<endl;

    printf("中序遍历访问二叉树的每个节点：\n");
    inorder(root);
    cout<<endl;

    printf("后序遍历访问二叉树的每个节点：\n");
    postorder(root);
    cout<<endl;

    printf("访问完毕！");

}