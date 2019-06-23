// case18.cpp
// Author:roohom<roohom@qq.com>
// Created by roohom on 2019/5/26.
// 2019/5/26 23:11
//二叉树的链式存储结构


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

//中序遍历
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


//计算树的深度
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

//统计树的节点数目
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

//先序输出序列中第k个节点的值(k<=节点数)
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

//改成中序或者后续遍历
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

//二叉树的层次遍历

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

    printf("下面计算树的深度:\n");
    printf("树的深度是：%d\n",getDepth(root));

    printf("统计树的节点数目为:%d\n",getNode(root));

    printf("请输入你想要的第k个节点:");
    int k;
    cin>>k;
    printf("这是采用先序遍历得到的结果:" );
    trave(root,k);

    printf("下面使用层次遍历打印二叉树的各个节点:\n");
    level(root);

    printf("访问完毕！");

}