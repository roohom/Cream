//
// Created by roohom on 2018/11/7.
//

#include <stdio.h>

int main(void)
{
    int i,j,p,q,s,n,a[11]={127,3,6,28,41,25,63,24,1,2};
    for(i=0;i<10;i++)                               /*    排        序     */
    {
        p=i;q=a[i];
        for(j=i+1;j<10;j++) {
            if (q < a[j]) { p = j, q = a[j]; }
        }
        if(p != i){
            s = a[i];
            a[i] = a[p];
            a[p] = s;
        }
        printf("%d ", a[i]);
    }
    printf("\nEnter a number:\n");                  /*    插  入  数  字    */
    scanf("%d", &n);

    for(i=0;i<10;i++)                               /*    再  次  排  序    */
    {
        if(n>a[i])
        {
            for(s=9;s>=i;s--)
                a[s+1]=a[s];
            break;
        }
    }
    a[i]=n;
    for(i=0;i<10;i++)
        printf("%d ", a[i]);
    printf("\n");
}