#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menu()
{
	printf("0. 退出游戏\n");
	printf("1. 开始游戏\n");
}

void game()
{
	char mine[ROWS][COLS] = {};		//存放雷的信息
	InitBoard(mine, ROWS, COLS, '0');	//初始化棋盘
	char show[ROWS][COLS] = {};		//展示棋盘
	InitBoard(show, ROWS, COLS, '*');	//初始化棋盘
	SetMine(mine, ROW, COL);		//布置雷
	DisPlayBoard(show, ROWS, COLS);		//打印棋盘
	FindMine(mine, show, ROW, COL);		//排雷
}

int main()
{
	int choice = 0;
	//设置随机数的生成起点
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("输入选项\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("游戏开始\n");
			game();
			break;
		case 0:
			printf("游戏已退出\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (choice);

	return 0;

}