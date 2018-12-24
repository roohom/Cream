// ch2.2.c
// Created by roohom on 2018/12/24.
// 2018/12/24 19:45

/*把2英寻转化为英尺*/

#include <stdio.h>
int main(void){
    int feet,fathoms;

    fathoms = 2;
    feet=6*fathoms;
    printf("There are %d feet in %d fathoms!\n",feet, fathoms);
    printf("Yes, i said %d feet!\n", 6*fathoms);
}