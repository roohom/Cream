// case08.cpp
// Author:roohom<roohom@qq.com>
// Created by roohom on 2019/1/14.
// 2019/1/14 19:23

/*����������*/
/* ��˳���������A[]��ʾ������Ԫ�ش����������±�Ϊ0~m+n-1�ķ�Χ�ڣ�ǰm��Ԫ�ص������򣬺�n��Ԫ��Ҳ�����������һ�㷨��ʹ������������*/


#include <stdio.h>
#include <malloc.h>

void insElem(int a[],int m, int n)
{
    int i,j;
    int temp;
    for(i=m;i<m+n;++i)
    {
        temp = a[i];              //�ѱ��еĵ�i��Ԫ�ظ�temp��Ȼ����temp�����ʣ�µ�m+n-1��Ԫ����Ƚ�
        for(j=i-1;j>0 && temp<a[j];--j)
        {
            a[j+1] = a[j];        //���temp�Ⱥ����Ԫ��ҪУ����ô�Ѻ����Ԫ�ذ���������Ųһλ���Ӷ�������λ�ò���temp
        }
        a[j+1] = temp;
    }
}

int main(){
    int a[] = {1,3,5,7,8,23,56,47,25,33,13,79,99,53};
    printf("ԭ��������aΪ:\n");
    for (int j:a) {
        printf("%d ", j);
    }
    insElem(a,9,5);
    printf("\n");
    printf("��ʱ������aΪ:\n");
    for (int i:a) {
        printf("%d ", i);
    }
}