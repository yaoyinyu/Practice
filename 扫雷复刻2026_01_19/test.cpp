#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void menu()
{
	printf("请选择选项：\n");
	printf("0.退出游戏\n");
	printf("1.开始游戏\n");
}

void game()
{
	char mine[ROWS][COLS] = {  };
	char show[ROWS][COLS] = {  };
	//初始化棋盘
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//展示棋盘
	ShowBoard(show, ROWS, COLS);
	//布置雷
	Lei(mine);
	ShowBoard(mine, ROWS, COLS);
	//判断输赢
	FindLei(mine,show);
}

int main()
{
	int choice;
	//设置随机数的生成起点
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("扫雷——开始游戏\n");
			game();
			break;
		case 0:
			printf("已退出游戏\n");
			break;
		default:
			printf("选择错误请重新选择\n");
			break;
		}
	} while (choice);

	return 0;

}