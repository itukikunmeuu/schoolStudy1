#include<stdio.h>

//for���̕��K
int main(void)
{
	int answer = 0;

	//1����100�̊Ԃɑ��݂���7�̔{���̍��v���v�Z����
	//answer �� 7 + 14 + 21 + 28 + 35...
	//2�p�^�[�����炢���@���l����

	//for�����H�v����
	for (int i = 1; i <= 100; i++) {
		if (i % 7 == 0) {
			answer += i;
		}
	}

	//7�̔{�����͂���

	printf("7�̔{���̍��v�� %d�ł�\n", answer);
	return 0;
}
//�������[�v
   /*
	int hp = 50;

	int damage = 8;

	//�v���C���[�̖h��͂��`�F�b�N���ă_���[�W�����炷
	damage -= 100;

	while (hp > 0) 
	{
		hp -= 8;
		printf("�c��HP:%d\n", hp);
	}

	//�������[�v
	while (1) {//while(1)�Ŗ������[�v

		//�����`�F�b�N���Ė������[�v�𔲂���
		if (1) {
			break;
		}
	}
	*/
//continue��
	/*
	int answer = 0;

	//1����P�O�܂ł̑����Z���āA�������o�͂���
	//�J��Ԃ������͎g�p���邱�ƁI�ifor�@while�j

	//1�`�P�O�܂ł̑����Z
//	answer = 0 + 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10;
	answer = 0 + 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10;

	//�����Z���P�O��s������
	answer = 0;
	for (int i = 0; i < 10; i++) {

		printf("�������Ƃ��Ă��鐔 %d\n", i+1);

		//3�̔{���𑫂����Ƃ����ꍇ������s��Ȃ�
		if (((i + 1) % 3 == 0) ){
			continue;
		}
		//�����Z���s��
		answer += i+1;
	printf("answer = %d\n", answer);

	}
	printf("answer = %d\n", answer);
	*/
//while���̑����Z1�`10�@���K
    /*
	int answer = 0;
	answer = 0;
	
	int addNum = 1;
	while (addNum <= 10) {
		answer += addNum;
		addNum++;
	}
	printf("answer= %d\n", answer);
	*/
//for���̑����Z�P�`10�@���K
    /*
int answer = 0;

	//1����P�O�܂ł̑����Z���āA�������o�͂���
	//�J��Ԃ������͎g�p���邱�ƁI�ifor�@while�j
	for (int i = 1; i <= 10; i++) {
		printf("���[�v��%d\n", i);
		//�����Z���s��
		answer += i;
	}

	printf("answer = %d\n", answer);
	*/
//break���̕��K�@while
	/*
	//break���̕��K
	int inputNum = 8; //�v���C���[�����͂�������
	int count = 1;   //�\�����鐔��
	while (1){
		printf("�����F%d\n", count);
		//�v���C���[�����͂����������\�����ꂽ��I��
		if (count == inputNum) {
			break;
		}
		//100�܂ŕ\�����ꂽ��I��
		if (count >= 100)
		{
			break;
		}
		count++;
	}
	*/
//break���̕��K�@for
	/*
	//while�������łȂ�for���������I���ł���
	for (int i = 0; i < 100; i++) {
		int dispNum = count + 1;
		priintf("����:%d\n", dispNum);

		//�v���C���[�����͂����������\�����ꂽ��I��
		if (dispNum == inputNum) {
			break;
		}
	}
	*/
//do-while�̕��K
    /*
	//do-while���̕��K
	do {
		printf("do-while���͕K����x�͎��s���܂�\n\n");
	} while (2 < 1);
	while (2 < 1);
	{
		printf("do-while���͍ŏ���������𖞂����Ă��Ȃ��ꍇ�A��x�����s����܂���\n\n");
	}
	*/
//�J��Ԃ� while
	/*
    //�����𖞂����܂œ����������J��Ԃ��@while��
	int hp = 50;
	while (hp > 0) {//�����͏I�������ł͂Ȃ��p������
		printf("�_���[�W���󂯂��I\n");
		hp -= 8;
		printf("�c��HP�@%d\n", hp);
	}
	printf("����ł��܂���...\n\n");

	//���while����for���Œu��������
	for (int hp = 50; hp > 0;); {
		printf("�_���[�W���󂯂��I\n");
		hp -= 8;
		printf("�c��hp�@%d\n", hp);
	}
	printf("����ł��܂���...\n\n");
	*/
//�J��Ԃ��@for
	/*
	//�w�肵���񐔓����������J��Ԃ�
	for (int i = 0; i < 16; i++) {
    //printf("%d��ڂ̃��[�v\n", i+1);
		//�����v�Z�����鏈���͂܂Ƃ߂Ă���
		int dispNum = (i + 1);

		if (dispNum % 2 == 0)
		{
			printf("%d�͋���\n", dispNum);
		}
		else {
			printf("%d�͊\n", dispNum);
		}
	}*/
//���������
	/*
		if ((i + 1) % 2 == 0)//�l�����������
		{
			printf("%d�͋���\n", i + 1);
		}
		else
		{
			printf("%d�͊\n", i + 1);
		}*/
//���[�v�񐔂𐔂���
	/*
	int loopCount = 0; //���[�v�񐔂𐔂���

	//�w�肵���񐔓����������J��Ԃ�
	for (loopCount = 1; loopCount <= 5; loopCount++) {
		printf("%d��ڂ̃��[�v\n", loopCount);
	}
	*/