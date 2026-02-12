#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <stdlib.h>

int main()
{
	//int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//int i, mid;
	//int left = 0, right = 9;
	//scanf_s("%d", &i);
	//while (left <= right)
	//{
	//	//mid = (left + right) / 2;
	//	mid = left + (right - left) / 2;
	//	if (arr[mid] == i)
	//	{
	//		printf("找到了，下标是%d\n", mid-1);
	//		break;
	//	}
	//	else if (arr[mid] > i)
	//	{
	//		right = mid - 1;
	//	}
	//	else
	//	{
	//		left = mid + 1;
	//	}
	//}
	//if (left > right)
	//{
	//	printf("没有找到\n");
	//}

	//char arr1[] = "change world";
	//char arr2[] = "************";
	//int left = 0;
	//int right = strlen(arr1) - 1;
	////int right = sizeof(arr1) / sizeof(arr1[0]) - 2;
	//while (left <= right)
	//{
	//	arr2[left] = arr1[left];
	//	arr2[right] = arr1[right];
	//	printf("%s\n", arr2);
	//	Sleep(1000);   //Windows.h函数库下的Sleep函数，注意S大写
	//	//清空屏幕
	//	system("cls");   //system是个库函数，可以执行系统命令
	//	left++;
	//	right--;
	//}
	//printf("%s\n", arr2);

	int i = 0;
	char password[20] = { 0 };
	for (i = 0; i < 3; i++)
	{
		printf("输入密码：>");
		scanf_s("%s", password);
		while (getchar() != '\n');
		if (strcmp(password, "abc")==0)
		{
			printf("密码正确\n");
			break;
		}
		else
		{
			printf("密码错误\n");
		}

	}
	if (i == 3)
	{
		printf("密码错误三次，锁定\n");
	}


	return 0;

}