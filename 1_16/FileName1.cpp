#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int my_strlen(char* str)
{
	int count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}

void jiaohuan(char* str1, char* str2, int sz)
{
	//int sz = my_strlen(str1);
	int i;
	for (i = 0; i < sz; i++)
	{
		int tmp;
		tmp = *str1;
		*str1 = *str2;
		*str2 = tmp;
		str1++;
		str2++;
	}
}

void init(int arr[], int sz)
{
	int i;
	for (i = 0; i < sz; i++)
	{
		arr[i] = 0;
	}
}

void print(int arr[], int sz)
{
	int i;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void reverse(int arr[], int sz)
{
	int left = 0;
	int right = sz - 1;
	while (left<right)
	{
		int tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}
}

void maopao(int arr[], int sz)
{
	int i;
	for (i = 0; i < sz - 1; i++)
	{
		int j;
		for (j = 0; j < sz - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp=arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}


int main()
{
	//char arr1[] = { "1,3,5,7,9" };
	//char arr2[] = { "2,4,6,8,0" };
	//int sz = sizeof(arr1) / sizeof(arr1[0]);
	//jiaohuan(arr1, arr2, sz);

	//printf("%s\n%s\n", arr1, arr2);

	int arr[] = { 1,2,3,4,5,6,7,8,9,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	reverse(arr, sz);
	print(arr, sz);
	init(arr, sz);
	print(arr, sz);

	int arr1[] = { 5,9,2,4516,2,874,6 };
	int sz1 = sizeof(arr1) / sizeof(arr1[0]);

	maopao(arr1, sz1);
	print(arr1, sz1);


	return 0;

}