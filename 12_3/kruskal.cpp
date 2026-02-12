#include "1.h"
#include <stdio.h>
#include <stdlib.h>

//找环
static int find(int parent[], int x) {
    if (parent[x] != x) {
        parent[x] = find(parent, parent[x]);
    }
    return parent[x];
}

//合并
static void Union(int parent[], int x, int y) {
    int x_root = find(parent, x);
    int y_root = find(parent, y);
    if (x_root != y_root) {
        parent[y_root] = x_root;
    }
}

//边的排序
static int compare(const void* a, const void* b) {
    bian* edgeA = (bian*)a;
    bian* edgeB = (bian*)b;
    return edgeA->chengben - edgeB->chengben;
}

//k实现
void kruskal() {
    //整理所有有效边
    bian edges[] = {
        {0, 1, 5}, {0, 2, 3}, {0, 5, 8}, {0, 7, 6},
        {1, 2, 2}, {1, 3, 4}, {1, 6, 7},
        {2, 4, 5}, {2, 7, 4},
        {3, 6, 3},
        {4, 5, 2}, {4, 7, 3},
        {5, 6, 1}
    };
    int edge_count = sizeof(edges) / sizeof(edges[0]);

    //按成本升序排序边
    qsort(edges, edge_count, sizeof(bian), compare);

    //初始化并查集
    int parent[N];
    for (int i = 0; i < N; i++) {
        parent[i] = i;
    }

    int selected = 0;  //已选边数
    int total_cost = 0;

    printf("Kruskal布线：\n");
    //遍历边选不成环边
    for (int i = 0; i < edge_count && selected < N - 1; i++) {
        int s = edges[i].start;
        int e = edges[i].end;
        int w = edges[i].chengben;

        //检查是否形成环
        if (find(parent, s) != find(parent, e)) {
            char start = 'A' + s;
            char end = 'A' + e;
            printf("布线：%c-%c，成本：%d万\n", start, end, w);
            total_cost += w;
            selected++;
            Union(parent, s, e);  //合并
        }
    }
    printf("Kruskal最低成本：%d万\n", total_cost);
}