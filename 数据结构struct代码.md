# 数据结构代码

## 01线性表

###　大纲要求

- 线性表的定义和基本操作

- 线性表的实现

   - 顺序存储结构

   - 链式存储结构

  	- 线性表的应用

### 线性表

- 顺序表

  - ```c++
    //顺序表的结构体定义
    typedef struct
    {
        ElemType elem[MaxSize];          //存放顺序表中的元素
        int length;                      //存放顺序表的长度
    } SqList;
    ```

    

- 单链表

  - 单链表的定义

    ```c++
    typedef struct LNode{
        int data;
        struct LNode *next;
    }SLNode, *List;
    ```

  - 基本操作

    -　打印输出链表

    ```c++
    int DisplayList(List l)
    {
        List p = nullptr;
        p = l->next;                     //初始化为初始节点
        int k = 0;
        while (p)
        {
            printf("%d ", p->data);
            p = p->next;
            k++;
        }
        if (k == 0)
        {
            printf("链表为空");
            return 0;
        }
        printf("\n");
        return 1;
    }
    ```

    - 尾插法建立单链表

      ```c++
      //尾插法建立链表C
      void tailCreatList(SLNode *&C, int a[], int n){
          LNode *s,*r;                          //s用来指向新申请的节点，始终指向终端节点
          int i;
          C = (LNode *)malloc(sizeof(LNode));   //申请内存空间建立链表C
          C->next = nullptr;                        //表示链表为空
          r = C;                                 //r始终指向终端节点
          for(i = 0; i<n; ++i)
          {
              s = (LNode *)malloc(sizeof(LNode));
              s->data = a[i];
              r->next = s;
              r = r->next;
          }
          r->next = nullptr;                         //数组a中所有的元素都已经装入链表中，现在将链表的末尾指针域置为NULL
          printf("链表（尾插法）创建成功！\n");
      }
      ```

    - 头插法建立链表

      ```c++
      //头插法建立链表C
      void headCreatList(SLNode *&C, int a[], int n)
      {
          LNode *s;                               //s用来指向新申请的节点
          int i;
          C = (LNode *)malloc(sizeof(LNode));
          C->next = nullptr;                         //空
          for (i = 0; i < n; ++i) {
              s = (LNode *)malloc(sizeof(LNode));
              s->data = a[i];
              /*头插法关键步骤*/
              s->next = C->next;                  //现在s所指向的新的节点的指针域也指向C指向的节点
              C->next = s;                        //C所指向的节点的指针域使命完成，将指针s与原先的C所指向的节点的指针域连接
          }
          printf("链表（头插法）创建成功！\n");
      
      }
      ```

    - 查找链表

      ```c++
      //查找链表C（带头节点）是否存在一个值为x的节点，若是则删除该节点，并返回1，否则返回0
      int findAndDelElem(SLNode *C, int x)
      {
          LNode *p,*q;
          p = C;
          /*查找部分开始*/
          while(p->next!= nullptr){
              if(p->next->data==x) {
                  break;
              }
              p = p->next;
      
          }
          /*查找部分结束*/
          if(p->next== nullptr)
              return 0;
          else
          {
              /*删除部分开始*/
              q = p->next;
              p->next = p->next->next;
              free(q);
              /*删除部分结束*/
              return 1;
          }
      }
      ```

      

