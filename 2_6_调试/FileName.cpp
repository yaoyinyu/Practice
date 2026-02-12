#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>

int jch(int n)
{
	int i = 0;
	int ret = 1;
	int sum = 0;
	for (i = 1; i <= n; i++)
	{
		ret = ret * i;
		sum = sum + ret;
	}
	return sum;
}

//const静态化指针/变量
char* my_strcpy(char* arr1, const char* arr2)
{
	//int i = 0;
	//for (i = 0; i < 20; i++)
	//{
	//	arr1[i] = arr2[i];
	//}

	//while (*arr2 != '\0')
	//{
	//	*arr1 = *arr2;
	//	arr1++;
	//	arr2++;
	//}
	//*arr1 = *arr2;

	char* ret = arr1;
	//断言判断语句为假就中断编译
	assert(arr1 != NULL);
	assert(arr2 != NULL);
	while (*arr1++ = *arr2++);
	return ret;
}

//const静态化指针/变量
int my_strlen(const char* arr)
{
	int count = 0;
	int i = 0;
	//断言判断语句为假就中断编译
	assert(arr != NULL);
	while (*arr != '\0')
	{
		count++;
		arr++;
	}
	return count;
}

int main()
{
	//int i = 0;
	//for (i = 0; i <= 10; i++)
	//{
	//	printf("%d ", i);
	//}

	//printf("%d\n", jch(3));

	////int j = 0;
	////int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	////for (j = 0; j <= 12; j++)
	////{
	////	arr[j] = 0;
	////	printf("hehe\n");
	////}

	//char arr1[20] = "XXXXXXXXXXXXXXXXX";
	//char arr2[] = "hello beach";
	//printf("%s\n", my_strcpy(arr1, arr2));

	//char arr[] = "hello beach";
	//int len = my_strlen(arr);
	//printf("%d\n", len);

	int a, b, c;
	while ((scanf("%d %d %d", &a, &b, &c)) == 3)
	{
		if ((a + b > c) && (a + c > b) && (b + c > a))
		{
			if ((a == b) && (a == c) && (b == c))
				printf("是等边三角形");
			else if ((a == b) && (a != c) || (a == c) && (a != b) || (b == c) && (a != c))
				printf("是等腰三角形");
			else
				printf("是三角形");
		}
		else
			printf("不是三角形重新输入");
	}

	return 0;

}