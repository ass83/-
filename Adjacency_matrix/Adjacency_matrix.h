//
// Created by 陈宇轩 on 2024/8/2.
//

#ifndef GRAPH_ADJACENCY_MATRIX_H
#define GRAPH_ADJACENCY_MATRIX_H
#include "Seq_Queue.h"
typedef char Vextex_type;
typedef int Adj_type;
#define  MAX_Vertex_Num 256
typedef struct Graph
{
    Vextex_type V[MAX_Vertex_Num];
    Adj_type A[MAX_Vertex_Num][MAX_Vertex_Num];
    int Vertex_num;
    int Adj_num;
}Graph;

Graph *Create_Graph(void);
void output_Graph(Graph *g);
void DFS(Graph *g,int v0);
void DFS_Traval(Graph *g);
//int DeQueue(SqQueue * q, QElemType * d);
//int EeQueue(SqQueue * q, QElemType d);
void BFS(Graph *g);

#endif //GRAPH_ADJACENCY_MATRIX_H
