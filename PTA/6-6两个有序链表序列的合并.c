#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read();
void Print( List L );

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

List Merge( List L1, List L2 ){
    List L = (List)malloc(sizeof(List));//创建一个结点作为头节点，用作第三个链表
    List head = L;//存储链表L的头节点
    L->Next = NULL;
    List node1;
    List node2;
    node1 = L1->Next;//将L1的第一个结点赋给node1
    node2 = L2->Next;//将L2的第一个结点赋给node2
    while (node1 != NULL && node2 != NULL){
        //如果node1->Data < node2->Data,则让L->Next指向node1，node1后移
        if (node1->Data < node2->Data){
            L->Next = node1;
            node1 = node1->Next;
        }
        else{
            L->Next = node2;
            node2 = node2->Next;//node2向后移动一个结点
        }
        L = L->Next;//L向后移动一个结点
    }
    if(node1 != NULL)
        L->Next = node1;//如果node1不指向空，则证明L1链表还有数据，因为是单链表，所以只需要让L-Next只想node1即可。
    if(node2 != NULL)
        L->Next = node2;
    L1->Next = NULL;//L1指向NULL,因为链表L1里面的结点全部移动到L里面。也可以将L1释放掉（free(L1)）
    L2->Next = NULL;//同上
    return head;//返回链表头节点
}

void Print( List L )
{
    List p=L->Next;
    if(p)
    {
        List r;
        r = L;
        while(r->Next)
        {
            r = r->Next;
            printf("%d ",r->Data);
        }
    }
    else
    {
        printf("NULL");
    }
    printf("\n");
}

List Read()
{
    int n;
    scanf("%d",&n);
    List L=(List)malloc(sizeof(PtrToNode));   ///申请一个头结点
    L->Next = NULL;        ///头指针为空
    if(n)    ///当n不是0时
    {
        List r=L;     ///r是一个中间变量的节点
        for(int i=0;i<n;i++)
        {
            List p=(List)malloc(sizeof(struct Node));
            scanf("%d",&(p->Data));    ///尾插法
            r->Next = p;
            r = p;
        }
        r->Next = NULL;
    }
    return L;
}
