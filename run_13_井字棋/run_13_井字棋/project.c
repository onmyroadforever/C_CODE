#include "game.h"

int main()
{
	int op = 0;//这个变量不能放在do里，否则无法在下面的while()里用
	//time_t t = time(NULL);//生成时间戳
	srand((unsigned int)time(NULL));//设置随机种子
	do
	{
		menu();
		scanf_s("%d", &op);
		switch (op)
		{
			case 1:
				game();
				break;
			case 0:
				{
					printf("退出\n");
					op = 0;
					break;
				}
			default:
			{
				printf("选择错误，请重新选择\n");
					op = 1;
					break;
			}
		}
	} while (op);
	return 0;
}