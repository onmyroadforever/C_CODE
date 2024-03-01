//É¨À×ÓÎÏ·
#include "game.h"
int main()
{
	time_t t = time(NULL);
	srand((unsigned int)t);
	int w = 1;
	while (w)
	{
		int a = 0;
		printf("    [start(1) quit(0)]\n    ");
		scanf_s("%d", &a);
		switch (a)
		{
		case 1:game();
			break;
		case 0:w = 0;
			printf("you have quited.");
			break;
		default:printf("error,please try again");
		}
		printf("\n");
	}
	return 0;
}