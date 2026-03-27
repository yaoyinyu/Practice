#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

enum Day
{
	Mon = 1,
	Tues,
	Wed,
	Thur,
	Fri,
	Sat,
	Sun
};

union Un
{
	int a;
	char c;
};

struct St
{
	int a; 
	char c;
};

int check_sys_un()
{
	union Un
	{
		char c;
		int i;
	}u;
	u.i = 1;
	return u.c;
}

int check_sys()
{
	int a = 1;
	return *(char*)&a;
}

int main()
{
	enum Day d = Fri;
	printf("%d\n", Mon);
	printf("%d\n", Tues);
	printf("%d\n", Wed);

	printf("\n");

	union Un u;
	struct St s;
	printf("%d\n", sizeof(u));
	printf("%d\n", sizeof(s));

	printf("%p\n", &u);
	printf("%p\n", &(u.a));
	printf("%p\n", &(u.c));

	printf("\n");

	int a = 1;
	int ret = check_sys();
	int ret_un = check_sys_un();
	if (ret_un == 1)
	{
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}

	return 0;

}