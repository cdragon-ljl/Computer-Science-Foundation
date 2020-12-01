#include <stdio.h>
#include <stdlib.h>

typedef struct Node *List;
struct Node{
    List Next;
    int zhishu; //指数
    int xishu; //系数
};

List Read(); //读入链表
List Addition(List l1, List l2); //加法
List Multiplication(List l1, List l2); //乘法
void Print(List l);

List Read()
{
    List L = (List)malloc(sizeof(struct Node));
    List Head = L;
    int n;
    printf("请输入多项式项数: ");
    scanf("%d", &n);
    while(n--){
        int x, z;
        List l = (List)malloc(sizeof(struct Node));
        printf("请输入第 %d 项: ", n);
        scanf("%d %d", &x, &z);
        l->zhishu = z;
        l->xishu = x;
        L->Next = l;
        L = L->Next;
    }
    L->Next = NULL;
    return Head->Next;
}

List Addition(List l1, List l2){
    printf("加法执行中...\n");
    List TmpL1 = l1, TmpL2 = l2;
    List Add = (List)malloc(sizeof(struct Node));
    Add->Next = NULL;
    List Head = Add, t;
    while(TmpL1 && TmpL2){
        t = (List)malloc(sizeof(struct Node));
        if(TmpL1->zhishu == TmpL2->zhishu){
            t->xishu = TmpL1->xishu + TmpL2->xishu;
            t->zhishu = TmpL1->zhishu;
            TmpL1 = TmpL1->Next;
            TmpL2 = TmpL2->Next;
        }
        else if(TmpL1->zhishu < TmpL2->zhishu){
            t->xishu = TmpL2->xishu;
            t->zhishu = TmpL2->zhishu;
            TmpL2 = TmpL2->Next;            
        }
        else if(TmpL1->zhishu > TmpL2->zhishu){
            t->xishu = TmpL1->xishu;
            t->zhishu = TmpL1->zhishu;
            TmpL1 = TmpL1->Next;
        }
        Add->Next = t;
        Add = Add->Next;
    }
    while(TmpL1){
        Add->Next = TmpL1;
    }
    while(TmpL2){
        Add->Next = TmpL2;
    }
    printf("加法执行完毕\n");
    return Head->Next;
}

List Multiplication(List l1, List l2){
    printf("乘法执行中...\n");
    List TmpL1 = l1, TmpL2 = l2;
    List Mul = (List)malloc(sizeof(struct Node));
    Mul->Next = NULL;
    List Head = Mul, t;
    while(TmpL1){
        while(TmpL2){
            t = (List)malloc(sizeof(struct Node));
            t->xishu = TmpL1->xishu * TmpL2->xishu;
            t->zhishu = TmpL1->zhishu + TmpL2->zhishu;
            t->Next = NULL;
            Head = Addition(t, Mul);
            Mul = Head;
            TmpL2 = TmpL2->Next;
        }
        TmpL1 = TmpL1->Next;
    }
    printf("乘法执行完毕\n");
    return Head;
}

void Print(List l){
    List t = l;
    int flag = 1;
    printf("结果为: ");
    while(t){
        if(!flag && t->xishu){
            printf(" ");
        }
        if(t->xishu){
            printf("%d %d", t->xishu, t->zhishu);
            flag = 0;
        }
        t = t->Next;
    }
    if(flag){
        printf("0 0");
    }
    printf("\n");
}

int main(void){
    List L1, L2, Add, Mul;
    L1 = Read();
    L2 = Read();
    Add = Addition(L1, L2);
    Print(Add);
    //Mul = Multiplication(L1, L2);
    //Print(Mul);

    return 0;
}

