#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu()
{
	printf("0. 退出游戏\n");
	printf("1. 开始游戏\n");
}

void game()
{
	char ret = 'C';
	//创建棋盘
	char board[ROW][COL] = { 0 };
	//初始化棋盘
	inboard(board, ROW, COL);
	displayboard(board, ROW, COL);
	while(1)
	{
		//玩家移动
		playermove(board, ROW, COL);
		//检查输赢
		ret = checkwin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		displayboard(board, ROW, COL);
		//电脑移动
		computermove(board, ROW, COL);
		//检查输赢
		ret = checkwin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		displayboard(board, ROW, COL);

	}
	if (ret == '*')
	{
		printf("玩家获胜！\n");
		printf("最终棋盘：\n");
		displayboard(board, ROW, COL);
	}
	else if (ret == '#')
	{
		printf("电脑获胜！\n");
		printf("最终棋盘：\n");
		displayboard(board, ROW, COL);
	}
	else
	{
		printf("平局\n");
		printf("最终棋盘：\n");
		displayboard(board, ROW, COL);
	}
}

int main()
{
	srand((unsigned int)time(NULL));	//随机值重置一次
	int choice = 0;
	printf("请选择项目\n");
	do
	{
		menu();
		scanf("%d", &choice);
		switch(choice)
		{
		case 1:
			game();
			break;
		case 0:
			printf("您已退出游戏\n");
			break;
		default:
			printf("输入有误，请重新输入\n");
			break;
		}
	} while (choice);

	return 0;

}