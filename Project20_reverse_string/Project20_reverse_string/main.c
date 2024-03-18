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
	char arr[101] = { 0 }; //101�����1��Ϊ������\0
	gets(arr);
	int con = 0;
	char* p = arr;
	//while (*arr++) ע�⣬����һ�������ò�������Ȼarr��߾�û����
	while (*p++) { //'\0'��ASCII����0
		con++;
	}
	char* las = arr + con - 1;
	reverse(arr, las);//����������һ��
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
		reverse(start, last);//�����ξֲ�����һ��
		last+=2;
	}
	printf("%s\n", arr);
}