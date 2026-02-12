#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100  // 集合最大容量
// 集合结构体定义
typedef struct {
    int elements[MAX_SIZE];
    int size;
} Set;
// 全局集合实例
Set setA, setB, resultSet;
// 函数声明
void initSet(Set* s);                  // 初始化集合
int isExist(Set* s, int elem);         // 判断元素是否存在
int findIndex(Set* s, int elem);       // 查找元素下标
void addElement(Set* s, int elem);     // 添加元素
void deleteElement(Set* s, int elem);  // 删除元素
void traverseSet(Set* s);              // 遍历集合
void clearSet(Set* s);                 // 清空集合
void unionSet(Set* a, Set* b, Set* res);// 并集运算
void intersectionSet(Set* a, Set* b, Set* res);// 交集运算
void differenceSet(Set* a, Set* b, Set* res, int type);// 差集运算
void showMainMenu();                   // 展示主菜单
void showSetMenu(Set* s, char setName);// 展示集合管理子菜单

void initSet(Set* s) {
    // 清空元素数组，重置元素个数
    for (int i = 0; i < MAX_SIZE; i++) {
        s->elements[i] = 0;
    }
    s->size = 0;
}

int isExist(Set* s, int elem) {
    for (int i = 0; i < s->size; i++) {
        if (s->elements[i] == elem) {
            return 1;
        }
    }
    return 0;
}

int findIndex(Set* s, int elem) {
    for (int i = 0; i < s->size; i++) {
        if (s->elements[i] == elem) {
            return i;  // 找到返回下标
        }
    }
    return -1;  // 未找到返回-1
}

void addElement(Set* s, int elem) {
    // 检查集合是否已满
    if (s->size >= MAX_SIZE) {
        printf("错误：集合已满，无法添加元素！\n");
        return;
    }
    // 检查元素是否已存在
    if (isExist(s, elem)) {
        printf("错误：元素%d已存在，添加失败！\n", elem);
        return;
    }
    // 添加元素到数组末尾
    s->elements[s->size] = elem;
    s->size++;
    printf("成功：元素%d已添加到集合！\n", elem);
}

void deleteElement(Set* s, int elem) {
    int index = findIndex(s, elem);
    if (index == -1) {
        printf("错误：元素%d不存在，删除失败！\n", elem);
        return;
    }
    // 元素前移覆盖目标位置
    for (int i = index; i < s->size - 1; i++) {
        s->elements[i] = s->elements[i + 1];
    }
    s->size--;
    printf("成功：元素%d已从集合中删除！\n", elem);
}

void traverseSet(Set* s) {
    if (s->size == 0) {
        printf("空集合\n");
        return;
    }
    printf("{");
    for (int i = 0; i < s->size; i++) {
        printf("%d", s->elements[i]);
        if (i != s->size - 1) {
            printf(", ");
        }
    }
    printf("}\n");
}

void clearSet(Set* s) {
    initSet(s);
    printf("成功：集合已清空！\n");
}

void unionSet(Set* a, Set* b, Set* res) {
    initSet(res);  // 初始化结果集合
    // 添加集合A的所有元素
    for (int i = 0; i < a->size; i++) {
        addElement(res, a->elements[i]);
    }
    // 添加集合B中不存在于结果集合的元素
    for (int i = 0; i < b->size; i++) {
        addElement(res, b->elements[i]);
    }
    // 输出并集结果
    printf("\n并集运算结果（A∪B）：");
    traverseSet(res);
}


void intersectionSet(Set* a, Set* b, Set* res) {
    initSet(res);  // 初始化结果集合
    // 遍历集合A，筛选在集合B中存在的元素
    for (int i = 0; i < a->size; i++) {
        int elem = a->elements[i];
        if (isExist(b, elem)) {
            addElement(res, elem);
        }
    }
    // 输出交集结果
    printf("\n交集运算结果（A∩B）：");
    traverseSet(res);
}

void differenceSet(Set* a, Set* b, Set* res, int type) {
    initSet(res);  // 初始化结果集合
    if (type == 0) {
        // 计算A-B：属于A但不属于B的元素
        for (int i = 0; i < a->size; i++) {
            int elem = a->elements[i];
            if (!isExist(b, elem)) {
                addElement(res, elem);
            }
        }
        printf("\n差集运算结果（A-B）：");
    }
    else {
        // 计算B-A：属于B但不属于A的元素
        for (int i = 0; i < b->size; i++) {
            int elem = b->elements[i];
            if (!isExist(a, elem)) {
                addElement(res, elem);
            }
        }
        printf("\n差集运算结果（B-A）：");
    }
    traverseSet(res);
}

void showMainMenu() {
    printf("\n=====================集合运算系统=====================\n");
    printf("0. 退出系统\n");
    printf("1. 集合A管理\n");
    printf("2. 集合B管理\n");
    printf("3. 并集运算（A∪B）\n");
    printf("4. 交集运算（A∩B）\n");
    printf("5. 差集运算\n");
    printf("=====================================================\n");
    printf("请输入操作序号：");
}

void showSetMenu(Set* s, char setName) {
    int choice, elem;
    while (1) {
        printf("\n=====================%c集合管理=====================\n", setName);
        printf("0. 返回主菜单\n");
        printf("1. 添加元素\n");
        printf("2. 删除元素\n");
        printf("3. 查看集合\n");
        printf("4. 清空集合\n");
        printf("=====================================================\n");
        printf("请输入操作序号：");
        scanf("%d", &choice);
        system("cls");  // 清屏（Windows系统）
        switch (choice) {
        case 0:
            return;  // 返回主菜单
        case 1:
            printf("请输入要添加的整数元素：");
            scanf("%d", &elem);
            addElement(s, elem);
            break;
        case 2:
            printf("请输入要删除的整数元素：");
            scanf("%d", &elem);
            deleteElement(s, elem);
            break;
        case 3:
            printf("%c集合当前内容：", setName);
            traverseSet(s);
            break;
        case 4:
            clearSet(s);
            break;
        default:
            printf("错误：无效的操作序号，请重新输入！\n");
            break;
        }
        printf("\n按任意键继续...");
        getchar();  // 吸收换行符
        getchar();  // 等待按键
        system("cls");
    }
}

int main() {
    int choice, diffType;
    // 初始化集合
    initSet(&setA);
    initSet(&setB);
    initSet(&resultSet);
    while (1) {
        showMainMenu();
        scanf("%d", &choice);
        system("cls");
        switch (choice) {
        case 0:
            printf("感谢使用集合运算系统，再见！\n");
            return 0;
        case 1:
            showSetMenu(&setA, 'A');
            break;
        case 2:
            showSetMenu(&setB, 'B');
            break;
        case 3:
            printf("正在执行并集运算（A∪B）...\n");
            unionSet(&setA, &setB, &resultSet);
            break;
        case 4:
            printf("正在执行交集运算（A∩B）...\n");
            intersectionSet(&setA, &setB, &resultSet);
            break;
        case 5:
            printf("请选择差集类型：\n");
            printf("0. A-B\n");
            printf("1. B-A\n");
            printf("请输入序号：");
            scanf("%d", &diffType);
            if (diffType != 0 && diffType != 1) {
                printf("错误：无效的差集类型！\n");
                break;
            }
            printf("正在执行差集运算...\n");
            differenceSet(&setA, &setB, &resultSet, diffType);
            break;
        default:
            printf("错误：无效的操作序号，请重新输入！\n");
            break;
        }
        if (choice >= 3 && choice <= 5) {
            printf("\n按任意键继续...");
            getchar();
            getchar();
            system("cls");
        }
    }
    return 0;
}
