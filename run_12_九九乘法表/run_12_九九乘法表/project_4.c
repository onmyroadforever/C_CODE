#include <stdio.h>
int main()
{
	int i, k, j, n;
	for (i = 0; i < 9; i++)
	{
		
		for (n = 0; n < (i + 1); n++)
		{
			printf("%d*%d=%-2d ", i + 1, n + 1, (i + 1) * (n + 1));//�����%-2d���-2��������ӡ��λ��
		}
		printf("\n");
	}
	return 0;
}