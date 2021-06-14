#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 1000

typedef struct{
    unsigned int weight;
    char ch;
}char_weight;

typedef struct {
    char ch;
    unsigned int weight;
    unsigned int parent,lchild,rchild;
}*HuffmanTree,HTNode;
typedef char* HuffmanCode;

void HuffmanCoding(HuffmanTree HT,HuffmanCode HC,char_weight *ch, int n);
void Get_str(char *path,char str[]);
void Calculate_weight(char str[],char_weight ch[],int *n);
void select(HTNode HT[],int n,int* s1,int* s2);


int main()
{
    char *path="C:\\Users\\chang\\CLionProjects\\HuffmanTree\\original_text.txt";
    char str[N];
    int n=0;
    float w[N];
    char_weight ch[N];
    Get_str(path,str);
    Calculate_weight(str,ch,&n);
    int size = 2*n;
//    HTNode HT[size];栈分配
    HuffmanTree HT = (HuffmanTree)malloc(size * sizeof(HTNode));//堆分配
//    HuffmanCode HC[n];栈分配
    HuffmanCode HC = (HuffmanCode)malloc(n*sizeof(char));//堆分配
    HuffmanCoding(HT, HC, ch, n);
    return 0;
}
void Get_str(char *path,char str[]){
    FILE *fp=fopen(path,"r");
    fgets(str,1000,fp);
    fclose(fp);
}
void Calculate_weight(char str[],char_weight ch[],int* n){
    int c=0;
    int count[N];
    for(int i=0;i<strlen(str);i++){
        count[str[i]]++;
    }
    for(int i=0;i<128;i++){
        if(count[i]!=0){
            ch[c].ch=i;
            ch[c].weight=count[i];
            c++;
            (*n)++;
        }
    }
}
void HuffmanCoding(HuffmanTree HT,HuffmanCode HC,char_weight *ch, int n){
    if(n<1) return;
    int m = 2*n-1;
    int s1,s2;
    int i =0;
    for(;i<n;i++,ch++){
        HT[i].ch = ch->ch;
        HT[i].weight = ch->weight;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
        HT[i].parent = 0;
    }
    for (i = n;  i<m ; i++) {
        HT[i].weight = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
        HT[i].parent = 0;
    }
    printf("\n");
    for (i = n; i < m; ++i) {
        select(HT,i,&s1,&s2);
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }
    char* cd = (char*)malloc(n * sizeof(char));
    cd[n-1]='\0';
    int s;
    unsigned int f,k;
    for (int j = 0; j < n; ++j) {
        s=n-1;
        for (f = HT[j].parent,k = j; f != 0 ; k=f, f=HT[f].parent) {
            if (HT[f].lchild==k)
                cd[--s]= '0';
            else
                cd[--s]='1';
        }
        strcpy((char *) &HC[j], &cd[s]);
        printf("%-3d word:%-2c   weight:%-3d   code:%s\n",j,HT[j].ch,HT[j].weight,(char *) &HC[j]);
    }
    free(cd);
}
void select(HTNode HT[],int n,int* s1,int* s2){
    int minum;
    for (int i = 0; i < n; ++i) {
        if(HT[i].parent==0){
            minum = i;
            break;
        }
    }
    for(int i=0; i< n; i++) {
        if (HT[i].parent == 0) {
            if (HT[i].weight < HT[minum].weight)
                minum = i;
        }
    }
    *s1 = minum;
    // 以下是找到第二个最小值，且与第一个不同
    for(int i=0; i<n; i++){
        if(HT[i].parent == 0 && i != *s1){
            minum = i;
            break;
        }
    }
    for(int i=0; i<n; i++){
        if(HT[i].parent == 0 && i != *s1) {
            if (HT[i].weight < HT[minum].weight)
                minum = i;
        }
    }
    *s2 = minum;
}