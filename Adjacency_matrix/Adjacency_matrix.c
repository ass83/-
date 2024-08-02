//
// Created by 陈宇轩 on 2024/8/2.
//

#include "Adjacency_matrix.h"
#include "stdlib.h"
#include "stdio.h"
#include "Seq_Queue.h"
Graph *Create_Graph(void)
{
    Graph *G= calloc(1,sizeof(*G));
    int i;
    for(i=0;i<MAX_Vertex_Num;i++)
        G->V[i]='0';
    Vextex_type x;
    scanf("%c",&x);
    while(x!='#')//初始化V
    {
        G->V[G->Vertex_num]=x;
        G->Vertex_num++;
        scanf("%c",&x);
    }
//    fflush(stdout);

    getchar();
//    fflush(stdout);
    Vextex_type start,end;//初始化A
    Adj_type weight;
    scanf("%c %c %d",&start,&end,&weight);
    int start_index,end_index;
//    int start_flag,end_flag;
    while(start!='#')
    {
        for (i = 0; i < G->Vertex_num; i++)
        {
            if (start == G->V[i])
            {
                start_index = i;
            }
            if (end == G->V[i])
            {
                end_index = i;
            }
        }
//        printf("%d %d \n",start_index,end_index);
        G->A[start_index][end_index] = weight;
        G->Adj_num++;
        getchar();
        scanf("%c %c %d", &start, &end, &weight);
    }
    return G;
}
void output_Graph(Graph *g)
{
    if(!g||g->Vertex_num==0)
    {
        return;
    }
    int i,j;
    printf("图中顶点数据：\n");
    for(i=0;i<g->Vertex_num;i++)
    {
        printf("%c\t",g->V[i]);
    }
    printf("\n图的邻接矩阵为：\n");
    for(i=0;i<g->Vertex_num;i++)
    {
        for(j=0;j<g->Vertex_num;j++)
        {
            if(g->A[i][j]==0)
                printf("#\t");
            else
                printf("%d\t",g->A[i][j]);
        }
        printf("\n");
    }
}
int visited[MAX_Vertex_Num]={0};

int find_Next_Adjvex(Graph *g,int v,int index)
{
    int i;
    for(i=index;i<g->Vertex_num;i++)
    {
        if(g->A[v][i]!=0&&visited[i]==0)
        {
            return i;
        }
    }
    return -1;
}

void DFS_Traval(Graph *g)
{
    int i;
    for(i=0;i<g->Vertex_num;i++)
    {
        DFS(g,i);
    }
}

void DFS(Graph *g,int v0)
{
    Graph *p=g;
    if(visited[v0]==0)
    {
        printf("%c",p->V[v0]);
        visited[v0]=1;
    }
    int v;
    for(v= find_Next_Adjvex(p,v0,0) ; v !=-1; v= find_Next_Adjvex(p,v0,v+1))
    {

        if(visited[v]==0)
        {
            DFS(p,v);
        }
    }
}

void BFS(Graph *g) {
    int i;
    if(!g||g->Vertex_num==0)
    {
        return;
    }

    for (i = 0; i < g->Vertex_num; i++)
    {
        visited[i]=0;
    }
    int start=0;
    fflush(stdout);
    scanf("%d",&start);
    printf("广度优先遍历算法：");
    SqQueue *q=InitQueue();
    EeQueue(q,start);
    visited[start]=1;
    int v;
    while(!QueueIsEmpty(q))
    {
        DeQueue(q,&start);
        printf("%c",g->V[start]);

        for(v= find_Next_Adjvex(g,start,0);v>=0;v= find_Next_Adjvex(g,start,v+1))
        {
            if(visited[v]==0)
            {
                EeQueue(q,v);
                visited[v]=1;
            }
        }
    }
}
//输入案例
//abcdefgh#
//a b 1
//a c 1
//b a 1
//b d 1
//b e 1
//d b 1
//d h 1
//h d 1
//h e 1
//e h 1
//e b 1
//c a 1
//c f 1
//c g 1
//f c 1
//f g 1
//g c 1
//g f 1
//# # 0
