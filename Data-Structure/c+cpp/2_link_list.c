#include <stdio.h>
#include <stdlib.h>

typedef int ElementType; //define ElementType as int,
typedef struct LNode *List;
struct LNode
{
    ElementType Data;
    List Next;
};

List L;

List MakeEmpty(); //initial a linear list
List Find(ElementType X, List L); //find X first index
List Insert(ElementType X, int i, List L); //insert a element after index i
List Delete(int i, List L); //delete index i
List FindKth(int K, List L); //return the value of index k
int Length(List L); //get the length of linear list
void ShowList(List L); // output linear list

List MakeEmpty()
{
	List L = (List)malloc(sizeof(struct LNode));
	L = NULL;
	return L;
}

/* get length */
int GetLength(List L)
{
    List p = L;
    int len = 0;
    while(p)
    {
        p = p->Next;
        len++;
    }
    return len;
}

/* Find value with index*/
List FindKth(int k, List L)
{
    List p = L;
    int i = 1;

    while(p != NULL && i < k)
    {
        p = p->Next;
        i++;
    }
    if(i == k) return p;
    else return NULL;
}

/* find with value */
List Find(ElementType X, List L)
{
    List p = L;

    while(p != NULL && p->Data != X)
    {
        p = p->Next;
    }

    return p;
}

/* Insert X */
List Insert(ElementType X, int i, List L)
{
    List p, s;

    if(i == 1)
    {
        s = (List)malloc(sizeof(struct LNode));
        s->Data = X;
        s->Next = L;
        return s;
    }
    p = FindKth(i-1, L);
    if(p == NULL)
    {
        printf("error i");
        return NULL;
    }
    else
    {
        s = (List)malloc(sizeof(struct LNode));
        s->Data = X;
        s->Next = p->Next;
        p->Next = s;
        return L;
    }
    
}


/* Delete */
List Delete(int i, List L)
{
    List p, s;
    if(i == 1)
    {
        s = L;
        if(L != NULL) L = L->Next;
        else return NULL;
        free(s);
        return L;
    }
    p = FindKth(i-1, L);
    if(p == NULL)
    {
        printf("%d Node not exist", i-1);
        return NULL;
    }
    else if(p->Next == NULL)
    {
        printf("%d Node not exist", i);
        return NULL;
    }
    else
    {
        s = p->Next;
        p->Next = s->Next;
        free(s);
        return L;
    }
    

}

void ShowList(List L)
{
    List p = L;
    printf("L length is %d\n", GetLength(L));
    printf("Link List: ");
    while(p)
    {
        printf("%d ", p->Data);
        p = p->Next;
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
    printf("*****   0.Exit              ***** \n");
}

int main(void)
{
    int i=0;
    int c, value, index;
    L = MakeEmpty();

    while(1)
    {
        Linear_List_Menu();
        printf("Please choose options:\n");
        scanf("%d", &c);

        switch(c)
        {
            case 1:
                printf("please input a value: ");
                scanf("%d", &value);
                if(Find(value, L) == NULL) printf("not exist\n");
                else printf("exist\n");
            break;

            case 2:
                printf("please input an index: ");
                scanf("%d", &index);
                if(FindKth(index, L) == NULL) printf("not exist\n");
                else printf("exist\n");
            break;

            case 3:
                printf("please input a value and position: ");
                scanf("%d%d", &value, &index);
                L = Insert(value, index, L);
            break;

            case 4:
                printf("please input an index: ");
                scanf("%d", &index); 
                L = Delete(index, L);           
            break;

            case 0:
                exit(0);
            break;

            default:
            break;
        }
        ShowList(L);
    }
}