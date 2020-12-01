#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct SNode *Stack;
struct SNode
{
    ElementType Data;
    Stack Next;
};


Stack CreateStack();
int IsEmpty(Stack s);
void Push(Stack s, ElementType item);
ElementType Pop(Stack s);

Stack CreateStack()
{
    Stack S;
    S = (Stack)malloc(sizeof(struct SNode));
    s->Next = NULL;
    return S;
}

int IsEmpty(Stack s)
{
    return (s->Next == NULL);
}

void Push(Stack s, ElementType item)
{
    Stack Tmp;
    Tmp = (Stack)malloc(sizeof(struct SNode));
    Tmp->Data = item;
    Tmp->Next = s->Next;
    s->Next = Tmp;
}

ElementType Pop(Stack s)
{
    Stack First;
    ElementType TopElem;
    if(IsEmpty(s))
    {
        printf("堆栈空");
        return NULL;
    }
    else
    {
        First = s->Next;
        s->Next = First->Next;
        TopElem = First->Data;
        free(First);
        return TopElem;
    }    
}