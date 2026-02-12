#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROW 3
#define COL 3
#define WIN_COUNT 3

//初始化棋盘
void inboard(char board[ROW][COL], int row, int col);

//玩家移动
void playermove(char board[ROW][COL], int row, int col);

//电脑移动
void computermove(char board[ROW][COL], int row, int col);

//打印棋盘
void displayboard(char board[ROW][COL], int row, int col);

//判断输赢
char checkwin(char board[ROW][COL], int row, int col);
