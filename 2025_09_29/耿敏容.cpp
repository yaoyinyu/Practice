#include <stdio.h>
void main()
{
	int a, b;
	float x;
	printf("请输入两个整数a,b的值(用英文逗号隔开)：\n");
	scanf_s("%d,%d", &a, &b);
	x = 2 * a * b / ((a + b) * (a + b));
	printf("x=%f \n", x);

}