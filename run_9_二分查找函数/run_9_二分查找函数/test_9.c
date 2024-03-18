//正确的二分查找函数写法，仅限于正向升序数列
#include <stdio.h>
int binary_search(int arr[],int sz, int x);
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof arr / sizeof arr[0];
	int x = 0;
	printf("Please input the number you want to check: ");
	scanf_s("%d", &x);
	printf("The sequence of your number is : %d", binary_search(arr,sz,x));
	
	return 0;
}
int binary_search(int arr[], int sz, int x)
{
	int left = 0;
	int right = sz - 1;
	
	while (left<=right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid] < x)
		{
			left = mid + 1;
		}
		else if (arr[mid] > x)
		{
			right = mid - 1;
		}
		else
		{
			return mid;
			
		}
	}
	return -1;
	
}