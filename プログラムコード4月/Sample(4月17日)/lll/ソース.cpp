#include<stdio.h>
#include<stdlib.h>
#include<time.h>


/*
	//�v���C���[�̎�ƓG�̎�������Ƃ��Ď󂯎��
	// �ŏI�I�Ɂy�O�[�@vs�@�p�[�z�̂悤�ɕ\������֐�
	void dispBattle(int playerHand,int enemyHand)
	{
		//�v���C���[�̎�@vs�@�G�̎�ƂȂ�悤�ɕ\�����s��
		// ���ꂼ��O�[�`���L�p�[��dispHand()�������g�p���ĕ\������

		//�v���C���[�̎��\������
	//	dispHand(playerHand);
		// vs��\������
		printf(" vs ");
		//�G�̎��\������
	//	dispHand(enemyHand);

		return;
	}*/
/*

	//�v���C���[�̏������A�v���C���[�̔s�k����2�������Ƃ��Ď󂯎��B
	//�v���C���[�������̂ق��������ꍇ�́u�����v
	//�v���C���[�̏������̂ق������Ȃ��ꍇ�́u����...�v
	//�v���C���[�̏����������Ȃ��ꍇ�́u���������v
	//�ƕ\������֐�
	void dispResult(int win,int lose)
	{
		printf("%d - %d", win, lose);//�ŏI�I�ȏ��s���\��
		//���s�ɉ��������ʂ�\������
		if (win > lose)
		{
			printf("�������񐔁@%d �������񐔁@%d\n", win, lose);

			printf("�����I");
		}
		else if(win < lose)
		{
			printf("�������񐔁@%d �������񐔁@%d\n", win, lose);
			printf("����...");
		}
		else
			printf("��������");
		}
		return;
	}*/
//�O�[�`���L�p�[��\�����邽�߂̊֐�
//�����Ƃ���0���n���ꂽ��O�[�ƕ\��
//�����Ƃ���1���n���ꂽ��`���L�ƕ\��
//�����Ƃ���2���n���ꂽ��p�[�ƕ\��
/*void dispHand(int hand)
{
	/*
	if (hand == 0)
	{
		printf("�O�[");
	}
	else if (hand == 1)
	{
		printf("�`���L");
	}
	else if (hand == 2)
	{
		printf("�p�[");
	}
}*/

//�����_���Ȏ�i�O�[�B�`���L�A�p�[�j�𐶐����ĕԂ��֐�
//�G�̎�����̊֐����g�p���Đ�������悤�ɕύX
int createRansHand(void)
{
	return rand() % 3;
}


//�v���C���[�̎�A�G�̎�������Ƃ��ēn����
//�v���C���[�������Ă���ꍇ��1
//�v���C���[�������Ă���ꍇ��-1
//�������̏ꍇ��0
//��Ԃ��֐��𐶐�����
//���ۂ̔��蕔�����g�p���čs���悤�ɕύX
int getBattleResult(int playerHand,int enemyHand)
{
	//���s����
	int result = 0; //�����Ȃ�1�����Ȃ�-1�A�������Ȃ�0������
	//���������Ȃ�0��Ԃ�
	if (playerHand == enemyHand) {
		//������
		result == 0;
		}
	if (playerHand == 0) {
		if (enemyHand == 1) {
			result = 1;
		}

		else if (enemyHand == 2) {
			result = 1;
		}
		//�����Ă���1��Ԃ�
		if (playerHand == enemyHand) {
			//����
			result == -1;
		}
		else if (enemyHand == 2) {
			result = 1;
		}
		//��������-1��Ԃ�
		if (playerHand == enemyHand) {
			//����
			result == 1;
		}
		else if (enemyHand == 2) {
			result = -1;
		}
	}
		//�����ɗ����n�_�ő��q�͂��蓾�Ȃ�
		//�����������������肦�Ȃ�

		//�����̃p�^�[�����`�F�b�N����
		if ((playerHand == 0) && (enemyHand == 1)) {
			return 1;
		}
		if ((playerHand == 1) && (enemyHand == 2)) {
			return 1;
		}
		if ((playerHand == 2) && (enemyHand == 0)) {
			return 1;
		}
		//�����ɗ������_�ł������Ə����̃p�^�[���͂��ׂď��O����Ă���
		return -1;

}


