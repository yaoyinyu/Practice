#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

//初始化棋盘
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

//展示棋盘
void ShowBoard(char board[ROWS][COLS], int rows, int cols)
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

//布置雷
void Lei(char board[ROWS][COLS])
{
	int count = Lei_Count;
	int x, y;
	while (count)
	{
		x = rand() % ROW + 1;
		y = rand() % COL + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

int QiuHe(char board[ROWS][COLS],int x,int y)
{
	int ret = 0;
	int i, j;
	for (i = x - 1; i <= x + 1; i++)
	{
		for (j = y - 1; j <= y + 1; j++)
		{
			ret = ret + board[i][j];
		}
	}
	return ret - 9 * '0';
}

//展开一片
void ZhanKai(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int *choice)
{
	if (x<1 || x>ROW || y<1 || y>COL)
	{
		return;
	}
	if (show[x][y]!= '*')
	{
		return;
	}
	show[x][y] = QiuHe(mine, x, y) + '0';
	(*choice)++;
	if (QiuHe(mine, x, y) == 0)
	{
		int i, j;
		for (i = x - 1; i <= x + 1; i++)
		{
			for (j = y - 1; j <= y + 1; j++)
			{
				ZhanKai(mine, show, i, j, choice);
			}
		}
	}
}

//找雷
void FindLei(char mine[ROWS][COLS], char show[ROWS][COLS])
{
	int x, y, a;
	int count = 0;
	while (count < ROW * COL - Lei_Count)
	{
		printf("1.标记/取消雷\n");
		printf("2.扫雷\n");
		printf("请输入操作类型：\n");
		scanf("%d", &a);
		printf("请输入操作坐标：");
		scanf("%d %d", &x, &y);
		printf("\n");
		if (a == 1)
		{
			if (show[x][y] == '*') show[x][y] = 'F';
			else if (show[x][y] == 'F') show[x][y] = '*';
			else printf("该位置已排查，无法标记。\n");
			ShowBoard(show, ROWS, COLS);
		}
		else if (a == 2)
		{
			if (x > 0 && x <= ROW && y > 0 && y <= COL)
			{
				if (mine[x][y] == '1')
				{
					printf("很不幸，你被炸死了\n");
					break;
				}
				else if (show[x][y] != '*')
				{
					printf("请重新选择\n");
				}
				else
				{
					ZhanKai(mine, show, x, y, &count);
					ShowBoard(show, ROWS, COLS);
					printf("请继续选择\n");
				}
			}
			else
			{
				printf("位置非法请重新输入：\n");
			}
		}
		else
		{
			printf("输入非法，请重新输入：\n");
		}

	}
	if (count == ROW * COL - Lei_Count)
	{
		printf("恭喜你赢了\n");
		ShowBoard(mine, ROWS, COLS);
	}
}