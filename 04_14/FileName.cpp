#include <stdio.h>

int main() {
 //   int arr[] = { 73,32,99,97,110,32,100,111,32,105,116,33 };
	//int sz = sizeof(arr) / sizeof(arr[0]);
	//int i = 0;
	//while (i <= sz)
	//{
	//	if (arr[i] == 0)
	//		break;
	//	putchar(arr[i]);
	//	i++;
	//}
	//putchar('\n');

        //int n;
        //printf("请输入一个正整数：");
        //scanf_s("%d", &n);

        //if (n < 1) {
        //    printf("请输入有效的正整数！\n");
        //    return 1;
        //}

        //int arr[100]; // 假设输入值不超过 99，可根据实际需求调整数组大小
        //arr[1] = 1;    // 1! = 1
        //int sum = arr[1]; // 先累加 1!

        //for (int i = 2; i <= n; i++) {
        //    arr[i] = arr[i - 1] * i; // 递推计算 i!（利用前一个数的阶乘）
        //    sum += arr[i];            // 累加当前阶乘
        //}

        //printf("1! 到 %d! 的累加结果为：%d\n", n, sum);
        //return 0;

 //   int n;
 //   int ret;
 //   int sum;
	//for (n = 1; n <= 10; n++)
	//{
	//	ret = 1;
	//	sum = 0;
	//	for (int i = 1; i <= n; i++)
	//	{
	//		ret *= i;
	//		sum += ret;
	//	}
	//	printf("1! + 2! + ... + %d! = %d\n", n, sum);
	//}

	//int n,ret = 1,sum = 1;
	//for(n = 1; n <= 10; n++)
	//{
	//	ret = ret * n;
	//	sum = sum + ret;
	//}
	//printf("1! + 2! + ... + %d! = %d\n", --n, sum);

	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int left = 0, right = 9,mid;
	int i;
	scanf_s("%d", &i);
	while (left<=right)
	{
		mid = (left + right) / 2;
		if (arr[mid] == i)
		{
			printf("找到了！下标是：%d\n", mid);
			break;
		}
		else if (arr[mid] < i)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	if (left > right)
	{
		printf("没有找到！\n");
	}
	return 0;
}