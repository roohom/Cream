// case09.cpp
// Author:roohom<roohom@qq.com>
// Created by roohom on 2019/2/23.
// 2019/2/23 20:07

//顺序队的基本操作


#include <stdio.h>
#include <malloc.h>
#define maxsize 100

//定义一个顺序栈
typedef struct {
    int data[maxsize];
    int top;
}SqStack;

//栈的初始化
void initStack(SqStack &st)
{
    st.top=-1;
}

//栈的销毁
void delStack(SqStack &st)
{
    st.top=-1;
}

//判断栈是否为空

int isEmptyStack(SqStack &st)
{
    if(st.top==-1)
    {
        return 1;
    }
    else
        return 0;
}

//入栈操作

int inStack(SqStack &st, int x)
{
    if (maxsize - 1 == st.top)             //栈满了继续入栈就会上溢
        return 0;
    ++(st.top);
    st.data[st.top]=x;
    return 1;
}

//出栈操作
int outStack(SqStack &st,int m)
{
    if(st.top==-1)                         //栈空了继续出战就会下溢
        return 0;
    m = st.data[st.top];
    --st.top;
    printf("出栈的元素为:%d\n",m);
    return 1;
}

int main(){
    SqStack L;
    initStack(L);
    printf("将元素1，2，3，4，5入栈:\n");
    inStack(L,1);
    inStack(L,2);
    inStack(L,3);
    inStack(L,4);
    inStack(L,5);
    printf("入栈完毕，现在检查栈是否为空,结果是:\n");
    if(isEmptyStack(L)==0)
        printf("否\n");
    else
        printf("是\n");
    printf("现在进行出栈操作:\n");
    outStack(L,0);
    outStack(L,0);
    outStack(L,0);
    printf("操作完毕！\n");
    delStack(L);
}