//#include <stdio.h>
//
//#define inf 10000       //无效路径
//#define n 8     //教学楼数
//
////成本
//int graph[n][n] = {
//    {inf, 5, 3, inf, inf, 8, inf, 6},   //A0
//    {5, inf, 2, 4, inf, inf, 7, inf},   //B1
//    {3, 2, inf, inf, 5, inf, inf, 4},   //C2
//    {inf, 4, inf, inf, inf, inf, 3, inf},   //D3
//    {inf, inf, 5, inf, inf, 2, inf, 3},  //E4
//    {8, inf, inf, inf, 2, inf, 1, inf},  //F5
//    {inf, 7, inf, 3, inf, 1, inf, inf},  //G6
//    {6, inf, 4, inf, 3, inf, inf, inf}   //H7
//};
//
////最小生成树，输出方案及成本
//void Prim() {
//    int lowcost[n];     //每个节点到当前生成树的最小成本
//    int adjvex[n];      //最小成本对应的生成树内节点
//    int total_cost = 0;     //成本
//    int i, j, k, min;
//
//    //构建生成树
//    for (i = 0; i < n; i++) {
//        lowcost[i] = graph[0][i];   //A到各节点的成本
//        adjvex[i] = 0;  //A0
//    }
//    lowcost[0] = 0;     //标记已加入生成树
//
//    //边
//    for (i = 1; i < n; i++) {
//        min = inf;
//        k = -1;
//
//        //找到成本最小的节点
//        for (j = 0; j < n; j++) {
//            if (lowcost[j] != 0 && lowcost[j] < min) {
//                min = lowcost[j];
//                k = j;
//            }
//        }
//
//        //输出当前边
//        char start_node = 'A' + adjvex[k];
//        char end_node = 'A' + k;
//        printf("布线：%c-%c，成本：%d万元\n", start_node, end_node, min);
//        total_cost += min;
//
//        lowcost[k] = 0;
//
//        //更新其他节点到生成树的最小成本
//        for (j = 0; j < n; j++) {
//            if (lowcost[j] != 0 && graph[k][j] < lowcost[j]) {
//                lowcost[j] = graph[k][j];
//                adjvex[j] = k;
//            }
//        }
//    }
//
//    printf("\n最低总成本：%d万元\n", total_cost);
//}
//
//int main() {
//    printf("最小生成树布线方案：\n");
//    Prim();
//
//    return 0;
//}