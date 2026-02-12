#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int fac(int n) {
	if (n <= 1) {
		return 1;
	} else {
		return n * fac(n - 1);
	}
}

int fab(int a) {
	if (a <= 2) {
		return 1;
	} else {
		return fab(a - 1) + fab(a - 2);
	}
}

int fib2(int n) {
	int a = 1;
	int b = 1;
	int c = 1;
	while (n >= 3) {
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return  c;
}

int main() {
	int n = 0;
	scanf("%d", &n);
	int ret = fac(n);
	printf("%d\n", ret);

	int a = 0;
	scanf("%d", &a);
	//int fib1 = fab(a);
	int fib = fib2(a);
	//printf("%d\n", fib1);
	printf("%d\n", fib2);

	return 0;

}