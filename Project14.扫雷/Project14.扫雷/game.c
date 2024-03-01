#include "game.h"
void init_board(char board[ROW][COL], char set)
{
	int i = 0, j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
			board[i][j] = set;
	}
}

void displayboard(char board[ROW][COL])
{
	int i = 0, j = 0;
	for (j = 0; j <= DCOL; j++)
	{
		printf("%d ", j);
	}
	printf("\n");
	for (i = 1; i <= DROW; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= DCOL; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}
void gen_mines(char board1[ROW][COL], int x, int y)
{
	if (x >= 1 && x <= DROW && y >= 1 && y <= DCOL)
	{
		int count = LEVEL;
		while (count)
		{
			int a = ((rand() % DROW) + 1);
			int b = ((rand() % DCOL) + 1);
			if (board1[a][b] =='0' )
			{
				if (a!=x||b!=y)
				board1[a][b] = '1';
				count--;
			}
		}
	}
}
int count_mines(char board1[ROW][ROW], int x, int y)
{
	//by using '1'-'0'=1 to compute how many mines are in the 8 coordinates around (x,y)
	return (board1[x - 1][y - 1] + 
		board1[x][y - 1] +
		board1[x + 1][y - 1] +
		board1[x + 1][y] +
		board1[x + 1][y + 1] +
		board1[x][y + 1] +
		board1[x - 1][y + 1] +
		board1[x - 1][y] - 8 * '0');
}
void clear_mines(char board1[ROW][COL], char board2[ROW][COL], int x, int y)
{
	int count = count_mines(board1, x, y);
	if (count != 0)
	{
		board2[x][y] = count + '0';//turn 'int' to 'char'
		
	}
	else
	{
		board2[x][y] = ' ';
		
		int i, j;
		for (i = x - 1; i <= x + 1; i++)
		{
			for (j = y - 1; j <= y + 1; j++)
			{
				if (board2[i][j] == '*' && i > 0 && i <= DROW && j > 0 && j <= DCOL)
				{
					if(i!=x||j!=y)
					clear_mines(board1, board2, i, j);
				}
			}
		}
	}
}


