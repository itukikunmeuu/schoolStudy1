#include<stdio.h>
#include "kadai.h"

int main(void)
{
	//�쐬�����֐����Ăяo��
	//�\������*�̐���print�\������v
	int num = kadai(8);
	printf("*�̐��@= %d\n", num);

	return 0;
}



/*
//�v���g�^�C�v�錾
void f1(int x);

int main(void)
{
	int inputNum = 0;
	printf("��������͂��Ă�������\n");
	scanf_s("%d", &inputNum);
	int num = 0;
	f1(1);
	
	while (num = inputNum)
	{
		num = num + inputNum;
		num++;
	}
		printf("*�̐���%d�ł�\n", inputNum);

	return 0;
}*/

void f1(int x) {
	printf("����%d���n����܂���\n", x);
}
//�v���g�^�C�v�錾
/*
void f(int x);			 //�����̒l��\������
void f2(int x);			//�����̒l��\������
void f3(int x,int y);	//�����̒l��\������

int main(void)
{
	f(2);
	f2(2);
	//�쐬�����֐����Ăяo��
	//�\������*�̐���print�\������


	return 0;
}*/
	//���������
	/*
	int inputNum = 0;
	printf("��������͂��Ă�������\n");
	scanf_s("%d", &inputNum);
	printf("����=%d\n", inputNum);
	*/
	//���������
	/*
	float inputFloat = 0.0f;
	printf("��������͂��Ă�������\n");
	scanf_s("%f", &inputFloat);
	printf("����=%f\n", inputFloat);
	*/
	//���������
	/*
	char inputChar = 'A';
	printf("���p1��������͂��Ă�������\n");
	inputChar = getchar();
	printf("���p1����=%c\n", inputChar);
	*/