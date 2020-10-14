#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100 //maxsize of data array

typedef int ElementType; //define ElementType as int,
typedef struct LNode
{
    ElementType Data[MAXSIZE];
    int Last; //define the last element of linear list
}*List;

List L; //define a linear list

List MakeEmpty(); //initial a linear list
int Find(ElementType X, List L); //find X first index
void Insert(ElementType X, int i, List L); //insert a element after index i
void Delete(int i, List L); //delete index i
ElementType FindKth(int K, List L); //return the value of index k
int Length(List L); //get the length of linear list
void ShowList(List L); // output linear list

/* initial a linear list */
List MakeEmpty()
{
    List L;
    L = (List)malloc(sizeof(struct LNode));
    L->Last = -1;

    return L;
}

/* find with value */
int Find(ElementType X, List L)
{
    int i = 0;

    while(i<=L->Last && L->Data[i] != X)
    {
        i++;
    }
    if(L->Last < i)
    {
        return -1;
    }
    else
    {
        return i;
    } 
}


/* Insert X */
void Insert(ElementType X, int i, List L)
{
    int j;

    if(L->Last == MAXSIZE-1)
    {
        printf("The linear list is full!");
        return;
    }
    if(i<0 || (L->Last+1)<i)
    {
        printf("illegal location");
        return;
    }
    for(j=L->Last; j>=i; j--)
    {
        L->Data[j+1] = L->Data[j];
    }
    L->Data[i] = X;
    L->Last++;

    return;
}


/* Delete */
void Delete(int i, List L)
{
    int j;

    if(i<0 || L->Last<i)
    {
        printf("no index %d", i);
        return;
    }
    for(j=i; j<=L->Last; j++)
    {
        L->Data[j-1] = L->Data[j];
    }
    L->Last--;

    printf("Delete success\n");
    ShowList(L);

    return;
}


/* Find value with index*/
ElementType FindKth(int k, List L)
{
    if(k<0 || L->Last<k)
    {
        printf("no index %d", k);
        return -1;
    }
    return L->Data[k];
}


/* get length */
int GetLength(List L)
{
    return L->Last+1;
}

void ShowList(List L)
{
    printf("L length is %d\n", L->Last+1);
    printf("Linear List: ");
    for(int i=0; i<GetLength(L); i++)
    {
        printf("%d ", L->Data[i]);
    }
    printf("\n");
}

int main(void)
{
    int i=0;

    L = MakeEmpty();

    Insert(20, 0, L);
    Insert(20, 1, L);
    Insert(10, 2, L);
    Insert(24, 3, L);
    ShowList(L);

    int index;
    index = Find(24, L);
    printf("the index=%d value is 24\n", index);

    int value;
    value = FindKth(3, L);
    printf("the index=3 value is %d\n", value);

    Delete(2, L);
}