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

int main()
{
	enum Day d = Fri;
	printf("%d\n", Mon);
	printf("%d\n", Tues);
	printf("%d\n", Wed);

	return 0;

}