//my_strcpy��ʵ���Լ�const������
#include <stdio.h>
#include <string.h>
#include <assert.h>

//void my_strcpy1(char* dest, char* sorc)//destination, source
//{
//	while (*sorc != '\0')
//	{
//		*dest = *sorc;
//		dest++;
//		sorc++;//��������
//	}
//	*dest = *sorc;//��������
//}//��һ�棬��������ʵ�֣�����10��ֵ5��


//void my_strcpy2(char* dest, char* sorc)
//{
//	while (*(sorc - 1) != '\0')
//	{
//		*dest++ = *sorc++;
//	}
//
//}//�ڶ��棬��Ƚ��ڵ�һ�棬���뾫���˺ܶ࣬�����ǲ����ã�Ҳ������ȫ

//void my_strcpy3(char* dest, char* sorc)
//{
//	//����assert
//	assert(dest != NULL && sorc != NULL);
//	/*���������һ��* sorcΪ'\0', ����'\0'��ֵ�� * dest��
//	�ø�ֵ���ʽ�ķ���ֵΪ'\0',��'\0'��ASC	II��ֵΪ0��Ϊ�٣��˳�ѭ��*/
//	while (*dest++ = *sorc++);
//
//}//��һ���Ѿ��ܽӽ������ˣ����ǻ������㲻��

char* my_strcpy4(char* dest, const char* sorc)//const char*��Ŀ���Ƿ�ֹ�����ڲ�sorc��ֵ���޸�
											  //�����β���const char*��ʵ����char*��ʵ�α��β�ǿ������ת��
{
	char* ret = dest;
	assert(dest != NULL && sorc != NULL);
	//while (*sorc++ = *dest++);//��Ϊ��const����������ڱ���׶ξͻᱨ��ʹ����Ѹ�ٱ��ҳ�
	while (*dest++ = *sorc++);
	return ret;//char*�ķ������ͣ�����dest�ĵ�ַ
}
int main()
{
	//�ȿ�һ�¿⺯��strcpy�����Լ�����ֵ
	char dest[] = "xxxxxxxxxxxxxx";
	char sorc[] = "Hello world";
	
	/*my_strcpy1/2/3(dest, sorc);*/
	/*printf("%s\n%s\n", dest, sorc);*/
	printf("%s\n%s\n", my_strcpy4(dest, sorc), sorc);
	return 0;
}