- 双链表

  - 定义

    ```c++
    typedef struct LNode{
        int data;
        struct LNode *prior;
        struct LNode *next;
    }DLNode,*DList;
    ```

  - 基本操作

    - 打印输出

      ```c++
      //输出每个节点的数据
      int displayList(DLNode *L,int n)
      {
          DLNode *p;
          p = L->next;
          int i = 1;
          if(p== nullptr){
              printf("后面没有数据啦！");
              return 0;
          }
          while(p)
          {
              printf("%d", p->data);
              p = p->next;
              ++i;
              if(i<=n)
                  continue;
              else
                  break;
          }
          return 1;
      }
      ```

    - 尾插法建立双链表

      ```c++
      //采用尾插法建立双链表
      void tailCreateList(DLNode *&L, int a[], int n)
      {
          DLNode *s,*r;
          int i;
          L = (DLNode *)malloc(sizeof(DLNode));
          L->prior = nullptr;
          L->next = nullptr;
          r = L;
          for (i = 0; i < n; ++i) {
              s = (DLNode *)malloc(sizeof(DLNode));
              s->data = a[i];
              r->next = s;
              s->prior = r;
              r = s;
          }
          r->next = nullptr;
      
      }
      ```

    - 查找节点

      ```c++
      //查找节点
      
      int findNode(DLNode *C,int x)
      {
          int i=0;
          DLNode *p = C->next;
          while(p!= nullptr)
          {
              ++i;
              if(p->data==x)
              {
                  break;
              }
              p = p->next;
          }
          return i;
      }
      ```

    - 插入节点

      ```c++
      //插入节点
      void insertElem(DLNode *&L,int e, int x)      //p为插入的位置，x为插入的元素值
      {
          DLNode *p,*s;
          s = (DLNode *)malloc(sizeof(DLNode));     //新申请一个节点用来存放要插入的新数据元素
          s->data = x;
          s->prior = nullptr;                       //完成对新数据节点的初始化
          DLNode *i;
          int j=1;
          i = L->next;                              //从初始节点开始
          while(i!= nullptr)
          {
              if(e==j+1)
              {
                  /*插入节点开始*/
                  p = i;
                  s->next = p->next;
                  s->prior = p;
                  p->next = s;
                  s->next->prior = s;
              }
              ++j;
              i = i->next;
          }
      }
      ```

    - 删除节点

      ```c++
      //删除节点
      void delListElem(DLNode *L,int x)
      {
          DLNode *l;
          l = L;
          while(l->next!= nullptr)
          {
              if(l->next->data==x)
                  break;
              l = l->next;
          }
          if(l->next== nullptr)
              return;
          else
          {
              /*删除部分开始*/
              DLNode *p,*q;
              p = l;
              q = p->next;
              p->next = q->next;
              q->next->prior = p;
              free(q);
              /*删除部分结束*/
          }
      }
      ```

      

- 循环链表

## 02栈和队列

### 大纲要求

###　栈和队列的基本概念

###　栈和队列的存储结构、算法与应用

- 顺序栈

  - 定义一个顺序栈

    ```c++
    //定义一个顺序栈
    typedef struct {
        int data[maxsize];
        int top;
    }SqStack;
    ```

    

- 链栈

  - 链栈的定义

    ```c++
    typedef struct LNode
    {
        int data;                             //数据域
        struct LNode *next;                   //指针域
    }LNode;
    ```

    

- 顺序队

  - 顺序列队定义

    ```c++
    typedef struct
    {
        int data[maxsize];
        int front;
        int rear;
    }SqQueue;
    ```

- 链队

  - 队节点类型定义

    ```c++
    typedef struct QNode
    {
        int data;
        struct QNode *next;
    }QNode;
    ```

    

  - 链队类型定义

    ```c++
    typedef struct 
    {
        QNode *front;
        QNode *rear;
    }LiQueue;
    ```

## 03串

###　串数据类型的定义

- 串的定义
- 串的存储结构
- 串的基本操作

### 串的模式匹配算法

- 简单模式匹配算法
- KMP算法
- KMP算法的改进

## 04数组、矩阵和广义表

### 数组

###　矩阵的压缩存储

- 矩阵
- 特殊矩阵和稀疏矩阵

###　广义表

## 05树与二叉树

###  树的基本概念

- 树的定义
- 输的基本术语
- 树的存储结构

###　二叉树

- 定义
- 主要性质
- 存储结构
- 遍历算法
- 便利算法的改进

### 树和森林与二叉树的互相转换

- 树转换为二叉树
- 二叉树转换为树
- 森林转换为二叉树
- 二叉树转换为森林
- 树和森林的遍历

### 树与二叉树的应用

- Huffman树和Huffman编码

## 06图

