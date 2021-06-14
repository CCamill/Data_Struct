#include <stdio.h>
#include <stdlib.h>

#define INT 0x3f3f3f3f
#define MAX 100
#define False 0
#define True 1

typedef struct{
    int vexnum;
    int edgenum;
}Graph;

typedef struct {
    int dw;
    int sw;
    int p;
}EdgeData;

void init(EdgeData ed[][MAX],Graph* G){
    int i,j;
    for(i=0;i<=G->vexnum;i++){
        for(j=0;j<=G->vexnum;j++){
            ed[i][j].dw=INT;
            ed[i][j].sw=INT;
        }
    }
    ed[1][1].dw=0;
    ed[1][2].dw=12;
    ed[1][3].dw=8;
    ed[1][4].dw=6;
    ed[2][5].dw=5;
    ed[3][5].dw=8;
    ed[4][6].dw=7;
    ed[5][7].dw=5;
    ed[5][8].dw=6;
    ed[6][8].dw=10;
    ed[7][9].dw=6;
    ed[8][9].dw=8;

    ed[1][1].sw=0;
    ed[1][2].sw=40;
    ed[1][3].sw=50;
    ed[1][4].sw=60;
    ed[2][5].sw=20;
    ed[3][5].sw=25;
    ed[4][6].sw=55;
    ed[5][7].sw=20;
    ed[5][8].sw=20;
    ed[6][8].sw=40;
    ed[7][9].sw=30;
    ed[8][9].sw=25;
}
int* ShortestPath_DIJ(Graph* G,int v1,EdgeData ed[][MAX]){
    int* dis = (int*)malloc((G->vexnum+1)*sizeof(int));//原点到v的距离权重
    int* final=(int*)malloc((G->vexnum+1) * sizeof(int));//原点到v的最短路径是否存在
    *(dis+1)=0;
    final[1]=True;
    //初始化dis和final
    for(int i=2;i<=G->vexnum;i++){
        *(dis+i)=INT;
        *(final+i)=False;
        if(ed[v1][i].dw!=INT){
            dis[i]=ed[v1][i].dw;
        }
    }
    for(int i=2;i <= G->vexnum;++i){
        int mini=0;
        int min=INT;
        for (int j = 1; j <= G->vexnum; ++j) {
            if(!final[j] && min>dis[j]){
                mini=j;
                min=dis[j];
            }
        }
        if(mini==0) break;
        final[mini]=True;
        for (int w = 2; w <= G->vexnum; ++w) {
            if(!final[w] && dis[w] > min + ed[mini][w].dw){
                dis[w] = min + ed[mini][w].dw;
            }
        }
    }
    for(int i=2;i<=G->vexnum;i++){
        printf("The shortest distance to the point \"V%d\" is \"%d\"\n",i,*(dis+i));
    }
    return dis;
}
int* Minimumtime_DIJ(Graph* G,int v1,EdgeData ed[][MAX]){
    int* dis = (int*)malloc((G->vexnum+1)*sizeof(int));//原点到v的时间权重
    int* final=(int*)malloc((G->vexnum+1) * sizeof(int));//原点到v的最短时间是否存在
    *(dis+1)=0;
    final[1]=True;
    //初始化dis和final
    for(int i=2;i<=G->vexnum;i++){
        *(dis+i)=INT;
        *(final+i)=False;
        if(ed[v1][i].sw!=INT){
            dis[i]=ed[v1][i].sw;
        }
    }
    for(int i=2;i <= G->vexnum;++i){
        int mini=0;
        int min=INT;
        for (int j = 1; j <= G->vexnum; ++j) {
            if(!final[j] && min>dis[j]){
                mini=j;
                min=dis[j];
            }
        }
        if(mini==0) break;
        final[mini]=True;
        for (int w = 2; w <= G->vexnum; ++w) {
            if(!final[w] && dis[w] > min + ed[mini][w].sw){
                dis[w] = min + ed[mini][w].sw;
            }
        }
    }
    for(int i=2;i<=G->vexnum;i++){
        printf("The shortest time to the point \"V%d\" is \"%d\"\n",i,*(dis+i));
    }
    return dis;
}
int main() {
    Graph* G=(Graph*)malloc(sizeof(Graph));
    G->vexnum=9;
    EdgeData ed[MAX][MAX];
    init(ed,G);
    int* distance=ShortestPath_DIJ(G,1,ed);
    int* time=Minimumtime_DIJ(G,1,ed);
    return 0;
}