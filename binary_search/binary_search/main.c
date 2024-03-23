#include <stdio.h>
#include <assert.h>
#include "binarysearch.h"
int main()
{
	int arr[13] = { -4, -1, 0, 3, 6, 7, 9, 15, 23, 34, 45, 57, 66 };
	int sz = (sizeof(arr) / sizeof(arr[0]));
	int n = 0;
	printf("please enter the number you want to search: ");
	scanf_s("%d", &n);
	getchar();
	if (binary_search(arr, n, sz) >= 0)
		printf("the figure %d is located at subscript %d.\n", n, binary_search(arr, n, sz));
	else
		printf("Oops, if seems empty.\n");

	return 0;
}