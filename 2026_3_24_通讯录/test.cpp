#define _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"

enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};

void menu()
{
	printf("1.add      2.del\n");
	printf("3.search   4.modify\n");
	printf("5.show     6.sort\n");
	printf("0.exit\n");
}

int main()
{
	int input = 0;

	Contact con;	//创建通讯录
	//初始化通讯录
	Inintcontact(&con);

	do
	{
		menu();
		printf("请选择序号：");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContcat(&con);
			break;
		case SEARCH:
			SearchContcat(&con);
			break;
		case MODIFY:
			ModifyContcat(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			SostContact(&con);
			break;
		case EXIT:
			DestroyContact(&con);
			printf("已退出通讯录");
			break;
		default:
			printf("输入错误请重新输入序号\n");
		}
	} while (input);

	return 0;

}