#include<stdio.h>

int main(void)
{
	int enemyHp = 100; //�G��HP
	int playerMp = 500; //�v���C���[��MP

	//�A���U�����@�œG��|���܂ōU������
	while (enemyHp > 0)
	{
		enemyHp -= 10;
		playerMp -= 10;
		printf("�G�̎c��HP: %d\n", enemyHp);
		printf("�v���C���[�̎c��MP: %d\n", playerMp);

		//MP���Ȃ��Ȃ����狭���I��
		if (playerMp <= 0) {
			printf("MP�؂�I�U���I��\n");
			break;
		}
		//�G�ɉ�����ꂽ
		if (0) {
			printf("�悯��ꂽ�̂Œ��f\n");
			break;
		}
		//�ق��̓G�̍U�����󂯂�
		if (0) {
			printf("�ق��̓G�̍U�����󂯂��̂Œ��f\n");
			break;
		}
		printf("�v���C���[�̎c��MP: %d\n", playerMp);
	}
	return 0;
}
/*
	//do-while���̐���
	//�@�������s��
	//�A�����𖞂����Ă�����@�ɖ߂�
	do {
		printf("do-while���͕K����x�͎��s���܂�\n");
	} while (2 < 1);

	//while���̐���
	//�@while���ɓ�����������`�F�b�N���s����
	//�A�����𖞂����Ă����珈�����s���@�������Ă��Ȃ��Ȃ�I��
	//�@�ɖ߂�
	while (2 < 1)
	{
		printf("while���́H\n");
	}
	*/

/*
	int num = 3;

	//true(�^)�@�@0�ȊO
	//false(�U)�@0

	while (num+1) {
		printf("����%d��J��Ԃ��܂�", num);
		num--;
	}

	if (num) {
		//num=0�̏ꍇ�͂����̏����͍s���Ȃ�
		//num!=0�̏ꍇ�͂����̏����͍s����
	}*/

/*
//for��������ƍׂ�
int main(void)
{
	int startCount = 4;
	int loopNum = 4;
	//��������p�������ɂ��ϐ��͎g����
	for (int i = 1; i <= loopNum; i++) {
		printf("�J��Ԃ�%d\n", i);
	}
	return 0;

}*/

/*
	int hp = 50;

		//HP��0�ȉ��ɂȂ�܂ōU������Â���
		while (hp > 0)
		{
			hp -= 6;
			printf("�c��HP:%d\n", hp);
		}

		//for���ɏ�������
		for (hp = 50; hp > 0; hp - -6)
		{
			printf("�c��HP:%d\n", hp);
		}

		//�@while���ɓ�����������`�F�b�N���s����
		//�A�����𖞂����Ă��瑼�������s���@�������Ă��Ȃ��Ȃ�I��
		//�@�ɖ߂�*/

/*
	printf("for���ɂ��J��Ԃ��̗��K�ł�\n");

	for (;;) {
		printf("���X�ƌJ��Ԃ��܂�\n");
	}
/*
	printf("for���ɂ��J��Ԃ��̗��K�ł�\n");

	int i;

	for (i = 1; i <= 5; i++)
	{
		printf("%d��ڂ̌J��Ԃ��ł�\n", i);
	}
	printf("�J�E���^�ϐ��̒l��%d�ł�\n",i);

	return 0;
	*/

/*
//�J��Ԃ�����
int main(void) 
{
	int hp0 = 100; //�E��
//	int hp1 = 120; //��m
//	int hp2 = 80; //�m��
//	int hp3 = 70; //���@�g��

	int count = 0; //�J��Ԃ��񐔂𐔂���
	for (count = 1; count <= 4; count++)
	{
		hp0 -= 8;
		printf("%d�̖ڂ̓G�̍U���I\n", count);
		printf("�c��HP:%d\n", hp0);
	}

	printf("count = %d\n",count)
	/*
	//�@�����s�����
	count = 1;
	//�A�J��Ԃ������`�F�b�N
	count <= 4  //true�̏ꍇ�J��Ԃ������i�C�j�����s����
		//false�̏ꍇ��for���I���
�@�@//�J��Ԃ������𖞂������ꍇ�͏������s����
�@�@hp0 -= 8; //�U�����󂯂��@HP�����炷
	printf("%d�̖ڂ̓G�̍U���I\n", count);
	printf("�c��HP:%d\n", hp0);

	//�B���߂����s������̏��������s�����
	count++;  //count = 2

	//�A�̏����`�F�b�N�ɖ߂�

	*/

/*
	for (
		count = 1;//�@for���ɗ������ɍŏ��Ɏ��s�����
		count <= 4;//�A�J��Ԃ�����
		);

	for (
		count = 1; //for���ɗ������ɍŏ��Ɏ��s�����
		count <= 4; //�J��Ԃ�����
		count++   //�J��Ԃ����߂����s������ɍs���鏈��
		)
	{
		//���̒��g���J��Ԃ�
	}
	return 0;

}*/

/*
	//�G��4��
	hp0 -= 10; //1�̖ڂ̓G����U�����󂯂��@�@HP��10���炷
	printf("�c��HP: %d\n", hp0);
	hp0 -= 10; //2�̖ڂ̓G����U�����󂯂��@�@HP��10���炷
	printf("�c��HP: %d\n", hp0);
	hp0 -= 10; //3�̖ڂ̓G����U�����󂯂��@�@HP��10���炷
	printf("�c��HP: %d\n", hp0);
	hp0 -= 10; //4�̖ڂ̓G����U�����󂯂��@�@HP��10���炷
	printf("�c��HP: %d\n", hp0);
	*/

/*
int main(void)
{
	int num = 1;

	int num2 = 0;

	if (num == 0 && num2 == 0) {
		//�ǂ�����0

		if (num == 0) {
			printf("�C���f���g�ɋC��t����\n");
		}
		else if (num == 0) {

		}
		else {

		}
	}
	
	switch (num)
	{
	case 0:
	    printf("num��0�ł�\n");
        break;
	case 1:
	    printf("num��0�ł�\n");
	    break;
	default:
		printf("num��0�ł�\n");
		break;

	}

	printf("\n");

	if (num == 0 && num2 == 0) { //num.num2�Ƃ���0�@�@and���Z
		printf("num��0�ł�\n");
	}
	if (num == 0 || num2 == 0) { //num.num2�̂ǂ��炩��0�@or���Z
		printf("num��0��������num2==0�ł�\n");
	}
	else if (num == 1) {
		printf("num��1�ł�\n");
	}
	else if (num == 2) {
		printf("num��2�ł͂���܂���\n");
	}
	else if (num == 3) {
		printf("num��3�ł͂���܂���\n");
	}
	else {
		printf("num��0�ł�1�ł�����܂���\n");
	}
	return 0;
}*/