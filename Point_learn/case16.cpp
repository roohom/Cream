// case16.cpp
// Author:roohom<roohom@qq.com>
// Created by roohom on 2019/3/10.
// 2019/3/10 9:34

//矩阵的常规操作

#include <stdio.h>
#include <malloc.h>
#define maxsize 5

//矩阵的转置
void trsmat(int A [][maxsize],int B[][maxsize],int m, int n)
{
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j)
            B[j][i]=A[i][j];                     //关键代码
    }
}

//矩阵的相加
void addmat(int C[][maxsize],int A[][maxsize],int B[][maxsize],int m,int n)
{
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            C[i][j]= A[i][j]+B[i][j];
        }
    }
}

//矩阵相乘
void mutmat(int C[][maxsize],int A[][maxsize],int B[][maxsize],int m,int n,int k)
{
    for(int i=0;i<m;++i)
        for(int j=0;j<k;++j){
            C[i][j]=0;
            for(int l=0;l<n;++l)
                C[i][j]+=A[i][j]*B[i][j];
        }
}

//矩阵的打印
int printArray(int A[][maxsize],int m,int n)
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
    int A[4][maxsize]={{1, 0, 0, 0, 0},
                       {2, 2, 0, 0, 0},
                       {3, 3, 3, 0, 0},
                       {4, 4, 4, 4, 1}};
    int E[4][maxsize]={{1, 2, 3, 4, 5},
                       {0, 2, 3, 4, 5},
                       {0, 0, 3, 4, 5},
                       {0, 0, 0, 4, 5}};
    int B[maxsize][5];
    int C[5][5];
    int D[5][5];
    printf("对矩阵A进行转置得B:\n");
    trsmat(A,B,4,5);
    printArray(B,5,4);
    printf("矩阵的相加得C:\n");
    addmat(C,A,E,4,5);
    printArray(C,4,5);
    printf("\n");
    printf("矩阵的相乘得D:\n");
    mutmat(D,A,B,4,4,5);
    printf("\n");
    printArray(D,4,4);
    printf("\n");
}