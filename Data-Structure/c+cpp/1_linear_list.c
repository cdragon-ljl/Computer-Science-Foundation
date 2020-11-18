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

    while(i <= L->Last && L->Data[i] != X)
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
    if(i < 0 || (L->Last + 1) < i)
    {
        printf("illegal location");
        return;
    }
    for(j = L->Last; j >= i; j--)
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

    if(i < 0 || L->Last < i)
    {
        printf("no index %d", i);
        return;
    }
    for(j = i; j <= L->Last; j++)
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
    if(k < 0 || L->Last < k)
    {
        printf("no index %d", k);
        return -1;
    }
    return L->Data[k];
}


/* get length */
int GetLength(List L)
{
    return L->Last + 1;
}

void ShowList(List L)
{
    printf("L length is %d\n", L->Last+1);
    printf("Linear List: ");
    for(int i = 0; i < GetLength(L); i++)
    {
        printf("%d ", L->Data[i]);
    }
    printf("\n");
}

void Linear_List_Menu()
{
    printf("*****   Linear List Menu    ***** \n");
    printf("*****   1.Find with value   ***** \n");
    printf("*****   2.Find with index   ***** \n");
    printf("*****   3.Insert new member ***** \n");
    printf("*****   4.Delete member     ***** \n");
}

int main(void)
{
    int i=0;
    int c, value, index;
    L = MakeEmpty();

    while(1)
    {
        Linear_List_Menu();
        printf("Please choose options");
        scanf("%d", &c);

        switch(c)
        {
            case 1:
                printf("please input a value");
                scanf("%d", &value);
                printf("the index=%d value is %d\n", Find(value, L), value);
            break;

            case 2:
                printf("please input an index");
                scanf("%d", &index);
                printf("the index=%d value is %d\n", index, FindKth(index, L));
            break;

            case 3:
                printf("please input a value and position");
                scanf("%d%d", &value, &index);
                Insert(value, index, L);
            break;

            case 4:
                printf("please input a value");
                scanf("%d", &value); 
                Delete(value, L);           
            break;

            default:
            break;
        }
        ShowList(L);
    }
}