#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
typedef struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
}TNode;

BinTree CreatBinTree(); /* 创建二叉树 */
void IgnoreTraversal( BinTree BT );//中序遍历
void PreorderTraversal( BinTree BT );//先序遍历
void PostorderTraversal( BinTree BT );//后序遍历
void LevelorderTraversal( BinTree BT );//层次遍历

int main()
{
    BinTree BT = CreatBinTree();
	/**
	 * 				A
	 * 			    
	 * 		     /     \
	 * 		    B	    C
	 * 		   / \     / \
	 * 		  D   F	  G   I
	 * 			 /     \
	 * 			E       H
	*/
    // printf("Ignore:");    IgnoreTraversal(BT);    printf("\n");
    // printf("Preorder:");   PreorderTraversal(BT);   printf("\n");
    // printf("Postorder:");  PostorderTraversal(BT);  printf("\n");
    printf("Levelorder:"); LevelorderTraversal(BT); printf("\n");
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
//中序遍历
void IgnoreTraversal(BinTree BT)
{
	if (BT)
	{
		IgnoreTraversal(BT->Left);
		printf(" %c", BT->Data);
		IgnoreTraversal(BT->Right);
	}
}
//前序遍历
void PreorderTraversal(BinTree BT)
{
	if (BT)
	{
		printf(" %c", BT->Data);
		PreorderTraversal(BT->Left);
		PreorderTraversal(BT->Right);
	}
}
//后序遍历
void PostorderTraversal(BinTree BT)
{
	if (BT)
	{
		PostorderTraversal(BT->Left);
		PostorderTraversal(BT->Right);
		printf(" %c", BT->Data);
	}
}
//层次遍历，用队列实现
void LevelorderTraversal(BinTree BT) 
{
	BinTree q[100],p;
	int front=0, rear=0;
	if (!BT) return;
	else
	{
		q[rear] = BT;//根节点入队
		rear++;//尾指针rear加一
		while (front != rear)
		{
			p = q[front];//把q[front]的数据赋值给p
			front++;//根节点出队，头指针向后移，即front++
			printf(" %c", p->Data);
			//如果p的左孩子不为空，则左孩子入队，尾指针rear加一
			if (p->Left){
				q[rear] = p->Left;
				rear++;
			}
			//如果p的右孩子不为空，则右孩子入队，尾指针rear加一	
			if (p->Right){
				q[rear] = p->Right;	
				rear++;
			}	
		}
	}
}
