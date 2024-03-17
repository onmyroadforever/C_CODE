#include <stdio.h>
int main()
{
	int arr1[11];
	int arr2[11];
	int arr[21];
	short a, b;
	scanf_s("%d %d", &a, &b);
	int n = 0;
	for (n = 0; n < a; n++)
	{
		scanf_s("%d", arr1 + n);
	}
	for (n = 0; n < b; n++)
	{
		scanf_s("%d", arr2 + n);
	}
	int i, j;
	i = j = n = 0;
	while (i < a && j < b)
	{
		if ((arr1[i] <= arr2[j]) && i < a && j < b)
		{
			arr[n++] = arr1[i++];
		}
		else
		{
			arr[n++] = arr2[j++];
		}
	}
	while (n < (a + b))
	{
		if (i < (a - 1))
			arr[n++] = arr1[i++];
		else
			arr[n++] = arr2[j++];
	}
	for (n = 0; n < (a + b); n++)
	{
		printf("%d ", arr[n]);
	}
	return 0;
}