#include <stdio.h>
#include <stdlib.h>
typedef enum
{
    false,
    true
} bool;

typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode
{
    ElementType Data;
    BinTree Left;
    BinTree Right;
    int flag;
};

/*------堆栈的定义-------*/
typedef Position SElementType;
typedef struct SNode *PtrToSNode;
struct SNode
{
    SElementType Data;
    PtrToSNode Next;
};
typedef PtrToSNode Stack;

/* 裁判实现，细节不表 */
Stack CreateStack();
bool IsEmpty(Stack S);
bool Push(Stack S, SElementType X);
SElementType Pop(Stack S);  /* 删除并仅返回S的栈顶元素 */
SElementType Peek(Stack S); /* 仅返回S的栈顶元素 */
/*----堆栈的定义结束-----*/

BinTree CreateBinTree(); /* 裁判实现，细节不表 */
void IgnoreTraversal(BinTree BT);
void PreorderTraversal(BinTree BT);
void PostorderTraversal(BinTree BT);

int main()
{
    BinTree BT = CreateBinTree();
    printf("Ignore:");
    IgnoreTraversal(BT);
    printf("\n");
    printf("Preorder:");
    PreorderTraversal(BT);
    printf("\n");
    printf("Postorder:");
    PostorderTraversal(BT);
    printf("\n");
    return 0;
}
/* 你的代码将被嵌在这里 */
void IgnoreTraversal(BinTree BT)
{
    Stack S = CreateStack();
    while (BT || !IsEmpty(S))
    {
        while (BT)
        {
            Push(S, BT);
            BT = BT->Left;
        }
        if (!IsEmpty(S))
        {
            BT = Pop(S);
            printf(" %c", BT->Data);
            BT = BT->Right;
        }
    }
}
void PreorderTraversal(BinTree BT)
{
    Stack S = CreateStack();
    while (!IsEmpty(S) || BT)
    {
        while (BT)
        {
            printf(" %c", BT->Data);
            Push(S, BT);
            BT = BT->Left;
        }
        if (!IsEmpty(S)){
            BT = Pop(S);
            BT = BT->Right;
        }
    }
}
void PostorderTraversal(BinTree BT)
{
    Stack S = CreateStack();
    while(BT || !IsEmpty(S)){
        while (BT){
            Push(S,BT);
            BT->flag = 1;
            BT = BT->Left;
        }
        if(!IsEmpty(S)){
            BT = Pop(S);
            if (BT->flag == 1){
                Push(S,BT);
                BT->flag=2;
                BT = BT->Right;
            }
            else{
                printf(" %c",BT->Data);
                BT = NULL;
            }
        }
    }
}
BinTree CreatBinTree(){
    BinTree A = (BinTree)malloc(sizeof(BinTree));
	BinTree B = (BinTree)malloc(sizeof(BinTree));
	BinTree C = (BinTree)malloc(sizeof(BinTree));
	BinTree D = (BinTree)malloc(sizeof(BinTree));
	BinTree E = (BinTree)malloc(sizeof(BinTree));
	BinTree F = (BinTree)malloc(sizeof(BinTree));
	BinTree G = (BinTree)malloc(sizeof(BinTree));
	BinTree H = (BinTree)malloc(sizeof(BinTree));
	BinTree I = (BinTree)malloc(sizeof(BinTree));
	A->Data = 'A';
	B->Data = 'B';
	C->Data = 'C';
	D->Data = 'D';
	E->Data = 'E';
	F->Data = 'F';
	G->Data = 'G';
	H->Data = 'H';
	I->Data = 'I';

	A->Left  = B;
	A->Right = C;
	B->Left  = D;
	B->Right = F;
	C->Left  = G;
	C->Right = I;
	D->Left  = NULL;
	D->Right = NULL;
	E->Right = NULL;
	E->Left  = NULL;
	F->Left  = E;
	F->Right = NULL;
	G->Left  = NULL;
	G->Right = H;
	H->Right = NULL;
	H->Left  = NULL;
	I->Left  = NULL;
	I->Right = NULL;
	return A;
}