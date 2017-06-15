# include <stdio.h>
# include <stdlib.h>

#ifndef _Tree_H

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

SearchTree MakeEmpty(SearchTree T);
Position Find(int X, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(int X, SearchTree T);
SearchTree Delete(int X, SearchTree T);
int Retrieve(Position P);
void PrintSearchTree(SearchTree T);

#endif /* _Tree_H */

struct TreeNode
{
	int data;
	SearchTree Left;
	SearchTree Right;
};

int main(void)
{
	SearchTree sTree = NULL;
	
	sTree = Insert(10, Insert(12, Insert(11, sTree)));
	PrintSearchTree(sTree);

	return 0;
}

SearchTree MakeEmpty(SearchTree T)
{
	if (T != NULL)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}

Position Find(int X, SearchTree T)
{
	if (T == NULL)
	{
		return NULL;
	}
	else if (X < T->data)
	{
		return Find(X, T->Left);
	}
	else if (X > T->data)
	{
		return Find(X, T->Right);
	}

	return T; 
}

Position FindMin(SearchTree T)
{
	if (T == NULL)
	{
		return NULL;
	}
	else if (T->Left == NULL)
	{
		return T;
	}
	else
		return FindMin(T->Left);
}

Position FindMax(SearchTree T)
{
	if (T == NULL)
	{
		return NULL;
	}
	else if (T->Right == NULL)
	{
		return T;
	}
	else
	  return FindMax(T->Right);
}

SearchTree Insert(int X, SearchTree T)
{
	if (T == NULL)
	{
		T = (SearchTree)malloc(sizeof(struct TreeNode));
		if (T == NULL)
		{
			printf("Out of Space!!!");
			exit(-1);
		}
		T->data = X;
		T->Left = T->Right = NULL;
	}
	else if (X < T->data)
	{
		T->Left = Insert(X, T->Left);
	}
	else if (X > T->data)
	{
		T->Right = Insert(X, T->Right);
	}

	return T;
}

SearchTree Delete(int X, SearchTree T)
{
	Position TmpCell;

	if (T == NULL)
	{
		return NULL;
	}
	else if (X < T->data)
	{
		T->Left = Delete(X, T->Left);
	}
	else if (X > T->data)
	{
		T->Right = Delete(X,T->Right);
	}
	//以下情况均处理的是已找到要删除的节点，T即为当前需要删除的节点，
	//所以需要考虑当前节点的左右子树情况，根据不同情况，做出不同的处理
	else if (T->Left && T->Right)//具有两个儿子的节点
	{
		TmpCell = FindMin(T->Right);//确定当前节点右子树中的最小值节点
		T->data = TmpCell->data;//最小值节点的值赋值给需要删除的节点的值
		T->Right = Delete(T->data, T->Right);//这一步整体实质是一次查找，最小值节点不可能有左儿子
	}
	else//具有单儿子的节点或者是树叶
	{
		TmpCell = T;

		if (T->Left == NULL)
		{
			T = T->Right;
		}
		else if (T->Right == NULL)
		{
			T = T->Left;
		}
		free(TmpCell);
	}

	return T;
}

int Retrieve(Position P)
{
	if (P != NULL)
	  return P->data;
	else
	{
		printf("不存在此位置！！");
		return 0;
	}

}

void PrintSearchTree(SearchTree T)
{
	if (T)
	{
		PrintSearchTree(T->Left);
		printf("%d\n", T->data);
		PrintSearchTree(T->Right);
	}
}
