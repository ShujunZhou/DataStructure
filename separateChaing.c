# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# define minTableSize 19
# ifndef _HashSep_H

struct ListNode;
typedef struct ListNode *Position;
struct HashTbl;
typedef struct HashTbl *HashTable;

int Hash(const char *Key, int TableSize);
HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
Position Find(const char *Key, HashTable H);
void Insert(const char *Key, HashTable H);
const char *Retrieve(Position P);
void Input(HashTable H);
void Print(HashTable H);

# endif

struct ListNode 
{
    char Data[10];
    Position Next;
};

typedef Position List;

struct HashTbl
{
    int TableSize;
    List *TheLists;
};

int main(void)
{
    HashTable ht = InitializeTable(31);

    Input(ht);
    Print(ht);

    return 0;
}
//一种好的散列函数
int Hash(const char *Key, int TableSize)
{
    unsigned int HashVal = 0;

    while (*Key != '\0')
    {
        HashVal = (HashVal << 5) + *Key++;//等价于HashVal = (HashVal * 32) + *Key++
    }

    return HashVal % TableSize;
}
//输入
void Input(HashTable H)
{
    Insert("shdjflds", H);
    Insert("shdjdks", H);
    Insert("qwwoeiodk", H);
    Insert("shjdall", H);
    Insert("sdklala.,", H);
    Insert("zjjckxkz", H);
    Insert("lsoapdosl", H);
    Insert("klfopap", H);
    Insert("lzopakd", H);
    Insert("mnxlzla", H);
    Insert("1223899", H);
    Insert("  clds;", H);
    Insert("shjs  sjs", H);
}
//打印输出
void Print(HashTable H)
{
    int i;
    List L;
    Position Pos;

    for (i = 0; i < H->TableSize; i++)
    {
        L = H->TheLists[i];
        Pos = L->Next;

        while (NULL != Pos)
        {
            printf("%s---->%d\n", Pos->Data, i);
            Pos = Pos->Next;
        }
    }
}

//初始化
HashTable InitializeTable(int TableSize)
{
    HashTable H;
    int i;

    if (TableSize < minTableSize) 
    {
        printf("Table size is too small");
        return NULL;
    }

    H = (HashTable)malloc(sizeof(struct HashTbl));
    if (NULL == H)
    {
        exit(-1);
    }
    //创建一个List数组
    H->TableSize = TableSize;
    H->TheLists = (List *)malloc(sizeof(Position) * TableSize);
    if (NULL == H->TheLists)
    {
        exit(-1);
    }

    for (i = 0; i < TableSize; i++)
    {
        //新建的节点在多次插入最终为尾节点
        H->TheLists[i] = (List)malloc(sizeof(struct ListNode));
        if (NULL == H->TheLists)
        {
            exit(-1);
        }

        H->TheLists[i]->Next = NULL;
    }

    return H;
}
//查找
Position Find(const char *Key, HashTable H)
{
    Position P;
    List L;

    //获取所要查找元素所在的列表
    L = H->TheLists[Hash(Key, H->TableSize)];

    P = L->Next;

    //注意字符串的比较需要用strcmp(char*, char*),若相等返回0
    while (NULL != P && strcmp(Key, P->Data))
    {
        P = P->Next;
    }

    return P;
}
//插入
void Insert(const char *Key, HashTable H)
{
    Position newPos;
    List L;
    Position Pos = Find(Key, H);

    if (NULL == Pos)
    {
        newPos = (List)malloc(sizeof(struct ListNode));
        if (NULL == newPos)
        {
            exit(-1);
        }

        L = H->TheLists[Hash(Key, H->TableSize)];
        newPos->Next = L->Next;//把要插入的元素放在表的前端
        L->Next = newPos;
        strcpy(newPos->Data, Key);
    }
}
//取回
const char * Retrieve(Position P)
{
    if (NULL == P)
    {
        return NULL;
    }
    return P->Data;
}

void DestroyTable(HashTable H)
{
    if (NULL == H)
    {
        printf("Please create Table");
    }
    else 
    {
        free(H->TheLists);
        free(H);
    }
}
