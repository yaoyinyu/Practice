#include <stdio.h>
#include <math.h>   //sqrt算数平方根

int su(int a) {
	if(a < 2) 
		return 0; // 0和1不是素数
	for(int i = 2; i * i <= a; i++) { //i <= sqrt(a)
		if(a % i == 0) 
			return 0; // 如果能被i整除，则不是素数
	}
	return 1; // 是素数
}

int run(int b) {
	if(b % 4 == 0 && b % 100 != 0 || b % 400 == 0) {
		return 1; // 是闰年
	} else {
		return 0; // 不是闰年
	}
}

int erfen(int arr[], int sz, int k) {
	int left = 0;
	int right = sz - 1;
	while(left <= right) {
		int mid = (left + (right - left)) / 2; // 中间位置   (right - left)/2防止溢出
		if(arr[mid] < k) {
			left = mid + 1; // 在右半部分
		} else if(arr[mid] > k) {
			right = mid - 1; // 在左半部分
		} else {
			return mid; // 找到k，返回下标
		}
	}
	return -1; // 如果没有找到，返回-1
}

int cha(int arr[], int sz, int k) {
	for(int i = 0; i < sz; i++) {
		if(arr[i] == k) {
			return i; // 返回k的下标
		}
	}
	return -1; // 如果没有找到，返回-1
}

void Add(int *num) {
	*num += 1; // 每次递归num加1
}

int main() {
	int a;
	printf("请输入一个整数：");
	scanf_s("%d", &a);
	for(;a <= 100; a++) {
		if(su(a)) {
			printf("100以内%d是素数\n", a);
		} else {
			printf("100以内%d不是素数\n", a);
		}
	}
 
	int b;
	printf("请输入一个年份：");
	scanf_s("%d", &b);
	if(run(b)) {
		printf("%d是闰年\n", b);
	} else {
		printf("%d不是如年\n", b);
	}

	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	//int k;
	//printf("请输入要查找的数字：");
	//scanf_s("%d", &k);
	//int sz = sizeof(arr) / sizeof(arr[0]);
	//int ret = cha(arr, sz, k);
	//if(ret == -1) {
	//	printf("数组中没有%d\n", k);
	//} else {
	//	printf("数组中%d的下标是%d\n", k, ret);
	//}
	//int ret_2 = erfen(arr, sz, k);
	//if(ret_2 != -1) {
	//	printf("二分查找：数组中%d的下标是%d\n", k, erfen(arr, sz, k));
	//} else {
	//}

	int num = 0;
	Add(&num);
	printf("递归结束%d\n", num);	// 递归调用Add函数，num值为1
	Add(&num);
	printf("递归结束%d\n", num);	// 再次调用Add函数，num值为2
	Add(&num);
	printf("递归结束%d\n", num);	// 再次调用Add函数，num值为3
	Add(&num);
	printf("递归结束%d\n", num);	// 再次调用Add函数，num值为4

	int len = sizeof(arr) / sizeof(arr[0]);
	for(int i = 0; i < len; i++) {
		printf("%d\n", arr[i]); // 打印数组元素
	}

	int len_2 = sizeof(arr) / sizeof(arr[0]);
	printf("\n数组长度为：%d\n", len_2); // 打印数组长度

	printf("数组的长度是%d\n", sizeof(arr) / sizeof(arr[0])); // 打印数组长度

	printf("%d", printf("%d", printf("%s", "Hello, World!"))); // 打印嵌套printf的结果

	return 0;

}