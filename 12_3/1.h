#pragma once
#ifndef GRAPH_UTILS_H
#define GRAPH_UTILS_H

#define N 8          //楼数量
#define inf 10000    //无路径

//邻接矩阵
extern int graph[N][N];

//Kruskal边
typedef struct bian {
    int start;   
    int end;     
    int chengben;
} bian;

void prim();

void kruskal();

#endif