#include<stdio.h>
#include<stdlib.h> //rand.stand���g���̂ɕK�v
#include<time.h>   //time���g���̂ɕK�v


//�����_���Ȑ��l�̐���
int main(void)
{
	// rand()�g�p����
	srand((unsigned int)time(NULL)); //0�b�Ɏ��s�����Ƃ���1�b�Ɏ��s�����Ƃ��ňႤ����������g��

	int randNum = 0;		//�����_���ɐ������ꂽ���l��ۑ����邽�߂̕ϐ�
	for (int i = 0; i < 8; i++)
	{
		randNum = rand();		//rand()�֐��̖߂�l��randNum�ɑ������
		printf("�����_���Ȑ���:%d\n", randNum % 3);
	}


	return 0;
}



// scanf_s�𗘗p���ăL�[�{�[�h���琔�l����͂���
/*
int main(void)
{
	//printf�͕������\�����邽�߂̊֐�
	printf("�������\������\n");

	//scanf_s�̓L�[�{�[�h����̓��͂��󂯕t���邽�߂̊֐�
	int inputNum = 0;  //�v���C���[�����͂���������ۑ����邽�߂̊֐�
	scanf_s("%d", &inputNum); //�L�[�{�[�h���琮���̓��͂��󂯕t����

	printf("���͂�������:%d\n", inputNum);

	return 0;
}
*/