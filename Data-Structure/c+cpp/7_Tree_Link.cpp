#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct TreeNode *BinTree;
struct TreeNode{
    int Data;
    BinTree Left;
    BinTree Right;
};

typedef struct SNode *Stack;
struct SNode{
    BinTree Data;
    Stack Next;
};

BinTree CreatBinTree();
bool IsEmpty(BinTree BT);
void PreOrderTraversal(BinTree BT); 
void InOrderTraversal(BinTree BT); 
void PostOrderTraversal(BinTree BT); 
void LevelOrderTraversal(BinTree BT);
void FindLeaves(BinTree BT);
int  GetHeight(BinTree BT);

Stack CreateStack();
int IsEmpty(Stack s);
void Push(Stack s, BinTree item);
BinTree Pop(Stack s);

Stack CreateStack(){
    struct SNode *S = new struct SNode;
	S->Next = NULL;
	return S;
}

int IsEmpty(Stack s){
	return (s->Next == NULL);
}

void Push(Stack s, BinTree item){
	struct SNode *tmp = new struct SNode;
	tmp->Data = item;
	// 链栈栈顶元素是链表头结点，新入栈的链表在栈顶元素后面 
	tmp->Next = s->Next;   
	s->Next = tmp;
} 

BinTree Pop(Stack s){
	Stack First;
	BinTree TopVal;
	if(IsEmpty(s)){
		cout << "堆栈空" <<endl;
		return 0;
	}
    else{
		First = s->Next;   // 出栈第一个元素在栈顶元素后面 
		s->Next = First->Next;  //把第一个元素从链栈删除 
		TopVal = First->Data;   // 取出被删除结点的值 
		free(First);  // 释放空间 
		return TopVal;
	}
} 

BinTree Insert(int Data){
	struct TreeNode *BT = new struct TreeNode;
	BT->Data = Data;
	BT->Left = NULL;
	BT->Right = NULL;
	return BT;
}

BinTree CreatBinTree(){
    struct TreeNode *BT = new struct TreeNode;
    BT->Data = 1;
    BT->Left = Insert(2);
    BT->Right = Insert(3);
    BT->Left->Left = Insert(4);
    BT->Left->Right = Insert(6);
    BT->Left->Right->Left = Insert(5);
    BT->Right->Left = Insert(7);
    BT->Right->Right = Insert(9);
    BT->Right->Left->Right = Insert(8);

    return BT;
}
/*
 * 先序遍历
 * 1.访问根节点
 * 2.先序遍历其左子树
 * 3.先序遍历其右子树
*/

//先序递归
// void PreOrderTraversal(BinTree BT){
//     if(BT){
//         printf("%d", BT->Data);
//         PreOrderTraversal(BT->Left);
//         PreOrderTraversal(BT->Right);
//     }
// }

//先序非递归
void PreOrderTraversal(BinTree BT){
    BinTree T = BT;
    Stack S = CreateStack();
    while(T || !IsEmpty(S)){
        while(T){
            Push(S, T);
            cout << T->Data << "-";
            T = T->Left;
        }
        if(!IsEmpty(S)){
            T = Pop(S);            
            T = T->Right;
        }
    }
    cout << endl;    
}
/*
 * 中序遍历
 * 1.先序遍历其左子树
 * 2.访问根节点
 * 3.先序遍历其右子树
*/

//中序递归
// void InOrderTraversal(BinTree BT){
//     if(BT){        
//         InOrderTraversal(BT->Left);
//         printf("%d", BT->Data);
//         InOrderTraversal(BT->Right);
//     }
// }

/*
 * 中序遍历非递归
 * 1.遇到一个结点，就把它压栈，并去遍历它的左子树
 * 2.当左子树遍历结束后，从栈顶弹出这个结点并访问它
 * 3.然后按其右指针再去中序遍历该结点的右子树
*/

void InOrderTraversal(BinTree BT){
    BinTree T = BT;
    Stack S = CreateStack();
    while(T || !IsEmpty(S)){
        while(T){
            Push(S, T);
            T = T->Left;
        }
        if(!IsEmpty(S)){
            T = Pop(S);
            cout << T->Data << "-";
            T = T->Right;
        }
    }
    cout << endl;
}
/*
 * 后序遍历
 * 1.先序遍历其左子树
 * 2.先序遍历其右子树
 * 3.访问根节点
*/

//后序递归
// void PostOrderTraversal(BinTree BT){
//     if(BT){        
//         PostOrderTraversal(BT->Left);
//         PostOrderTraversal(BT->Right);
//         printf("%d", BT->Data);
//     }
// }

/*
 * 中序遍历非递归
 * 1.遇到一个结点，就把它压栈，并去遍历它的左子树
 * 2.当左子树遍历结束后,然后按其右指针再去中序遍历该结点的右子树
 * 3.当右子树遍历结束后，从栈顶弹出这个结点并访问它
*/
void PostOrderTraversal(BinTree BT){
    BinTree T = BT;
    Stack S = CreateStack();
    //Stack Q = CreateStack();
    vector<BinTree> v;
    while(T || !IsEmpty(S)){
        while(T){
            Push(S, T);
            //Push(Q, T);
            v.push_back(T);
            T = T->Right;
        }
        if(!IsEmpty(S)){
            T = Pop(S);
            T = T->Left;
        }
    }
    // while(!IsEmpty(Q)){
    //     T = Pop(Q);
    //     cout << T->Data << "-"; 
    // }
    reverse(v.begin(), v.end());
    for(vector<BinTree>::iterator it = v.begin(); it != v.end(); it++){
        cout << (*it)->Data << "-"; 
    }
    cout << endl;
}

//层序遍历
void LevelOrderTraversal(BinTree BT){
    queue<BinTree> Q;
    BinTree T = BT;
    if(!T){
        return;
    }
    Q.push(T);
    while(!Q.empty()){
        T = Q.front();
        Q.pop();
        cout << T->Data << "-";
        if(T->Left){
            Q.push(T->Left);
        }
        if(T->Right){
            Q.push(T->Right);
        }
    }
    cout << endl;
}

//输出叶子结点
void  FindLeaves(BinTree BT){
	if(BT){
		if( !BT->Left && !BT->Right){
			cout << BT->Data << "-";
        }
		FindLeaves(BT->Left);
		FindLeaves(BT->Right);
	}
} 

// 求树高度
int  GetHeight(BinTree BT){
	int HL, HR, HMAX;
	if(BT){
		HL = GetHeight(BT->Left);
		HR = GetHeight(BT->Right);
		HMAX = max(HL, HR);
		return HMAX + 1;
	}
    else{
		return 0;
    }
} 

int main(void){
    BinTree BT;
    BT = CreatBinTree();

    cout << "先序遍历:" << endl;
    PreOrderTraversal(BT);

    cout << "中序遍历:" << endl;
    InOrderTraversal(BT);

    cout << "后序遍历:" << endl;
    PostOrderTraversal(BT);

    cout << "层序遍历:" << endl;
    LevelOrderTraversal(BT);

    cout << "输出叶子结点:" << endl;
    FindLeaves(BT);
    cout << endl;
    
    cout << "树高: ";
    cout << GetHeight(BT) << endl;

    system("pause");
    return 0;
}