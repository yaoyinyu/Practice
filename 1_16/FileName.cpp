//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <string.h>
//
//void shuwei(int x)
//{
//	if (x < 10){
//		printf("%d\n", x);
//	}
//	else {
//		shuwei(x / 10);
//		printf("%d\n", x % 10);
//	}
//}
//
//int jiecheng(int x)
//{
//	if (x != 1 && x != 0)
//	{
//		return x * jiecheng(x - 1);
//	}
//	else
//		return 1;
//}
//
//void nixu(char arr[], int sz)
//{
//	int left = 0;
//	int right = sz - 2;
//	while (left < right)
//	{
//		char tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//}
//
//void jiaohuan(char arr[], int left, int right)
//{
//	if (left < right)
//	{
//		char tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//	}
//	else
//		return;
//	left++;
//	right--;
//	jiaohuan(arr, left, right);
//}
//
//int my_strlen(char* str)
//{
//	int count = 0;
//	while(*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//
//void reverse(char* str)
//{
//	char tmp = *str;
//	int len = my_strlen(str);
//	*str = *(str + len - 1);
//	*(str + len - 1) = '\0';
//	if (my_strlen(str + 1) >= 2)
//		reverse(str + 1);
//	*(str + len - 1) = tmp;
//}
//
//int qiuhe(int x)
//{
//	if (x < 10) {
//		return x;
//	}
//	else {
//		return qiuhe(x / 10) + x % 10;
//	}
//}
//
//double mi(double x, int y)
//{
//	if (y > 0)
//	{
//		return x * mi(x, y - 1);
//	}
//	else if (y == 0)
//	{
//		return 1.0;
//	}
//	else
//	{
//		return 1.0 / mi(x, -y);
//	}
//}
//
//
//int main()
//{
//	int n = 1729;
//	int x = 4;
//
//	shuwei(n);
//
//	printf("%d\n", jiecheng(x));
//
//	char arr[] = "abcdefg";
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int left = 0;
//	int right = sz - 2;
//	while (left < right)
//	{
//		char tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//	printf("循环：%s\n", arr);
//	nixu(arr, sz);
//	printf("逆序：%s\n", arr);
//	left = 0;
//	right = sz - 2;
//	jiaohuan(arr, left, right);
//	printf("交换：%s\n", arr);
//	reverse(arr);
//	printf("reverse：%s\n", arr);
//
//	printf("%d\n", qiuhe(n));
//
//	int z, y;
//	scanf("%d %d", &z, &y);
//	double ret = mi(z, y);
//
//	printf("%lf\n", ret);
//
//
//	return 0;
//}