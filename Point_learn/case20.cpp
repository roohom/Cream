//
// Created by roohom on 19-6-22.
//

//二叉树深度优先遍历算法的非递归实现
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


void Visit(BTNode *p)
{
    cout<<p->data<<endl;
}





//建立二叉树
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




void preOrderNoneRecursion(BTNode *bt)
{
    if(bt!= nullptr)
    {
        BTNode *Stack[maxsize];
        int top=-1;
        BTNode *p;
        Stack[++top] = bt;
        while(top-1)
        {
            p = Stack[top-1];
            Visit(p);
            if(p->rchild!= nullptr)
            {
                Stack[++top] = p->rchild;
            }
            if(p->lchild!= nullptr)
                Stack[top++] = p->lchild;
        }
    }
}


void inOrderNoneRrcursion(BTNode *bt)
{
    if(bt!= nullptr)
    {
        BTNode *Stack[maxsize] ;
        int top=-1;
        BTNode *p;
        p = bt;
        while(top!=-1||p!=nullptr)
        {
            while(p!=nullptr)
            {
                Stack[++top]=p;
                p=p->lchild;
            }
            if(top!=-1)
            {
                p=Stack[top-1];
                Visit(p);
                p=p->rchild;
            }
        }
    }
}


void postOrderNoneRecursion(BTNode *bt)
{
    if(bt!=nullptr)
    {
        BTNode *Stack1[maxsize]; int top1=-1;
        BTNode *Stack2[maxsize]; int top2=-1;
        BTNode *p = nullptr;
        Stack1[++top1] = bt;
        while(top1 != -1)
        {
            p = Stack1[top1--];
            Stack2[++top2] = p;
            if(p->lchild != nullptr)
                Stack1[++top1] = p->rchild;
            if(p->rchild != nullptr)
                Stack1[++top1] = p->rchild;
        }
        while(top2 != -1)
        {
            p = Stack2[top2--];
            Visit(p);
        }
    }
}


int main()
{
    printf("Let`s begin!\n");
    printf("首先创建二叉树:\n");
    BTnode root;
    createBinaryTree(root);
    printf("二叉树建立成功\n");
    cout<<endl;

    printf("先序遍历:\n");
    preorder(root);
    cout<<"  "<<endl;

    printf("先序遍历非递归实现打印输出:\n");
    preOrderNoneRecursion(root);
    cout<<"   "<<endl;

    printf("中序遍历非递归实现打印输出:\n");
    inOrderNoneRrcursion(root);
    cout<<"   "<<endl;

    printf("后序遍历非递归实现打印输出:\n");
    postOrderNoneRecursion(root);
    cout<<"   "<<endl;

    printf("Function dead");

}


