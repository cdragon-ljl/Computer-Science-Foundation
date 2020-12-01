#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5 //队列的最大长度

typedef int ElementType; 
typedef struct QNode *Queue;
struct QNode
{
    ElementType Data[MAXSIZE];
    int front; //记录队头
    int rear; //记录队尾
    int num; //记录元素个数
};

Queue CreateQueue(); //初始化队列
int IsFullQ(Queue q); //判断队列是否已满
int IsEmptyQ(Queue q); //判断队列是否为空
void AddQ(Queue q, ElementType item); //入队
ElementType DeleteQ(Queue q); //出队
void ShowQueue(Queue q);

Queue CreateQueue()
{
    Queue Q;
    Q = (Queue)malloc(sizeof(struct QNode));
    Q->front = -1;
    Q->rear = -1;
    Q->num = 0;
    ShowQueue(Q);
    return Q;
}

int IsFullQ(Queue q)
{
    return ((q->rear + 1) % MAXSIZE == q->front);
}

int IsEmptyQ(Queue q)
{
    return (q->front == q->rear);
}

void AddQ(Queue q, ElementType item)
{
    if(IsFullQ(q))
    {
        printf("队列满\n");
        return;
    }
    q->rear = (q->rear + 1) % MAXSIZE;
    q->Data[q->rear] = item;
    q->num++;
}

ElementType DeleteQ(Queue q)
{
    if(IsEmptyQ(q))
    {
        printf("队列空\n");
        return -1;
    }
    else
    {
        q->front = (q->front + 1) % MAXSIZE;
        q->num--;
        return q->Data[q->front];
    }
}

void ShowQueue(Queue q)
{
    if(IsEmptyQ(q))
    {
        printf("队列空\n");
        return;
    }
    printf("front = %d, rear = %d, num = %d\n", q->front, q->rear, q->num);
    for(int i = 0; i <= q->rear; i++)
    {
        printf("%d ", q->Data[i]);
    }
    printf("\n");
}

void Queue_Menu()
{
    printf("*****       Queue Menu      ***** \n");
    printf("*****   1.Add to queue      ***** \n");
    printf("*****   2.Delete from queue ***** \n");
    printf("*****   0.Exit              ***** \n");
}

int main(void)
{
    int c, q;
    Queue Q;
    Q = CreateQueue();
    while(1)
    {
        Queue_Menu();
        printf("Please choose options: ");
        scanf("%d", &c);

        switch(c)
        {
            case 1:
                printf("please input a value: ");
                scanf("%d", &q);
                AddQ(Q, q);
            break;

            case 2:
                printf("Delete %d\n", DeleteQ(Q));
            break;

            case 0:
                exit(0);
            break;

            default:
            break;
        }
        ShowQueue(Q);
    }
}
