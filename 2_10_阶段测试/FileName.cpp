#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

int cnt = 0;

int fib(int n)
{
	cnt++;
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}

void quannixu(char arr[], int len)
{
	int i = 0;
	int tmp = 0;
	for (i = 0; i < len / 2; i++)
	{
		tmp = arr[i];
		arr[i] = arr[len - i - 1];
		arr[len - i - 1] = tmp;
	}
}

void nixu(char arr[],int len)
{
	int i = 0;
	int left = 0;
	for (i = 0; i <= len; i++)
	{
		if (arr[i] == ' ' || arr[i] == '\0' || arr[i] == '.')
		{
			quannixu(arr + left, i - left);
			left = i + 1;
		}

		//for (j = len-1; j >= 0; j--)
		//{
		//	if (arr[i] != ' ')
		//	{
		//		int tmp = arr[i];
		//		arr[i]=arr[j]
		//	}
		//}
	}
	quannixu(arr, len);
}

int main()
{
	//fib(8);
	//printf("%d\n", cnt);

	//int a = 0;
	//int b = 0;
	//scanf("%d %d", &a, &b);
	//int i = 0;
	////for (i = (a > b ? a : b); i <= a * b; i++)
	////{
	////	if (i % a == 0 && i % b == 0)
	////		break;
	////}
	////printf("%d\n", i);


	//for (i = 1;; i++)
	//{
	//	if ((a * i) % b == 0)
	//		break;
	//}

	//printf("%d\n", (a * i));

	char arr[] = { "I like Beijing." };
	int i = 0;
	int len = strlen(arr);
	nixu(arr, len);
	for (i = 0; i < len; i++)
	{
		printf("%c", arr[i]);
	}

	return 0;

}