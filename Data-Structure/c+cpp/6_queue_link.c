#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct QNode *Queue;
struct Node
{
    ElementType Data;
    struct Node *Next;
};
struct QNode
{
    struct Node *front; //指向队头节点
    struct Node *rear;  //指向队尾节点
};

Queue CreateQueue();  // 初始化队列 
void AddQ(Queue q, ElementType item);  //  入队
ElementType DeleteQ(Queue q);  // 出队 
int IsEmpty(Queue q); // 判断队列是否为空 

Queue CreateQueue(){
	Queue Q;
	Q = (Queue)malloc(sizeof(struct QNode));
	Q->front = NULL;
	Q->rear = NULL;
	return Q;
}

int IsEmpty(Queue Q){
	return (Q->front == NULL);
}

void AddQ(Queue q, ElementType item){
    struct Node *node;
    node = (struct Node *)malloc(sizeof(struct Node));
    node->Data = item;
    node->Next = NULL;

    if(q->rear == NULL){//队列为空
        q->rear = node;
        q->front = node;
    }
    else{
        q->rear->Next = node;
        q->rear = node;
    }
}

ElementType DeleteQ(Queue q){
    struct Node *FrontCell;
    ElementType FrontElem;

    if(q->front == NULL){
        printf("队列空");
        return -1;
    }
    FrontCell = q->front;
    if(q->front == q->rear){
        q->front = q->rear = NULL;
    }
    else{
        q->front = q->front->Next;
    }
    FrontElem = FrontCell->Data;
    free(FrontCell);
    return FrontElem;
}

int main(void){
    Queue Q;
    Q = CreateQueue();
    printf("入队1\n");
    AddQ(Q, 1);
    printf("入队2\n");
    AddQ(Q, 2);
    printf("入队3\n");
    AddQ(Q, 3);
    printf("入队4\n");
    AddQ(Q, 4);
    printf("入队5\n");
    AddQ(Q, 5);
    printf("出队%d\n", DeleteQ(Q));
    printf("出队%d\n", DeleteQ(Q));
    printf("出队%d\n", DeleteQ(Q));

    return 0;
}