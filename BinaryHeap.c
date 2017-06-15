# include <stdio.h>
# include <stdlib.h>
# define MinPQSize 5  //定义二叉堆的最小容量
# define MinData 3    //定义二叉堆的最小数据

#ifndef _BinHeap_H

struct HeapStruct;
typedef struct HeapStruct *PriorityQueue;

PriorityQueue Initialize(int MaxElements);
void Destroy(PriorityQueue H);
void MakeEmpty(PriorityQueue H);
void Insert(int X, PriorityQueue H);
int DeleteMin(PriorityQueue H);
int FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
int IsFull(PriorityQueue H);

#endif

struct HeapStruct
{
    int Capacity; //堆的最大值
    int Size;     //堆的大小
    int *Data;    //数组
};

int main(void)
{
    int i;

    PriorityQueue H = Initialize(20);
    Insert(25, H);
    Insert(16, H);
    Insert(9, H);
    Insert(64, H);
    Insert(46, H);
    Insert(3, H);
    Insert(32, H);
    Insert(46, H);

    for (i = 1; i <= H->Size; i++)
    {
        printf("%d\t", H->Data[i]);
    }

    printf("\n----------最小元素-------\n");
    printf("%d\t", FindMin(H));
    DeleteMin(H);
    printf("\n----------最小元素-------\n");
    printf("%d\t", FindMin(H));

    MakeEmpty(H);
    Destroy(H);

    return 0;
}

//优先队列的初始化
PriorityQueue Initialize(int MaxElements)
{
    PriorityQueue H;

    if (MaxElements < MinPQSize)
    {
        printf("Priority queue is too small");
        exit(-1);
    }

    H = (PriorityQueue)malloc(sizeof(struct HeapStruct));
    if (NULL == H)
    {
        exit(-1);
    }

    H->Data = (int *)malloc(sizeof(int) * (MaxElements + 1));
    if (NULL == H->Data)
    {
        exit(-1);
    }

    H->Capacity = MaxElements;
    H->Size = 0;
    H->Data[0] = MinData;//数组的第一个位置保存二叉堆的最小值

    return H;
}

/*
 * 为将一个元素X插入到堆中，我们在下一个空闲位置创建一个空穴，否则该树将不是全树
 * 如果X可以放在该空穴中并不破坏堆的序，那么插入完成。否则，我们把空穴的父节点
 * 上的元素移入该空穴中，这样，空穴就朝着根的方向上行一步。继续该过程直到X能被放入空穴中为止。
 * */
void Insert(int X, PriorityQueue H)
{
    int i;

    if (IsFull(H))
    {
        printf("Priority queue is full");
        return;
    }

    for (i = ++H->Size; H->Data[i / 2] > X; i /= 2)
    {
        H->Data[i] =  H->Data[i / 2];
    }
    H->Data[i] = X;
}

int DeleteMin(PriorityQueue H)
{
    int i, Child;
    int MinElement, LastElement;
 
    if (IsEmpty(H))
    {
        printf("Priority queue is empty");
        return H->Data[0];
    }
    MinElement = H->Data[1];
    LastElement = H->Data[H->Size--];

    for (i = 1; i * 2 <= H->Size; i = Child)
    {
        Child = i * 2;
        if (Child != H->Size && (H->Data[Child + 1] < H->Data[Child]))
        {
            Child++;
        }
        if (LastElement > H->Data[Child])
        {
            H->Data[i] = H->Data[Child];
        }
        else
        {
            break;
        }
    }
    H->Data[i] = LastElement;

    return MinElement;
}

int IsEmpty(PriorityQueue H)
{
    if (H->Size == 0)
    {
        return 1;
    }
    return 0;
}

int IsFull(PriorityQueue H)
{
    if (H->Size == H->Capacity)
    {
        return 1;
    }
    return 0;
}

void Destroy(PriorityQueue H)
{
    if (!IsEmpty(H))//先判断队列是否为空
    {
        free(H->Data);
        H->Data =NULL;
        free(H);
        H = NULL;
    }
}

void MakeEmpty(PriorityQueue H)
{
    if (!IsEmpty(H))
    {
        H->Size = 0;
    }
    else
    {
        printf("Priority is Empty");
        return;
    }
}

int FindMin(PriorityQueue H)
{
    if (!IsEmpty(H))
    {
        return H->Data[1];
    }
    else
    {
        printf("Priority is Empty");
        return -1;
    }
}

