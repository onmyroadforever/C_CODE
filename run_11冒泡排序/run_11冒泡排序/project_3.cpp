#include <stdio.h>

int main(void)
{
	int i,j,n,t;
	int arr[10];
	for (i = 0; i < 10; i++)
	{
		scanf_s("%d", &arr[i]);
		
	}
	for (j = 0; j < 9; j++)
	{
		n = j;
		for (i = j; i <= 9; i++)
		{
			if (arr[i] < arr[n])
				n = i;
		}
		t = arr[n];
		arr[n] = arr[j];
		arr[j] = t;
	}
	
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	
	return 0;
}