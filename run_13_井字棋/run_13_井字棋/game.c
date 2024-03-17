#include "game.h"
void initboard(char board[ROW][COL],int row,int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void displayboard(char board[ROW][COL])
{
	int i = 0;

	for (i = 0; i < ROW; i++)
	{
		int j = 0;
		for (j = 0; j < COL; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < COL - 1)
				printf("|");
		}
		printf("\n");
		if (i < ROW - 1)
		{
			for (j = 0; j < COL; j++)
			{
				printf("---");
				if (j < COL - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}
void playermove(char board[ROW][COL])
{
	int row = 0;
	int col = 0; 
	
	while(1)
	{
		scanf_s("%d %d", &row, &col);
		if (row >=1 && row <=ROW && col>=1 && col <=COL)
		{
			if (board[row-1][col-1] == ' ')
			{
				board[row - 1][col - 1] = '@';
				break;
			}
			else
				printf("输入坐标非法，请重新输入：");
		}
	}
	
}
void computermove(char board[ROW][COL],int row,int col)
{
	/*time_t t = time(NULL);
	srand((unsigned int)t);*/
	int ret1 = 0;
	int ret2 = 0;
	while(1)
	{
		ret1 = rand() % (row-1)+1;
	    ret2 = rand() % (col-1)+1;
		if (board[ret1][ret2] == ' ')
		{
			board[ret1][ret2] = '*';
			printf("%d %d\n", ret1+1, ret2+1);//这里的打印不能写在循环外，因为是在循环里定义的
			break;
		}
	}
}
char judge(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	int count1 = 0;
	int count2 = 0;
	while(1)
	{
		//先判断行
		for (i = 0; i < ROW; i++)
		{
			count1 = 0;
			count2 = 0;
			for (j = 0; j < COL; j++)
			{
				if (board[i][j] == '@')
					count1++;
				if (board[i][j] == '*')
					count2++;
			}
			if (count1 == 3|count2==3)
				break;
		}
		if (count1== 3)
		{
			return '@';
		    break;
		}
		if (count2 == 3)
		{
			return '*';
			break;
		}
		//再判断列
		count1 = 0;
		count2 = 0;
		for (j = 0; j < ROW; j++)
		{
			count1 = 0;
			count2 = 0;
			for (i = 0; i < COL; i++)
			{
				if (board[i][j] == '@')
					count1++;
				if (board[i][j] == '*')
					count2++;
			}
			if (count1 == 3 | count2 == 3)
				break;
		}
		if (count1 == 3)
		{
			return '@';
			break;
		}
		if (count2 == 3)
		{
			return '*';
			break;
		}
		/*else
			return 'c';
			break;*/
		//再判断×
		count1 = 0;
		count2 = 1;
		if (board[0][0] == '@')
		{
			if (board[1][1] == '@')
			{
				if (board[2][2] == '@')
				{
					count1 = count2;
				}
			}
		}
		if (board[0][2] == '@')
		{
			if (board[1][1] == '@')
			{
				if (board[2][0] == '@')
				{
					count1 = count2;
				}
			}
		}
		if (board[0][0] == '*')
		{
			if (board[1][1] == '*')
			{
				if (board[2][2] == '*')
				{
					count2 = count1;
				}
			}
		}
		if (board[0][2] == '*')
		{
			if (board[1][1] == '*')
			{
				if (board[2][0] == '*')
				{
					count2 = count1;
				}
			}
		}
		
		if (count1 == 1)
			return '@';
	    if (count2 == 0)
			return '*';
		count1 = 0;
		for (i = 0; i < ROW; i++)
		{
			for (j = 0; j < COL; j++)
			{
				if (board[i][j] == ' ')
					return 'c';//return执行就会跳出函数
			}
		}
		return '=';//能执行到这说明上一个return没有执行
	}
}
void game()
{
	char board[ROW][COL] = { 0 };
	initboard(board, ROW, COL);//初始化棋盘
	displayboard(board);//打印显示棋盘
	char flag = '\0';//注意，这个变量的创建不能再while循环内，因为在内部创建如果循环结束该变量也会随之销毁
	while(1)
	{
		
		printf("玩家下棋：");
		playermove(board);
		displayboard(board);
	    flag = judge(board, ROW, COL);
		if (flag != 'c')//这里的'c'表示continue
			break;
		printf("电脑下棋：");
		computermove(board,ROW,COL);
		displayboard(board);
	    flag = judge(board, ROW, COL);
		if (flag != 'c')//这里的'c'表示continue
			break;
	}
	if (flag == '@')
		printf("你赢了\n");
	else if (flag == '*')
		printf("电脑赢了\n");
	else//(flag == '=')
		printf("平局，游戏结束\n");

}