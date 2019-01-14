// case08.cpp
// Author:roohom<roohom@qq.com>
// Created by roohom on 2019/1/14.
// 2019/1/14 19:23

/*问题描述：*/
/* 设顺序表用数组A[]表示，表中元素储存在数组下标为0~m+n-1的范围内，前m个元素递增有序，后n个元素也递增有序，设计一算法，使得整个表有序。*/


#include <stdio.h>
#include <malloc.h>

void insElem(int a[],int m, int n)
{
    int i,j;
    int temp;
    for(i=m;i<m+n;++i)
    {
        temp = a[i];              //把表中的第i个元素给temp，然后用temp与表中剩下的m+n-1个元素相比较
        for(j=i-1;j>0 && temp<a[j];--j)
        {
            a[j+1] = a[j];        //如果temp比后面的元素要校，那么把后面的元素挨个儿往后挪一位，从而留出来位置插入temp
        }
        a[j+1] = temp;
    }
}

int main(){
    int a[] = {1,3,5,7,8,23,56,47,25,33,13,79,99,53};
    printf("原来的数组a为:\n");
    for (int j:a) {
        printf("%d ", j);
    }
    insElem(a,9,5);
    printf("\n");
    printf("此时的数组a为:\n");
    for (int i:a) {
        printf("%d ", i);
    }
}