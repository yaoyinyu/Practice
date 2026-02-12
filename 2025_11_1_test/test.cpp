#define _CRT_SECURE_NO_WARNINGS  // 添加这行，禁用安全警告
#include <stdio.h>

void print(unsigned int num)
{
    if (num > 9)
    {
        print(num / 10);
    }
    printf("%d", num % 10);
}

int main()
{
    unsigned int a;
    scanf("%u", &a);  // 补充：%u是unsigned int的格式符（原%d也能运行，但不规范）
    print(a);

    return 0;
}