#pragma once
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define ROW 3
#define COL 3 //定义宏，方便调整棋盘大小
void game();
void menu();
void initboard(char board[ROW][COL], int row, int col);
void displayboard(char board[ROW][COL]);
void playermove(char board[ROW][COL]);
void computermove(char board[ROW][COL],int row,int col);
char judge(char board[ROW][COL], int row, int col);
