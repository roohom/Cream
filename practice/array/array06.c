//
// Created by roohom on 2018/11/6.
//
//二维数组的初始化
#include <stdlib.h>
#include <stdio.h>

main()
{
    int a[3][5] = {{80,61,59,85,76},{75,65,63,87,77},{92,71,70,90,85}};
    int b[3] = {0,0,0},i,j,s=0;
    float aver;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 5; j++) {
            s+=a[i][j];
        }
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 5; j++) {
            b[i]+=a[i][j];
        }
        printf("Average for student %d is %d\n", i+1,b[i]/5);
    }
    aver = s/15.0;
    printf("Total average is: %6.2f \n",aver);
}