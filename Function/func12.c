// func12.c
// Created by roohom on 2018/11/10.
// 2018/11/10 16:26

#include <stdio.h>


void scalarMultiply(int matrix[3][5], int scalar);
void displayMatrix(int matrix[3][5]);


int main(void)
{
    int sampleMatrix[3][5] =
            {
                    {7,16,55,13,12},
                    {12,10,52,0,7},
                    {-2,1,2,4,9}
            };
    printf("Original matrix:\n");

    displayMatrix(sampleMatrix);

    scalarMultiply(sampleMatrix,2);

    printf("\nMultiply by 2:\n");
    displayMatrix(sampleMatrix);

    scalarMultiply(sampleMatrix,-1);

    printf("\nThen multiply by -1:\n");

    displayMatrix(sampleMatrix);


}


void scalarMultiply(int matrix[3][5], int scalar)    // 数组乘以一个标量
{
    int row,column;
    for (row = 0; row < 3; row++) {
        for (column = 0; column < 5; column++) {
            matrix[row][column] *= scalar;
        }

    }
}

void displayMatrix(int matrix[3][5])                   // 数组打印显示
{
    int row,column;
    for (row = 0; row < 3; row++) {
        for (column = 0; column < 5; column++) {
            printf("%5i", matrix[row][column]);

        }
        printf("\n");
    }
}