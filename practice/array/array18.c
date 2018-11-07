//
// Created by roohom on 2018/11/7.
//

// 找出矩阵中每行中最大的数，作为另一个数组的元素

#include <stdio.h>

int main(void)
{
    int a[][4] = {3,16,87,65,4,32,11,108,10,25,12,27};
    int b[3],i,j,m;
    for (i = 0; i <= 2; i++) {                    //对每行的元素进行比较，找出最大的值并赋值给m
        m = a[i][0];
        for (j = 0; j <= 3; j++) {
            if(a[i][j]>m)
                m=a[i][j];
        b[i] = m;
        }
    }
    printf("\nArray a:\n");
    for (i = 0; i <=2 ; i++) {                    // 打印数组a中的每个值
        for (j = 0; j <=3 ; j++) {
            printf("%5d", a[i][j]);
        }
        printf("\n");
    }
    printf("\nArray b:\n");
    for (i = 0; i <=2 ; i++) {                    //打印数组b中的每个值
        printf("%5d",b[i]);
    }
}