#include<stdio.h>
#include<string.h>

int main(void)
{
	char str[100];
	printf("���Ȃ��͐l�Ԃł����H�@yes / no\n");
	scanf_s("%s", str, 100);


	if (strcmp(str, "yes") == 0) //yes�Ɠ��͂��ꂽ��
	{
		printf("���Ȃ��͐l�Ԃł�\n");
	}
	else if (strcmp(str, "no") == 0) //no�Ɠ��͂��ꂽ��
	{
		printf("���Ȃ��͐l�Ԃł͂���܂���\n");
	}
	else //����ȊO�����͂��ꂽ��
	{
		printf("���Ȃ��͉��҂ł����H\n");
	}

	return 0;
}