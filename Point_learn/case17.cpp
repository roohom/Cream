// case17.cpp
// Author:roohom<roohom@qq.com>
// Created by roohom on 2019/3/10.
// 2019/3/10 10:35

#include <stdio.h>
#include <malloc.h>
#include <iostream>
using namespace std;
#define maxsize 4
//三元组表示法
typedef struct
{
    int val;
    int i,j;
}Trimat;


//建立三元组
void creatTrimat(int A[][maxsize],int m,int n, int B[][3])
{
    int k=1;
    for(int i=0;i<m;++i) {
        for (int j = 0; j < n; ++j) {
            if (A[i][j] != 0) {
                B[k][0] = A[i][j];
                B[k][1] = i;
                B[k][2] = j;
                ++k;
            }
        }
        B[0][0] = k - 1;
        B[0][1] = m;
        B[0][2] = n;
    }
}

void print(int B[][3])
{
    int k=1;
    for (int i = 0; i < B[0][1]; ++i) {
        for (int j = 0; j < B[0][2]; ++j) {
            if(i == B[k][1] && j == B[k][2])
            {
                cout<<B[k][0]<<" ";
                ++k;
            }
            else
                cout<<"0 ";
        }
        cout<<endl;

    }
}

int printArray(int A[][3],int m,int n)
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",A[i][j]);
        }
        printf("\n");
    }
}


int main()
{
    printf("给定矩阵A=[0 0 0 1\n"
           "         0 0 3 2\n"
           "         1 0 0 0\n"
           "         0 2 0 0]\n");
    int A[4][4]={{0, 0, 0, 1}, {0, 0, 3, 2}, {1, 0, 0, 0},{0, 2, 0, 0}};
    int B[6][3]={};
    printf("构建三元组:\n");
    creatTrimat(A,4,4,B);
    printf("通过三元组打印A:\n");
    print(B);
    printf("\n");
    printf("打印三元组B:\n");
    printArray(B,6,3);

}
