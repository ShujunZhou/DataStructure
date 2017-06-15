# include <stdio.h>
# include <stdlib.h>

struct StackRecord;
typedef struct StackRecord *Stack;

int IsEmpty(Stack s);
int IsFull(Stack s);
Stack CreateStack(int MaxStackSize);
void MakeEmpty(Stack s);
void Push(int x, Stack s);
int Top(Stack s);
void Pop(Stack s);
int TopAndPop(Stack s);
void DisposeStack(Stack s);

# define EmptyTOS (-1)
# define MinStackSize (5)

struct StackRecord
{
    int Capacity;
    int TopOfStack;
    int * Array;
};

int main(void)
{
    int i;
    Stack s = CreateStack(10);

    for (i = 0; i < 10; i++)
    {
        Push(2 * i, s);
    }

    while (!IsEmpty(s))
    {
        printf("%d\t", Top(s));
        Pop(s);
    }
    DisposeStack(s);
    s = NULL;
}

Stack CreateStack(int MaxStackSize)
{
    Stack s;

    if (MaxStackSize < MinStackSize)
    {
        printf("Stack is too small");
        exit(-1);
    }

    s = (Stack)malloc(sizeof(struct StackRecord));
    if (s == NULL)
    {
        exit(-1);
    }

    s->Array = (int *)malloc(sizeof(int) * MaxStackSize);
    if (s->Array == NULL)
    {
        exit(-1);
    }
    s->Capacity = MaxStackSize;
    MakeEmpty(s);

    return s;
}

void MakeEmpty(Stack s)
{
    s->TopOfStack = EmptyTOS;//将TopOfStack置为-1
}

int IsEmpty(Stack s)
{
    if (s->TopOfStack == EmptyTOS)
    {
        return 1;
    }
    return 0;
}

void Push(int x, Stack s)
{
    if (IsFull(s))
    {
        printf("Stack isfull!!");
        return;
    }
    else
    {
        s->Array[++s->TopOfStack] = x;
    }

}

int Top(Stack s)
{
    if (!IsEmpty(s))
    {
        return s->Array[s->TopOfStack];
    }
    else
    {
        printf("Empty Stack!!!");
        return 0;
    }
}

int TopAndPop(Stack s)
{
    if (!IsEmpty(s))
    {
        return s->Array[s->TopOfStack--];
    }
    return 0;
}

void Pop(Stack s)
{
    if (IsEmpty(s))
    {
        printf("Empty Stack!!!");
    }
    else
    {
        s->TopOfStack--;
    }
}

int IsFull(Stack s)
{
    if (s->Capacity == s->TopOfStack)
    {
        return 1;
    }
    return 0;
}

void DisposeStack(Stack s)
{
    if (s != NULL)
    {
        free(s->Array);
        s->Array = NULL;
        free(s);
        s = NULL;
    }
}
