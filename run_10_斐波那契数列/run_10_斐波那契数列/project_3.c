//쳲��������п����õݹ�д������Ч��̫�ͣ������������
#include <stdio.h>
int Fib(int n)//�õ���д�ļ����n��쳲���������
{
	int i = 0;
	if (n > 2)
	{
		int a = 1;
		int b = 1;
		int c = 0;
		for (i = 2; i < n; i++)
		{
			c = a + b;
			a = b;
			b = c;
		}
		return c;
	}
	else
		return 1;
}
int main(void)
{  
	int n = 0;
	scanf_s("%d", &n);
	printf("%d\n", Fib(n));
	printf("%d\n", Fib2(n));
	return 0;
}