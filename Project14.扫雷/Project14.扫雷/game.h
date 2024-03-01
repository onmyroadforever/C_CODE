#pragma once
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define ROW 11//the number of row of the board
#define COL 11//the number of column of the board
#define DROW (ROW-2)
#define DCOL (COL-2)
#define LEVEL 9
void game();//the main body of the game
void init_board(char board[ROW][COL],char set);//to initialize the board
void displayboard(char board[ROW][COL]);//to display the board
void gen_mines(char board1[ROW][COL], int x, int y);//to generate the mines randomly
int count_mines(char board1[ROW][ROW], int x, int y);//count the number of the mines around the assigned position (x,y)
void clear_mines(char board1[ROW][COL], char board2[ROW][COL], int x, int y);//to clear the mines recursively