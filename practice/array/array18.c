//
// Created by roohom on 2018/11/7.
//

// �ҳ�������ÿ��������������Ϊ��һ�������Ԫ��

#include <stdio.h>

int main(void)
{
    int a[][4] = {3,16,87,65,4,32,11,108,10,25,12,27};
    int b[3],i,j,m;
    for (i = 0; i <= 2; i++) {                    //��ÿ�е�Ԫ�ؽ��бȽϣ��ҳ�����ֵ����ֵ��m
        m = a[i][0];
        for (j = 0; j <= 3; j++) {
            if(a[i][j]>m)
                m=a[i][j];
        b[i] = m;
        }
    }
    printf("\nArray a:\n");
    for (i = 0; i <=2 ; i++) {                    // ��ӡ����a�е�ÿ��ֵ
        for (j = 0; j <=3 ; j++) {
            printf("%5d", a[i][j]);
        }
        printf("\n");
    }
    printf("\nArray b:\n");
    for (i = 0; i <=2 ; i++) {                    //��ӡ����b�е�ÿ��ֵ
        printf("%5d",b[i]);
    }
}