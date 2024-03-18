//my_strcpy的实现以及const的作用
#include <stdio.h>
#include <string.h>
#include <assert.h>

//void my_strcpy1(char* dest, char* sorc)//destination, source
//{
//	while (*sorc != '\0')
//	{
//		*dest = *sorc;
//		dest++;
//		sorc++;//代码冗余
//	}
//	*dest = *sorc;//代码冗余
//}//第一版，最垃圾的实现，满分10分值5分


//void my_strcpy2(char* dest, char* sorc)
//{
//	while (*(sorc - 1) != '\0')
//	{
//		*dest++ = *sorc++;
//	}
//
//}//第二版，相比较于第一版，代码精简了很多，但还是不够好，也不够安全

//void my_strcpy3(char* dest, char* sorc)
//{
//	//断言assert
//	assert(dest != NULL && sorc != NULL);
//	/*这里在最后一步* sorc为'\0', 并将'\0'赋值给 * dest后，
//	该赋值表达式的返回值为'\0',而'\0'的ASC	II码值为0，为假，退出循环*/
//	while (*dest++ = *sorc++);
//
//}//这一版已经很接近满分了，但是还有两点不足

char* my_strcpy4(char* dest, const char* sorc)//const char*的目的是防止函数内部sorc的值被修改
											  //这里形参是const char*而实参是char*，实参被形参强制类型转换
{
	char* ret = dest;
	assert(dest != NULL && sorc != NULL);
	//while (*sorc++ = *dest++);//因为有const，这个代码在编译阶段就会报错，使问题迅速被找出
	while (*dest++ = *sorc++);
	return ret;//char*的返回类型，返回dest的地址
}
int main()
{
	//先看一下库函数strcpy作用以及返回值
	char dest[] = "xxxxxxxxxxxxxx";
	char sorc[] = "Hello world";
	
	/*my_strcpy1/2/3(dest, sorc);*/
	/*printf("%s\n%s\n", dest, sorc);*/
	printf("%s\n%s\n", my_strcpy4(dest, sorc), sorc);
	return 0;
}
