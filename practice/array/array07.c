//
// Created by roohom on 2018/11/7.
//

// 生成一个五行五列的矩阵，主对角线上的数字是1，其余为0

#include <stdio.h>

int main(void)
{
    int a[5][5], i, j;
    for(i=0;i<5;i++)                 //行
    {
        for(j=0;j<5;j++)             //列
        {
            if (i==j)
                a[i][j]=1;
            else
                a[i][j]=0;
        }
    }
    for (int i = 0; i < 5; i++) {    //ROW
        for (j = 0; j < 5; j++) {    //COLUMN
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
}