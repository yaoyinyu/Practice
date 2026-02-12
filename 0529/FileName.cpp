#include <stdio.h>

void Swap(int m, int n)
{
	int x = 0;
	x = m;
	m = n;
	n = x;

}

void Swap2(int *m, int *n)
{
	int x = 0;
	x = *m;
	*m = *n;
	*n = x;
}

int Add(int m, int n)
{
	int z = 0;
	z = m + n;
	return z;
}

int main()
{
	int a, b;
	scanf_s("%d %d", &a, &b);
	printf("a = %d, b = %d\n", a, b);

	Swap(a, b);
	printf("a = %d, b = %d\n", a, b);

	Swap2(&a, &b);
	printf("a = %d, b = %d\n", a, b);

	int c = Add(a, b);
	printf("c = %d\n", c);

	return 0;
}