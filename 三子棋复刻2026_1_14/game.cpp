#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

//初始化棋盘
void inboard(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

//打印棋盘
void displayboard(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		//打印每行元素
		for (j = 0; j < col; j++)
		{
			//打印棋盘元素
			printf(" %c ", board[i][j]);
			//打印分隔符
			if (j < col - 1)
			{
				printf("|");
			}
		}printf("\n");
		//打印分割行
		if (i < row - 1)
		{
			//除了最后一个元素
			for (j = 1; j <= col; j++)
			{
				printf("---");

				if (j < col)
				{
					printf("|");
				}
			}printf("\n");
		}
	}
}

//玩家移动
void playermove(char board[ROW][COL], int row, int col)
{
	printf("玩家下棋：\n");
	int i, j;
	while (1)
	{
		printf("请输入坐标\n");
		scanf("%d %d", &i, &j);
		if (i > 0 && i <= row && j > 0 && j <= col)
		{
			if (board[i - 1][j - 1] == ' ')
			{
				board[i - 1][j - 1] = '*';
				break;
			}
			else
			{
				printf("位置被占用请重新输入\n");
			}
		}
		else
		{
			printf("位置非法请重新输入\n");
		}
	}
}

//电脑移动
void computermove(char board[ROW][COL], int row, int col)
{
	printf("电脑下棋：\n");
	int i, j;
	while (1)
	{
		i = rand() % row;	// 0~row-1
		j = rand() % col;	// 0~col-1
		if (board[i][j] == ' ')
		{
			board[i][j] = '#';
			break;
		}
	}
}

//检查棋盘是否满
int isfull(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

//检查输赢
char checkwin(char board[ROW][COL], int row, int col)
{
	//横着
	int i, j, k;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j <= col - WIN_COUNT; j++)
		{
			if (board[i][j] == ' ')
				continue;
			int win = 1;
			for (k = 1; k < WIN_COUNT; k++)
			{
				if (board[i][j] != board[i][j + k])
				{
					win = 0;
					break;
				}
			}
			if (win)
				return board[i][j];
		}
	}

	//竖着
	for (j = 0; j < col; j++)
	{
		for (i = 0; i <= row - WIN_COUNT; i++)
		{
			if (board[i][j] == ' ')
				continue;
			int win = 1;
			for (k = 1; k < WIN_COUNT; k++)
			{
				if (board[i][j] != board[i + k][j])
				{
					win = 0;
					break;
				}
			}
			if (win)
				return board[i][j];
		}
	}

	//对角线（左上）
	for (i = 0; i <= row - WIN_COUNT; i++)
	{
		for (j = 0; j <= col - WIN_COUNT; j++)
		{
			if (board[i][j] == ' ')
				continue;
			int win = 1;
			for (k = 1; k < WIN_COUNT; k++)
			{
				if (board[i][j] != board[i + k][j + k])
				{
					win = 0;
					break;
				}
			}
			if (win)
				return board[i][j];
		}
	}
	//对角线（右上）
	for (i = 0; i <= row - WIN_COUNT; i++)
	{
		for (j = WIN_COUNT - 1; j < col; j++)
		{
			if (board[i][j] == ' ')
				continue;
			int win = 1;
			for (k = 1; k < WIN_COUNT; k++)
			{
				if (board[i][j] != board[i + k][j - k])
				{
					win = 0;
					break;
				}
			}
			if (win)
				return board[i][j];
		}
	}

	//平局
	if (isfull(board, ROW, COL))
	{
		return 'Q';
	}
	return 'C';
}