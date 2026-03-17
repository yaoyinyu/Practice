#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<assert.h>

void reverse(char* left, char* right)
{
	assert(left && right);
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}

void left_move(char arr[], int k)
{
	assert(arr);
	int len = strlen(arr);
	k %= len;
	int i = 0;
	for (i = 0; i < k; i++)
	{
		char tmp = arr[0];
		int j;
		for (j = 0; j < len - 1; j++)
		{
			arr[j] = arr[j + 1];
		}
		arr[len - 1] = tmp;
	}
}

void left_move_1(char arr[], int k)
{
	assert(arr);
	int len = strlen(arr);
	k %= len;
	reverse(arr, arr + k - 1);
	reverse(arr + k, arr + len - 1);
	reverse(arr, arr + len - 1);
}

int find_num(int arr[3][3], int *px, int *py, int k)
{
	int x = 0;
	int y = *py - 1;
	while (x <= *px - 1 && y >= 0)
	{
		if (k < arr[x][y])
			y--;
		else if (k > arr[x][y])
			x++;
		else
		{
			*px = x;
			*py = y;
			return 1;
		}
	}
	*px = -1;
	*py = -1;
	return 0;
}

struct Print
{
	int x;
	int y;
};

struct Print find_num_1(int arr[3][3], int r, int c, int k)
{
	int x = 0;
	int y = c - 1;
	struct Print p = { -1,-1 };
	while (x <= r - 1 && y >= 0)
	{
		if (k < arr[x][y])
			y--;
		else if (k > arr[x][y])
			x++;
		else
		{
			p.x = x;
			p.y = y;
			return p;
		}
	}
	return p;
}

int is_left_move(char arr1[], char arr2[])
{
	int len = strlen(arr1);
	int i = 0;
	for (i = 0; i < len; i++)
	{
		char tmp = arr1[0];
		int j = 0;
		for (j = 0; j < len; j++)
		{
			arr1[j] = arr1[j + 1];
		}
		arr1[len - 1] = tmp;
		if (strcmp(arr2, arr1) == 0)
			return 1;
	}
	return 0;
}

int is_left_move_1(char arr1[], char arr2[])
{
	int len1 = strlen(arr1);
	int len2 = strlen(arr2);
	if (len1 != len2)
		return 0;
	strncat(arr1, arr1, len1);
	char* ret = strstr(arr1, arr2);
	if (ret == NULL)
		return 0;
	else
		return 1;
}

