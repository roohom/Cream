// case19.cpp
// Author:roohom<roohom@qq.com>
// Created by roohom on 2019/6/14.
// 2019/6/14 22:27

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



typedef struct
{
    BTNode *p;
    int lno;
}St;



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




int maxNode(BTNode *b){

    St que[maxsize];
    int front, rear;
    int  Lno,i, j, n, max;
    front = rear = 0;
    BTNode *q;
    if(b!= nullptr)
    {
        ++rear;
        que[rear].p = b;
        que[rear].lno = 1;
        while(front != rear)
        {
            ++front;
            q = que[front].p;
            Lno = que[front].lno;
            if(q->lchild!=nullptr)
            {
                ++rear;
                que[rear].p = q->lchild;
                que[rear].lno = Lno +1;
            }
            if(q->rchild!= nullptr)
            {
                ++rear;
                que[rear].p = q->rchild;
                que[rear].lno = Lno+1;
            }
        }

        max = 0;
        for (i = 1; i <= Lno; ++i)
        {
            n = 0;
            for (j = 1; j <= rear; ++j)

                if (que[j].lno == i) {
                    ++n;
                }
                if (max < n) {
                    max = n;
                }
        }
        return max;
    }
    else return 0;

}




int main()
{
    int i =0;
    printf("Let`s begin!\n");
    printf("首先创建二叉树:\n");
    BTnode root;
    createBinaryTree(root);
    printf("二叉树建立成功\n");
    cout<<endl;
    
    printf("求二叉树的宽度:\n");
    printf("%d\n",maxNode(root));
    
    printf("Function dead");

}