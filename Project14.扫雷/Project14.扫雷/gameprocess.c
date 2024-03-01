#include "game.h"
void game()
{
	
	int x, y;
	char board1[ROW][COL] = { 0 };//to store the mines
	char board2[ROW][COL] = { 0 };//to show your progress
	init_board(board1,'0');
	init_board(board2, '*');
	displayboard(board2);
	scanf_s("%d %d",&x, &y);
	gen_mines(board1, x, y);
	//displayboard(board1);
	clear_mines(board1, board2, x, y);
	displayboard(board2);
	while (1)
	{
		scanf_s("%d %d", &x, &y);
		if (x >= 1 && x <= DROW && y >= 1 && y <= DCOL)
		{
			if (board1[x][y] == '1')
			{
				printf("game over\n");
				break;
			}
			else
			{
				clear_mines(board1, board2, x, y);
				displayboard(board2);
			}
		}
		else
			printf("fault, please enter again\n");
	}
	
	
}