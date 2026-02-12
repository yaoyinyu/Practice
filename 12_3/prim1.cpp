#include "1.h"
#include <stdio.h>

//输入图
int graph[N][N] = {
    {inf, 5, 3, inf, inf, 8, inf, 6},   //A0
    {5, inf, 2, 4, inf, inf, 7, inf},   //B1
    {3, 2, inf, inf, 5, inf, inf, 4},   //C2
    {inf, 4, inf, inf, inf, inf, 3, inf}, //D3
    {inf, inf, 5, inf, inf, 2, inf, 3},  //E4
    {8, inf, inf, inf, 2, inf, 1, inf},  //F5
    {inf, 7, inf, 3, inf, 1, inf, inf},  //G6
    {6, inf, 4, inf, 3, inf, inf, inf}   //H7
};

//方案+总成本
void prim() {
    int lowcost[N];  //节点到当前生成树的最小成本
    int adjvex[N];   //最小成本对应的生成树内节点
    int total_cost = 0;
    int i, j, k, min;

    //初始化从A0
    for (i = 0; i < N; i++) {
        lowcost[i] = graph[0][i];
        adjvex[i] = 0;
    }
    lowcost[0] = 0;  //标记A已加入生成树

    printf("Prim布线：\n");
    //选择N-1条边
    for (i = 1; i < N; i++) {
        min = inf;
        k = -1;

        //找未加入树且成本最小的节点
        for (j = 0; j < N; j++) {
            if (lowcost[j] != 0 && lowcost[j] < min) {
                min = lowcost[j];
                k = j;
            }
        }

        //输出当前边
        char start = 'A' + adjvex[k];
        char end = 'A' + k;
        printf("布线：%c-%c，成本：%d万\n", start, end, min);
        total_cost += min;

        //标记已加入
        lowcost[k] = 0;

        //更新最小成本
        for (j = 0; j < N; j++) {
            if (lowcost[j] != 0 && graph[k][j] < lowcost[j]) {
                lowcost[j] = graph[k][j];
                adjvex[j] = k;
            }
        }
    }
    printf("Prim最低成本：%d万\n\n", total_cost);
}