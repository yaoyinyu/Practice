#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char n)
{
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = n;
		}
	}
}

void DisPlayBoard(char board[ROWS][COLS], int rows, int cols)
{
	int i, j;
	for (j = 0; j < cols - 1; j++)
	{
		printf("%d ", j);
	}
	printf("\n");
	for (i = 1; i < rows - 1; i++)
	{
		printf("%d ", i);
		for (j = 1; j < cols - 1; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = COUNT;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

int get_mine_count(char board[ROWS][COLS], int x, int y)
{
	//return (board[x - 1][y - 1] +
	//	board[x][y - 1] +
	//	board[x + 1][y - 1] +
	//	board[x + 1][y] +
	//	board[x + 1][y + 1] +
	//	board[x][y + 1] +
	//	board[x - 1][y + 1] +
	//	board[x - 1][y] - 8 * '0');
	int i, j;
	int count = 0;
	for (i = -1; i <= 1; i++)
	{
		for (j = -1; j <= 1; j++)
		{
			count = count + board[x + i][y + j];
		}
	}
	return count - 9 * '0';
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x, y;
	int count = 0;
	int win = 0;		//找到非0的个数

	while (win < row * col - COUNT)
	{
		printf("请输入坐标：");
		scanf("%d %d", &x, &y);
		printf("\n");
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show[x][y] != '*')
			{
				printf("请重新选择坐标\n");
			}
			else
			{
				//是雷的话提示游戏结束
				if (mine[x][y] == '1')
				{
					printf("很遗憾你踩雷了\n");
					DisPlayBoard(mine, ROWS, COLS);
					break;
				}
				//不是雷的话统计周围的雷的数量
				else
				{
					win++;
					//统计mine数组中x，y周围的八个框中有几个雷
					count = get_mine_count(mine, x, y);
					show[x][y] = count + '0';
					DisPlayBoard(show, ROWS, COLS);
					printf("游戏继续\n");
				}
			}
		}
		else
		{
			printf("坐标有误，请重新输入坐标\n");
		}
	}
	if (win = row * col - COUNT)
	{
		printf("恭喜你，排雷成功\n");
		DisPlayBoard(mine, ROWS, COLS);
	}
}