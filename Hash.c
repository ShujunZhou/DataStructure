# include <stdio.h>
# include <stdlib.h>
# define minTableSize 29

# ifndef _HashSep_H

typedef unsigned int Index;
struct ListNode;
typedef struct ListNode *Position;
struct HashThl;
typedef struct HashThl *HashTable;

Index hash(const char *Key, int TableSize);
HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
Position Find(int Key, HashTable H);
void Insert(int Key, HashTable H);
int Retrieve(Position P);

#endif /* _HashSep_H */

struct ListNode
{
	int Data;
	Position Next;
};

typedef Position List;

struct HashThl
{
	int TableSize;
	List * TheLists;
};

int main(void)
{
	HashTable Ht = InitializeTable(31);
	Insert(5, Ht);
	Insert(1, Ht);
	Insert(2, Ht);
	Insert(26, Ht);
	Insert(23, Ht);

	printf("%d", Retrieve(Find(26, Ht)));
	DestroyTable(Ht);

	return 0;
}

//一个简单的散列函数(通过关键字计算出一个位置进行数据的存储)
Index Hash(int Key, int TableSize)
{
	return Key % TableSize;//输入的关键字是整数，合理的方法是直接返回(Key mod TableSize)
}

HashTable InitializeTable(int TableSize)//分离链接散列表的初始化
{
	int i = 0;
	HashTable H = NULL;
	
	if (TableSize < minTableSize)
	{
		printf("Table size too small");
		return NULL;
	}
	
	H = (HashTable)malloc(sizeof(struct HashThl));
	if (H == NULL)
	{
		exit(-1);
	}
	H->TableSize = TableSize;

	H->TheLists = (List *)malloc(sizeof(List) * TableSize);
	if (H->TheLists == NULL)
	{
		exit(-1);
	}

	for (i = 0; i < TableSize; i++)
	{
		H->TheLists[i] = (List)malloc(sizeof(struct ListNode));
		if (H->TheLists[i] == NULL)
		{
			exit(-1);
		}
		else
		{
			H->TheLists[i]->Next = NULL;
		}
	}

	return H;
}

Position Find(int Key, HashTable H)
{
	Position P = NULL;
	List L = NULL;

	L = H->TheLists[Hash(Key, H->TableSize)];
	P = L->Next;

	while (P != NULL && P->Data != Key)
	{
		P = P->Next;
	}

	return P;
}

void Insert(int Key, HashTable H)
{
	Position Pos, NewCell = NULL;
	List L = NULL;

	Pos = Find(Key, H);

	if (Pos == NULL)//若表中无此元素，则进行插入操作
	{
		NewCell = (List)malloc(sizeof(struct ListNode));
		if (NewCell == NULL)
		{
			exit(-1);
		}
		else
		{
			/*
			 * 将元素插入到表的前端
			 * */
			L = H->TheLists[Hash(Key, H->TableSize)];
			NewCell->Data = Key;
			NewCell->Next = L->Next;
			L->Next = NewCell;
		}
	}
}

void DestroyTable(HashTable H)
{
	if (H == NULL)
	{
		printf("Please create HashTable");
	}
	else 
	{
		free(H->TheLists);
		free(H);
	}
}

int Retrieve(Position P)
{
	if (P == NULL)
	{
		return -1;
	}

	return P->Data;
}
