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
				printf("��������Ƿ������������룺");
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
			printf("%d %d\n", ret1+1, ret2+1);//����Ĵ�ӡ����д��ѭ���⣬��Ϊ����ѭ���ﶨ���
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
		//���ж���
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
		//���ж���
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
		//���жϡ�
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
					return 'c';//returnִ�оͻ���������
			}
		}
		return '=';//��ִ�е���˵����һ��returnû��ִ��
	}
}
void game()
{
	char board[ROW][COL] = { 0 };
	initboard(board, ROW, COL);//��ʼ������
	displayboard(board);//��ӡ��ʾ����
	char flag = '\0';//ע�⣬��������Ĵ���������whileѭ���ڣ���Ϊ���ڲ��������ѭ�������ñ���Ҳ����֮����
	while(1)
	{
		
		printf("������壺");
		playermove(board);
		displayboard(board);
	    flag = judge(board, ROW, COL);
		if (flag != 'c')//�����'c'��ʾcontinue
			break;
		printf("�������壺");
		computermove(board,ROW,COL);
		displayboard(board);
	    flag = judge(board, ROW, COL);
		if (flag != 'c')//�����'c'��ʾcontinue
			break;
	}
	if (flag == '@')
		printf("��Ӯ��\n");
	else if (flag == '*')
		printf("����Ӯ��\n");
	else//(flag == '=')
		printf("ƽ�֣���Ϸ����\n");

}