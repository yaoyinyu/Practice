#include<stdio.h>
#include<math.h>
int main()
{
	float a, b, c, s, area;
	printf("输入 a,b,c:");
	scanf("%f,%f,%f", &a, &b, &c);
	if (a + b > c && b + c > a && a + c > b)
	{
		s = (float)(a + b + c) / 2;
		area = sqrt(s * (s - a) * (s - b) * (s - c));
		printf("area = %.2f\n", area);
	}
	else
	{
		printf("您输入的数字无法构成三角形\n");
	}


	float n;
	double rate, capital, deposit;
	printf("输入利率，本金,存期:");
	scanf("%1f,%d,%1f", &rate, &n, &capital);
	deposit = capital * (1 + rate * n);
	printf("deposit = %.2f\n", deposit);

	printf("任意按一个键然后回车");
	char ch = getchar();
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
	{
		printf("您输入的是一个英文字母!\n");
	}
	else if (ch <= '9' && ch >= '0')
	{
		printf("您输入的是一个数字字符!\n");
 }
 else if (ch == ' ')
 {
	 printf("您输入的是一个空格字符!\n");
	}
 else
 {
	 printf("您输入的是一个其他字符!\n");
 }

 int a, b, c, d;
 scanf("%d,%d,%d", &a, &b, &c);
 d = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
 printf("%d\n", d);

 return 0;
}

