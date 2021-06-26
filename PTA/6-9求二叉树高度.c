#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree CreatBinTree(); /* 实现细节忽略 */
int GetHeight( BinTree BT );

int main()
{
    BinTree BT = CreatBinTree();
    /**
	 * 				A
	 * 		     /     \
	 * 		    B	    C
	 * 		   / \     / \
	 * 		  D   F	  G   I
	 * 			 /     \
	 * 			E       H
	*/
    printf("%d\n", GetHeight(BT));
    return 0;
}
//创建二叉树
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
int GetHeight( BinTree BT ){
    int high;
    int lh,rh;
    if ( BT == NULL)
        return 0;
    else{
        lh = GetHeight(BT->Left);
        rh = GetHeight(BT->Right);
        high = lh > rh ? lh : rh;
        return high+1;
    }
}