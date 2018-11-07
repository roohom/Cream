//
// Created by roohom on 2018/11/6.
//

#include <stdio.h>
#include <stdlib.h>

main()
{
    int a[3][5], b[3]={0,0,0},i,j,s=0;
    float aver;
    for(i=0;i<3;i++)
    {
        for(j=0;j<5;j++)
        {
            scanf("%d",&a[i][j]);
            s+=a[i][j];
        }
    }
    for (i = 0; i < 3; i++) {
        for(j=0;j<5;j++){
            b[i]+=a[i][j];
        }
        printf("Average for student %d is %d\n ",i+1, b[i]/5);
    }
    aver=s/15.0;
    printf("Total average is: %6.2f\n ",aver);
    system("pause");
}