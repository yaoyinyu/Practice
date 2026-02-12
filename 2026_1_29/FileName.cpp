#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

//&按位与…………登陆验证，账号+密码，同真才真，一假则假。
//|按位或…………付款方式，微信/支付宝/现金，有真就真，全假才假。
//^按位异或…………吃饭，米饭/面条只能选一个不能全都要，相异为真，相同为假。
//异或支持交换律

struct stu
{
	char name[20];
	int age = 0;
	double score = 0;
};

void set_stu(struct stu *ss)
{
	strcpy(ss->name, "zhangsan");
	ss->age = 20;
	ss->score = 100.0;
};

void print_stu(struct stu ss)
{
	printf("%s %d %lf\n", ss.name, ss.age, ss.score);
};

int main()
{
	int a = 3;
	int b = 5;
	//printf("a=%d, b=%d\n", a, b);
	//a = a + b;
	//b = a - b;
	//a = a - b;
	//printf("a=%d, b=%d\n", a, b);	//溢出风险
	//a = a ^ b;	//a = 5^3
	//b = a ^ b;	//b = 5^3^3
	//a = a ^ b;	//a = 5^3^5^3^3
	//printf("a=%d, b=%d\n", a, b);	//只能处理整数，且运行效率较低

	//int count = 0;
	//while (a != 0)
	//{
	//	count++;
	//	a = a& (a - 1);
	//}
	//printf("a有%d个1", count);


	//&&逻辑与，同真则真，有假就假（并且）
	//	左边为真，右边就不计算了
	//||逻辑或，同假则假，有真则真（或者）
	//	左边为假，右边就不计算了
	int c = a && b;
	printf("%d\n", c);

	struct stu s = { 0 };
	set_stu(&s);
	print_stu(s);


	return  0;

}