#include <stdio.h>
#include "Add.h"	//在用户定义的库中包含头文件	
//导入lib静态库文件
#pragma comment(lib, "Add.lib")	//链接到用户定义的库

void print(unsigned int i) {
	if(i > 9) {
		print(i / 10); //递归调用
		printf("%d\n", i); //输出当前位
	}
	printf("%d\n", i % 10); //输出当前位
}

int main() {
	//int n, m, k, l;
	//printf("Enter two integers (n and m): ");
	//scanf_s("%d %d", &n, &m);

	//k = Add(n, m);
	//printf("The result stored in k is: %d\n", k);

	unsigned int i = 0;
	printf("Enter an unsigned integer: ");	
	scanf_s("%u", &i);
	printf("The value of i is: %u\n", i);

	//while (i)
	//{
	//	printf("%d\n", i % 10);
	//	i = i / 10;	
	//}

	print(i); //调用递归函数打印每一位

	return 0;
}