int main()
{
	//int input;
	//scanf("%d", &input);
	//int sum = 0;
	//int i = 0;
	//while (input)
	//{
	//	int bit = input % 10;
	//	if (bit % 2 == 1)
	//	{
	//		bit = 1;
	//	}
	//	else
	//	{
	//		bit = 0;
	//	}
	//	sum += bit * pow(10, i);
	//	i++;
	//	input /= 10;
	//}
	//printf("%d\n", sum);

	//int n;
	//while (scanf("%d", &n) == 1)
	//{
	//	int i = 0;
	//	int j = 0;
	//	for (i = 0; i < n; i++)
	//	{
	//		for (j = 0; j < n; j++)
	//		{
	//			if (i + j < n - 1)
	//			{
	//				printf("  ");
	//			}
	//			else
	//			{
	//				printf("* ");
	//			}
	//		}
	//		printf("\n");
	//	}
	//}

	//double price = 0;
	//int m = 0;
	//int d = 0;
	//int flag = 0;
	//scanf("%lf %d %d %d", &price, &m, &d, &flag);
	//if (m == 11 && d == 11)
	//{
	//	price = price * 0.7 - flag * 50;
	//}
	//else if (m == 12 & d == 12)
	//{
	//	price = price * 0.8 - flag * 50;
	//}
	//if (price < 0.0)
	//	printf("%.2lf\n", 0);
	//else
	//{
	//	printf("%.2lf\n", price);
	//}

	//int a = 0;
	//int b = 0;
	//int c = 0;
	//int d = 0;
	//int e = 0;
	//for (a = 1; a <= 5; a++)
	//{
	//	for (b = 1; b <= 5; b++)
	//	{
	//		for (c = 1; c <= 5; c++)
	//		{
	//			for (d = 1; d <= 5; d++)
	//			{
	//				for (e = 1; e <= 5; e++)
	//				{
	//					if (((b == 2) + (a == 3)) == 1
	//						&& ((b == 2) + (e == 4)) == 1
	//						&& ((c == 1) + (d == 2)) == 1
	//						&& ((c == 5) + (d == 3)) == 1
	//						&& ((e == 4) + (a == 1)) == 1)
	//					{
	//						if (a * b * c * d * e == 120 && a + b + c + d + e == 15)
	//						{
	//							printf("a=%d b=%d c=%d d=%d e=%d\n", a, b, c, d, e);
	//						}
	//					}
	//				}
	//			}
	//		}
	//	}
	//}

	//int killer = 0;
	//for (killer = 'a'; killer <= 'd'; killer++)
	//{
	//	if ((killer != 'a') + (killer == 'c') + (killer == 'd') + (killer != 'd') == 3)
	//	{
	//		printf("%c\n", killer);
	//	}
	//}
	
	//int arr[10][10] = { 0 };
	//int i = 0;
	//int j = 0;
	//for (i = 0; i < 10; i++)
	//{
	//	for (j = 0; j <= i; j++)
	//	{
	//		if (j == 0)
	//			arr[i][j] = 1;
	//		if (j == i)
	//			arr[i][j] = 1;
	//		if (i >= 2 && j >= 1)
	//			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
	//	}
	//}
	//for (i = 0; i < 10; i++)
	//{
	//	for (j = 0; j <= i; j++)
	//	{
	//		printf("%d ", arr[i][j]);
	//	}
	//	printf("\n");
	//}

	//char arr[] = "abcdef";
	//int k = 0;
	//scanf("%d", &k);
	////left_move(arr, k);
	//left_move_1(arr, k);
	//printf("%s\n", arr);

	//int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
	//int k = 0;
	//scanf("%d", &k);
	//int a = 3;
	//int b = 3;
	//int ret = find_num(arr, &a, &b, k);
	//if (ret == 1)
	//	printf("第%d行 第%d列\n", a + 1, b + 1);
	//else
	//	printf("找不到\n");

	//struct Print ret1 = find_num_1(arr, 3, 3, k);
	//printf("第%d行 第%d列\n", ret1.x + 1, ret1.y + 1);

	//char arr1[20] = "abcdef";
	//char arr2[] = "cdefab";
	////int ret = is_left_move(arr1, arr2);
	//int ret = is_left_move_1(arr1, arr2);
	//if (ret == 1)
	//	printf("ok\n");
	//else
	//	printf("no\n");

	//int n = 0;
	//int m = 0;
	//scanf("%d %d", &n, &m);
	//int arr[10][10] = { 0 };
	//int i = 0;
	//int j = 0;
	//for (i = 0; i < n; i++)
	//{
	//	for (j = 0; j < m; j++)
	//	{
	//		scanf("%d", &arr[i][j]);
	//	}
	//}
	//for (i = 0; i < m; i++)
	//{
	//	for (j = 0; j < n; j++)
	//	{
	//		printf("%d ", arr[j][i]);
	//	}
	//	printf("\n");
	//}

	//int n = 0;
	//scanf("%d", &n);
	//int arr[10][10] = { 0 };
	//int i = 0;
	//int j = 0;
	//int flag = 1;	//是上三角矩阵
	//for (i = 0; i < n; i++)
	//{
	//	for (j = 0; j < n; j++)
	//	{
	//		scanf("%d", &arr[i][j]);
	//	}
	//}	
	//for (i = 0; i < n; i++)
	//{
	//	for (j = 0; j < i; j++)
	//	{
	//		if (arr[i][j] != 0)
	//		{
	//			flag = 0;
	//			goto end;
	//		}
	//	}
	//}
	//end:
	//	if (flag == 0)
	//		printf("no\n");
	//	else
	//		printf("yes\n");

	int n = 0;
	scanf("%d", &n);
	int arr[100] = { 0 };
	int flag1 = 0;
	int flag2 = 0;
	int i = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		if (i > 0)
		{
			if (arr[i] > arr[i - 1])
				flag1 = 1;
			else if (arr[i] == arr[i - 1]);
			else
				flag2 = 1;
		}
	}
	if (flag1 + flag2 <= 1)
		printf("yeah");
	else
		printf("no");

	
	
	return	0;

}