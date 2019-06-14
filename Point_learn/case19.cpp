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



//����������
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
    printf("���ȴ���������:\n");
    BTnode root;
    createBinaryTree(root);
    printf("�����������ɹ�\n");
    cout<<endl;
    
    printf("��������Ŀ��:\n");
    printf("%d\n",maxNode(root));
    
    printf("Function dead");

}