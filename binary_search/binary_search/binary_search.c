#include "binarysearch.h"
#include <assert.h>
int binary_search(const int* arr, int n, int sz)
{
	assert(arr != NULL);
	if (sz == 0)
		return -1;
	int left = 0;
	int right = sz - 1;
	int mid = 0;
	while(left < right)
	{
		if (*(arr + left) == n)
			return left;
		else if (*(arr + right) == n)
			return right;
		else
		{
			mid = ((left / 2) + (right / 2));
			if (arr[mid] == n)
				return mid;
			else
			{
				if (arr[mid] < n)
					left = mid + 1;
				else
					right = mid - 1;
			}
		}
	}
	if (left > right)
		return -1;
}