#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100 //maxsize of data array

typedef int ElementType; //define ElementType as int
typedef struct SNode *Stack;
struct SNode
{
    ElementType Data[MAXSIZE];
    int Top; //define the top of stack
};

typedef struct DSNode *DStack;
struct DSNode
{
    ElementType Data[MAXSIZE];
    int Top1; //define the top of stack
    int Top2;
};

Stack CreateStack();
int IsFull(Stack s);
int IsEmpty(Stack s);
void Push(Stack s, ElementType item);
ElementType Pop(Stack s);


Stack D_CreateStack();
int D_IsFull(Stack s);
int D_IsEmpty(Stack s);
void D_Push(Stack s, ElementType item);
ElementType D_Pop(Stack s);

Stack CreateStack()
{
    Stack s;
    s = (Stack)malloc(sizeof(struct SNode));
    s->Top = -1;
    return s;
}

int IsFull(Stack s)
{
    return (s->Top == MAXSIZE - 1);
}

int IsEmpty(Stack s)
{
    return (s->Top == -1);
}

void Push(Stack s, ElementType item)
{
    if(IsFull(s))
    {
        printf("堆栈满");
        return;
    }
    else
    {
        s->Top++;
        s->Data[++(s->Top)] = item;
        return;
    }  
}

ElementType Pop(Stack s)
{
    if(IsEmpty(s))
    {
        printf("堆栈空");
        return -1;
    }
    else
    {
        ElementType val = s->Data[s->Top];
        s->Top--;
        return val;
    }          
}

DStack D_CreateStack()
{
    DStack s;
    s = (DStack)malloc(sizeof(struct DSNode));
    s->Top1 = -1;
    s->Top2 = MAXSIZE;
    return s;
}

int D_IsFull(DStack s)
{
    return (s->Top2 - s->Top1 == 1);
}

int D_IsEmpty(DStack s, int Tag)
{
    if((Tag == 1 && s->Top1 == -1)||
    (Tag == 2 && s->Top2 == MAXSIZE))
    {
        return -1;
    }
    
}

void D_Push(DStack s, ElementType item, int Tag)
{
    if(D_IsFull(s))
    {
        printf("堆栈满");
        return;
    }
    if(Tag == 1)
    {
        s->Data[++(s->Top1)] = item;
    }  
    else
    {
        s->Data[++(s->Top2)] = item;
    }
    
}

ElementType D_Pop(DStack s, int Tag)
{
    if(IsEmpty(s) == -1)
    {
        printf("堆栈空");
        return -1;
    }
    ElementType val;
    if(Tag == 1)
    {
        val = s->Data[s->Top1--];
        return val;
    }
    else
    {
        val = s->Data[s->Top2++];
        return val;
    }      
}

int main()
{
    Stack S;

    S = CreateStack();
    printf("");
}
