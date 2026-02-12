#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

int main()
{
	//int arr[10] = { 0 };
	//int i = 0;
	//int sz = sizeof(arr) / sizeof(arr[0]);
	//for (i = 0; i < sz; i++)
	//{
	//	scanf("%d", arr + i);
	//}
	//int left = 0;
	//int right = sz - 1;
	//while (left < right)
	//{
	//	while ((arr[left] % 2 == 0) || (left < right))
	//	{
	//		left++;
	//	}
	//	while ((arr[right] % 2 == 0) || (left < right))
	//	{
	//		right--;
	//	}
	//	if (left < right)
	//	{
	//		int tmp;
	//		tmp = arr[left];
	//		arr[left] = arr[right];
	//		arr[left] = tmp;
	//		left++;
	//		right--;
	//	}
	//}

	int arr1[1000] = {};
	int arr2[1000] = {};
	int m, n;
	int i = 0;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr1[i]);
	}
	for (i = 0; i < m; i++)
	{
		scanf("%d", &arr2[i]);
	}
	i = 0;
	int j = 0;
	while (i < n || j < m)
	{
		if (arr1[i] < arr2[j])
		{
			printf("%d ", arr1[i]);
			i++;
		}
		else
		{
			printf("%d ", arr2[j]);
			j++;
		}
	}
	if (i < n)
	{
		for (; i < n; i++)
			printf("%d ", arr1[i]);
	}
	else
	{
		for (; j < n; j++)
			printf("%d ", arr2[j]);
	}


	return 0;

}