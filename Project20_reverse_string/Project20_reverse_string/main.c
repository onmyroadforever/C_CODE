#include <stdio.h>
#include <assert.h>

void reverse(char* start, char* last) {

	assert(start && last);
	char* left = start;
	char* right = last;
	char tmp;
	while (left < right) {
		tmp = *left;
		*left = *right;
		*right = tmp;
		right--;
		left++;
	}
}

int main() {
	char arr[101] = { 0 }; //101多这个1是为了容纳\0
	gets(arr);
	int con = 0;
	char* p = arr;
	//while (*arr++) 注意，这里一定不能用参数，不然arr后边就没用了
	while (*p++) { //'\0'的ASCII码是0
		con++;
	}
	char* las = arr + con - 1;
	reverse(arr, las);//先整体逆序一遍
	char* i;
	char* last = arr;
	while (*(last+1) != '\0') {
		i = last;
		char* start = last;
		while (*i++) {
			if (*(i+1) == ' ' || *(i+1) == '\0') {
				last = i;
				break;
			}
		}
		reverse(start, last);//再依次局部逆序一遍
		last+=2;
	}
	printf("%s\n", arr);
}