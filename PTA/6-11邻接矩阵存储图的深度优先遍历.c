#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;
#define MaxVertexNum 10  /* 最大顶点数设为10 */
#define INFINITY 65535   /* ∞设为双字节无符号整数的最大值65535*/
typedef int Vertex;      /* 用顶点下标表示顶点,为整型 */
typedef int WeightType;  /* 边的权值设为整型 */

typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv;  /* 顶点数 */
    int Ne;  /* 边数   */
    WeightType G[MaxVertexNum][MaxVertexNum]; /* 邻接矩阵 */
};
typedef PtrToGNode MGraph; /* 以邻接矩阵存储的图类型 */
bool Visited[MaxVertexNum]; /* 顶点的访问标记 */

MGraph CreateGraph(); /* 创建图并且将Visited初始化为false；裁判实现，细节不表 */

void Visit( Vertex V )
{
    printf(" %d", V);
}

void DFS( MGraph Graph, Vertex V, void (*Visit)(Vertex) );


int main()
{
    MGraph G;
    Vertex V;

    G = CreateGraph();
    scanf("%d", &V);
    if( V>=G->Nv){
        printf("Please enter an integer less than %d,please.",G->Nv-1);
        exit(1);
    }
    printf("DFS from %d:", V);
    DFS(G, V, Visit);

    return 0;
}

void DFS( MGraph Graph, Vertex V, void (*Visit)(Vertex) )
{
    Visited[V] = true;
    Visit(V);
    for ( int i=0; i < Graph->Nv; i++){
        if(Graph->G[V][i]==1 && Visited[i]!=true){
            DFS(Graph,i,Visit);
        }
    }
}
MGraph CreateGraph(){
    MGraph G = (MGraph)malloc(sizeof(MGraph));
    G->Nv = 7;
    G->Ne = 9;
    G->G[0][3] = 1;
    G->G[3][0] = 1;
    G->G[0][4] = 1;
    G->G[4][0] = 1;
    G->G[0][2] = 1;
    G->G[2][0] = 1;
    G->G[1][5] = 1;
    G->G[5][1] = 1;
    G->G[1][3] = 1;
    G->G[3][1] = 1;
    G->G[2][5] = 1;
    G->G[5][2] = 1;
    G->G[2][3] = 1;
    G->G[3][2] = 1;
    G->G[4][5] = 1;
    G->G[5][4] = 1;
    G->G[5][6] = 1;
    G->G[6][3] = 1;
    return G;
}