#include <stdio.h>
int main()
{
	int i, k, j, n;
	for (i = 0; i < 9; i++)
	{
		
		for (n = 0; n < (i + 1); n++)
		{
			printf("%d*%d=%-2d ", i + 1, n + 1, (i + 1) * (n + 1));//这里的%-2d里的-2是左对齐打印两位。
		}
		printf("\n");
	}
	return 0;
}