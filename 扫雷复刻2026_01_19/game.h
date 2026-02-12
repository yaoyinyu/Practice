#pragma once

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define ROW 9
#define COL 9

#define ROWS ROW + 2
#define COLS COL + 2

#define Lei_Count 10

//初始化棋盘
void InitBoard(char board[ROWS][COLS], int rows, int cols, char n);

//展示棋盘
void ShowBoard(char board[ROWS][COLS], int rows, int cols);

//布置雷
void Lei(char board[ROWS][COLS]);

//找雷
void FindLei(char mine[ROWS][COLS],char show[ROWS][COLS]);

//找雷的个数
int QiuHe(char board[ROWS][COLS], int x, int y);