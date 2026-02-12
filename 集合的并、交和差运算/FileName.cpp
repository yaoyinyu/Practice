//#include <stdio.h>
//
//// 定义集合类型，使用位向量表示
//typedef unsigned int Set;
//
//// 创建一个空集
//Set createSet() {
//    return 0;
//}
//
//// 向集合中添加一个元素（元素值为0-31）
//Set addElement(Set set, int element) {
//    if (element >= 0 && element < 32) {
//        set |= (1 << element); // 将对应位设置为1
//    }
//    return set;
//}
//
//// 从集合中移除一个元素
//Set removeElement(Set set, int element) {
//    if (element >= 0 && element < 32) {
//        set &= ~(1 << element); // 将对应位设置为0
//    }
//    return set;
//}
//
//// 检查元素是否在集合中
//int isElement(Set set, int element) {
//    if (element >= 0 && element < 32) {
//        return (set & (1 << element)) != 0; // 检查对应位是否为1
//    }
//    return 0;
//}
//
//// 计算两个集合的并集
//Set unionSet(Set a, Set b) {
//    return a | b; // 按位或操作
//}
//
//// 计算两个集合的交集
//Set intersectSet(Set a, Set b) {
//    return a & b; // 按位与操作
//}
//
//// 计算两个集合的差集 (a - b)
//Set differenceSet(Set a, Set b) {
//    return a & (~b); // a 与 b 的补集进行按位与
//}
//
//// 打印集合中的所有元素
//void printSet(Set set) {
//    int i;
//    printf("{ ");
//    for (i = 0; i < 32; i++) {
//        if (isElement(set, i)) {
//            printf("%d ", i);
//        }
//    }
//    printf("}\n");
//}
//
//int main() {
//    // 创建两个集合 A 和 B
//    Set A = createSet();
//    Set B = createSet();
//
//    // 向集合 A 添加元素
//    A = addElement(A, 1);
//    A = addElement(A, 3);
//    A = addElement(A, 5);
//    A = addElement(A, 7);
//
//    // 向集合 B 添加元素
//    B = addElement(B, 3);
//    B = addElement(B, 6);
//    B = addElement(B, 7);
//    B = addElement(B, 9);
//
//    // 打印原始集合
//    printf("集合 A: ");
//    printSet(A);
//    printf("集合 B: ");
//    printSet(B);
//
//    // 计算并集
//    Set unionAB = unionSet(A, B);
//    printf("并集 A ∪ B: ");
//    printSet(unionAB);
//
//    // 计算交集
//    Set intersectAB = intersectSet(A, B);
//    printf("交集 A ∩ B: ");
//    printSet(intersectAB);
//
//    // 计算差集
//    Set differenceAB = differenceSet(A, B);
//    printf("差集 A - B: ");
//    printSet(differenceAB);
//
//    Set differenceBA = differenceSet(B, A);
//    printf("差集 B - A: ");
//    printSet(differenceBA);
//
//    // 检查元素是否在集合中
//    int element = 3;
//    if (isElement(A, element)) {
//        printf("元素 %d 在集合 A 中\n", element);
//    }
//    else {
//        printf("元素 %d 不在集合 A 中\n", element);
//    }
//
//    // 从集合 A 中移除元素 5
//    A = removeElement(A, 5);
//    printf("移除元素 5 后的集合 A: ");
//    printSet(A);
//
//    return 0;
//}