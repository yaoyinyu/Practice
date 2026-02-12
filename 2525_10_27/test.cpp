#include <stdio.h>
#include <stdlib.h>

// 定义状态码（成功/失败）
typedef int Status;
#define OK 1
#define ERROR 0

// 定义链表节点结构
typedef struct LNode {
    int data;               // 数据域
    struct LNode* next;     // 指针域（指向下一个节点）
} LNode, * LinkList;         // LNode为节点类型，LinkList为节点指针类型


/**
 * 初始化链表（创建头节点）
 * 返回：链表头指针（头节点）
 */
LinkList InitList() {
    // 分配头节点内存（头节点不存储实际数据，用于简化操作）
    LinkList L = (LNode*)malloc(sizeof(LNode));
    if (L == NULL) {        // 内存分配失败
        printf("初始化失败：内存不足\n");
        return NULL;
    }
    L->next = NULL;         // 空链表，头节点后无节点
    return L;
}


/**
 * 按位插入（在第i个位置插入元素e）
 * 参数：
 *   L：链表头指针（头节点）
 *   i：插入位置（i≥1）
 *   e：待插入元素
 * 返回：OK（成功）/ ERROR（失败）
 */
Status ListInsert(LinkList L, int i, int e) {
    if (i < 1) {            // 位置不合法（i必须≥1）
        return ERROR;
    }

    // 查找第i-1个节点（插入需修改前一个节点的指针）
    LNode* p = L;           // p从表头开始
    int j = 0;              // 当前p指向第j个节点（头节点为第0个）
    while (p != NULL && j < i - 1) {  // 循环到第i-1个节点
        p = p->next;
        j++;
    }

    if (p == NULL) {        // i超过链表长度（第i-1个节点不存在）
        return ERROR;
    }

    // 创建新节点并赋值
    LNode* s = (LNode*)malloc(sizeof(LNode));
    if (s == NULL) {        // 内存分配失败
        return ERROR;
    }
    s->data = e;

    // 插入新节点（先连后，再连前）
    s->next = p->next;
    p->next = s;

    return OK;
}


/**
 * 按位查找（查找第i个位置的节点）
 * 参数：
 *   L：链表头指针（头节点）
 *   i：查找位置（i≥1）
 * 返回：第i个节点的指针（失败返回NULL）
 */
LNode* GetElem(LinkList L, int i) {
    if (i < 1) {            // 位置不合法
        return NULL;
    }

    LNode* p = L->next;     // p指向第1个节点（头节点后第一个）
    int j = 1;              // 当前p指向第j个节点
    while (p != NULL && j < i) {  // 循环到第i个节点
        p = p->next;
        j++;
    }

    return p;               // 若p为NULL，说明i超过链表长度
}


/**
 * 打印链表所有元素
 */
void PrintList(LinkList L) {
    LNode* p = L->next;     // 从第一个节点开始
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}


// 测试主函数
int main() {
    // 初始化链表
    LinkList L = InitList();
    if (L == NULL) {
        return 1;
    }

    // 测试按位插入
    if (ListInsert(L, 1, 10) == OK) {
        printf("插入第1个位置（10）成功，当前链表：");
        PrintList(L);  // 输出：10
    }

    if (ListInsert(L, 2, 20) == OK) {
        printf("插入第2个位置（20）成功，当前链表：");
        PrintList(L);  // 输出：10 20
    }

    if (ListInsert(L, 1, 5) == OK) {
        printf("插入第1个位置（5）成功，当前链表：");
        PrintList(L);  // 输出：5 10 20
    }

    // 测试按位查找
    int i = 2;
    LNode* node = GetElem(L, i);
    if (node != NULL) {
        printf("第%d个元素：%d\n", i, node->data);  // 输出：第2个元素：10
    }
    else {
        printf("第%d个元素不存在\n", i);
    }

    i = 3;
    node = GetElem(L, i);
    if (node != NULL) {
        printf("第%d个元素：%d\n", i, node->data);  // 输出：第3个元素：20
    }
    else {
        printf("第%d个元素不存在\n", i);
    }

    i = 4;
    node = GetElem(L, i);
    if (node != NULL) {
        printf("第%d个元素：%d\n", i, node->data);
    }
    else {
        printf("第%d个元素不存在\n", i);  // 输出：第4个元素不存在
    }

    return 0;
}