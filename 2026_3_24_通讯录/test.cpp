#define _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"

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
		case 1:
			AddContact(&con);
			break;
		case 2:
			DelContcat(&con);
			break;
		case 3:
			SearchContcat(&con);
			break;
		case 4:
			ModifyContcat(&con);
			break;
		case 5:
			ShowContact(&con);
			break;
		case 6:
			SostContact(&con);
			break;
		case 0:
			printf("已退出通讯录");
			break;
		default:
			printf("输入错误请重新输入序号\n");
		}
	} while (input);

	return 0;

}