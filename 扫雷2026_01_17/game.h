#pragma once

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define COUNT 10

//初始化棋盘
void InitBoard(char board[ROWS][COLS], int rows, int cols, char n);

//打印棋盘
void DisPlayBoard(char board[ROWS][COLS], int rows, int cols);

//布置雷
void SetMine(char board[ROWS][COLS], int row, int col);

//排查雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);

//统计雷
int get_mine_count(char board[ROWS][COLS], int x, int y);