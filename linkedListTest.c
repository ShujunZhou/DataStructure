# include <stdio.h>
# include <stdlib.h>

struct Node;
typedef struct Node * Position;
typedef Position List;

List CreateList(int a[]);
void SwapWithNext(Position BeforeP, List L);

struct Node
{
	int Data;
	List Next;
};

int main(void)
{
	int a[20];

	for (int i = 0; i < 20; i++)
	{
		a[i] = 2 * i + 5;
	}
	List L = CreateList(a);

	SwapWithNext(L->Next->Next, L);

	while (L->Next != NULL)
	{
		printf("%d\t", L->Next->Data);
		L = L->Next;
	}

	return 0;
}


List CreateList(int a[])
{
	int i = 0;
	List Next = NULL;
	List Temp = NULL;
	List L = (List)malloc(sizeof(struct Node));
	if (NULL == L) 
	{
		exit(-1);
	}
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
		Temp = Next;
		Temp->Next = NULL;
	}
	Temp = NULL;
	Next = NULL;

	return L;
}

void SwapWithNext(Position BeforeP, List L)
{
	Position P = NULL;
	Position AfterP = NULL;

	P = BeforeP->Next;
	AfterP = P->Next;

	BeforeP->Next = P->Next;
	P->Next = AfterP->Next;
	AfterP->Next = P;
}

