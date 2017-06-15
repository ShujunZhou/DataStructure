/*************************************************************************
	>通过只调整指针（而不是数据）来交换两个相邻的元素（双链表）
 ************************************************************************/
# include <stdio.h>
# include <stdlib.h>

struct Node;
typedef struct Node * Position;
typedef Position List;

List CreateDoubleList(int a[]);
void SwapWithNext(Position P, List L);

struct Node
{
	int Data;
	List Prev;
	List Next;
};

int main(void)
{
	int i = 0;

	int a[20];
	for (i = 0; i < 20; i++)
	{
		a[i] = 2 * i + 1;
	}
	List L = CreateDoubleList(a);
	SwapWithNext(L->Next->Next, L);

	while (L->Next != NULL)
	{
		printf("%d\t", L->Next->Data);
		L = L->Next;
	}

	return 0;
}

List CreateDoubleList(int a[])
{
	int i = 0;
	List Temp = NULL;
	List Next = NULL;

	List L = (List)malloc(sizeof(struct Node));
	if (NULL == L) 
	{
		exit(-1);
	}
	L->Prev = NULL;
	Temp = L;

	for (i = 0; i < 20; i++)
	{
		Next = (List)malloc(sizeof(struct Node));
		if (NULL == Next)
		{
			exit(-1);
		}
		Next->Data = a[i];
		Temp->Next = Next;
		Next->Prev = Temp;
		Temp = Next;
		Temp->Next = NULL;
	}
	Temp = NULL;
	Next = NULL;

	return L;
}

void SwapWithNext(Position P, List L)
{
	Position AfterP = P->Next;
	Position BeforeP = P->Prev;

	//先处理前驱节点
	BeforeP->Next = AfterP;
	P->Next = AfterP->Next;
	AfterP->Next = P;

	//再处理后去节点
	P->Next->Prev = P;
	AfterP->Prev = BeforeP;
	P->Prev = AfterP;
}
