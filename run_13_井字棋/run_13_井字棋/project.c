#include "game.h"

int main()
{
	int op = 0;//����������ܷ���do������޷��������while()����
	//time_t t = time(NULL);//����ʱ���
	srand((unsigned int)time(NULL));//�����������
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
					printf("�˳�\n");
					op = 0;
					break;
				}
			default:
			{
				printf("ѡ�����������ѡ��\n");
					op = 1;
					break;
			}
		}
	} while (op);
	return 0;
}