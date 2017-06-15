# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# define MinTableSize 29

#ifndef _HashQuad_H

typedef unsigned int Index;
typedef Index Position;

struct HashTbl;
typedef struct HashTbl *HashTable;

unsigned int Hash(const char *Key, int TableSize);
HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
Position Find(const char *Key, HashTable);
void Insert(const char *Key, HashTable);
const char *Retrieve(Position P, HashTable H);
HashTable Rehash(HashTable H);

#endif /* _HashQuad_H */

enum KindOfEntry{Legitimate, Empty, Deleted};//列举出三种状态 合法，空，被删除（懒惰删除）

struct HashEntry
{
    char Data[10];
    enum KindOfEntry Info;
};

typedef struct HashEntry Cell;

struct HashTbl
{
    int TableSize;
    Cell *TheCells;
};

int main(void)
{
    HashTable H = InitializeTable(31);
    printf("%p\n", H);
    Insert("sjkakal", H);
//    Insert("qwieowoe", H);
//    Insert("qakkkxc", H);
//    Insert("q;zlc..", H);
//    Insert("x,c. sd0", H);
//    Insert("sdjak", H);
    
    return 0;
}

unsigned int Hash(const char *Key, int TableSize)
{
    unsigned int HashVal = 0;

    while (*Key != '\0')
    {
        HashVal = (HashVal << 5) + *Key++;
    }

    return HashVal % TableSize;
}

HashTable InitializeTable(int TableSize)
{
    HashTable H;
    int i;

    if (TableSize < MinTableSize)
    {
        printf("Table is too small");
        return NULL;
    }

    H = (HashTable)malloc(sizeof(struct HashTbl));
    if (NULL == H)
    {
        exit(-1);
    }

 //   H->TableSize = NextPrime(TableSize);

    H->TheCells = (Cell *)malloc(sizeof(Cell) * H->TableSize);
    if (NULL == H->TheCells)
    {
        exit(-1);
    }

    for (i = 0; i < H->TableSize; i++)
    {
        H->TheCells[i].Info = Empty;
    }

    return H;
}

Position Find(const char *Key, HashTable H)
{
    Position CurrentPos;
    int CollisionNum = 0;

    //根据关键字，调用Hash函数确定位置
    CurrentPos = Hash(Key, H->TableSize);

    //当标记Info的值不为空并且值不相等
    while(H->TheCells[CurrentPos].Info != Empty && strcmp(H->TheCells[CurrentPos].Data, Key))
    {
        //由平方探测解决函数的定义可知F(i) = F(i - 1) + 2 * i -1
        CurrentPos += (2 * ++CollisionNum - 1);

        //如果新的定位越过数组，那么可以通过减去TableSize把它拉回到数组范围内
        if (CurrentPos >= H->TableSize)
        {
            CurrentPos -= H->TableSize;
        }
    }

    return CurrentPos;
}

//定理：如果使用平方探测，且表的大小是素数，
//那么当表至少有一半是空的时候，总能够插入一个新的元素
//如果表元素填的太满，那么操作的运行时间将开始消耗过长，且插入操作可能失败
void Insert(const char *Key, HashTable H)
{
    Position Pos;

    Pos = Find(Key, H);

    if (H->TheCells[Pos].Info != Legitimate)
    {
        H->TheCells[Pos].Info = Legitimate;
        strcpy(H->TheCells[Pos].Data, Key);
    }
}

//再散列，
HashTable Rehash(HashTable H)
{
    int i, OldSize;
    Cell *OldCells;

    OldSize = H->TableSize;
    H = InitializeTable(2 * OldSize);

    for (i = 0; i < OldSize; i++)
    {
        if (H->TheCells[i].Info == Legitimate)
        {
            Insert(OldCells[i].Data, H);
        }
    }

    free(OldCells);

    return H;
}
