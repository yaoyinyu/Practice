#include <stdio.h>

int main() {
    float shuxue, yingyu, c_yuyan, pingjun;
    printf("请输入数学成绩: ");
    scanf_s("%f", &shuxue);
    printf("请输入英语成绩: ");
    scanf_s("%f", &yingyu);
    printf("请输入C语言成绩: ");
    scanf_s("%f", &c_yuyan);
    pingjun = (shuxue + yingyu + c_yuyan) / 3.0;
    printf("三门课程的平均成绩是: %.2f\n", pingjun);
    printf("耿敏容");
    return 0;
}