int main(void)
{
	printf("return 0;�܂ŗ�����֐����킩��\n");
	printf("�R���s���[�^�[�y�l�Ə������悤��z\n");		//�R���s���[�^�̕�����\��������
	printf("0����͂���ƃO�[�ƕ\�������\n");			//���[�������̕��͂����
	printf("1����͂���ƃ`���L�ƕ\�������\n");		//���[�������̕��͂����
	printf("2����͂���ƃp�[�ƕ\�������\n");			//���[�������̕��͂����
	int a = 0;
	srand((unsigned int)time(NULL));					//��������͂���
	int randNum = 0;
	int num = 0;
	int winCount = 0;									 //�������񐔂𐔂���
	int loseCount = 0;									 //�������񐔂𐔂���
	int playerHand = 0;
	for (int i = 0; i < 3; i++)
	{
		printf("========================\n");
		scanf_s("%d", &a);								//���ꂽ�l���o��
		randNum = rand();								//rand()�֐��̖߂�l��randNum�ɑ������
		num = randNum % 3;
		printf("%d����͂�����", a);						//���ꂽ�l���Ȃ�Ȃ̂���\��������
		if (a == 0) {									//���ꂽ�l���Ȃ�Ȃ̂������߂�
			printf("�O�[\n");
		}
		else if (a == 1) {
			printf("�`���L\n");
		}
		else {
			printf("�p�[\n");
		}


		if (num == 0)									//�R���s���[�^�����̒l�����Ȃ̂������߂�
		{
			printf("�O�[\n");
		}
		else if (num == 1)
		{
			printf("�`���L\n");
		}
		else
		{
			printf("�p�[\n");

		}

		//int getBattleResult(int playerHand.int enemyHand)
		//���g�p���ď��s������s��
		int result = getBattleResult(playerHand, enemyHand);

		if (result == 0) {
			//������
			printf("��������...\n");
			continue;
		}
		else if (result == 1) {
			//����
			dispWin();//�֐����Ăяo��
			winCount++
		}
		else {
			//����
			dispLose();//�֐����Ăяo��
			loseCount++
		}
		/*
		if (a == 0 && num == 1) {						//�ǂ���̏����Ȃ̂������߂�
			printf("����\n");							//�������ꍇ��+1���Ēl�𑝂₷
			winCount++;
			printf("�������񐔂�%d����\n", winCount);
		}
		else if (a == 1 && num == 2) {
			printf("����\n");
			winCount++;
			printf("�������񐔂�%d����\n", winCount);
		}
		else if (a == 2 && num == 0)
		{
			printf("����\n");
			winCount++;
			printf("�������񐔂�%d����\n", winCount);
		}
		else if (a == num) {
			printf("��������...\n");
			i--;
			continue;
		}
		else
		{
			printf("����\n");
			loseCount++;
		}
		*/
	}
	
	if (winCount > 1) {									//���҂����߂�
		printf("�������񐔁@%d �������񐔁@%d\n", winCount, loseCount);
		printf("���ҁ@�v���C���[�I�I\n");
		printf("�R���s���[�^�[�y���A������������B���͕����Ȃ�����Ȃ܂����킵���I�z\n");
	}
	else
	{
		printf("�������񐔁@%d �������񐔁@%d\n", winCount, loseCount);
		printf("���ҁ@�R���s���[�^�[\n");
		printf("�R���s���[�^�[�y�c�O�A�l�̏������ˁO�O�z");
	}
	

	return 0;
}


