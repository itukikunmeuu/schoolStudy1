#include<stdio.h>

int main(void)
{
	//false�́@0
	//true�́@0�ȊO
	if (4)
	{
		printf("���s�����\n");
	}
	int keyNum = 0;
	if (keyNum)
	{
		printf("�������Ă��� %d\n", keyNum);
	}
	else
	{
		printf("�������ĂȂ�\n");
	}

	int num = 0;
	int num2 = 1;

	//false��0
	//true��1
	printf("(num == 1)�̒��g��\��%d\n", num == 1);  //false
	printf("(num == 0)�̒��g��\��%d\n", num == 0);  //true

	printf("%d\n", num == 0 && num2 == 1); //true
	printf("%d\n", num == 0 || num2 == 0); //true

	printf("%d\n", num == 3 && num2 == 3); //false
	printf("%d\n", num == 3 || num2 == 3); //false

	//false��0
	//true��0�ȊO

	int result = (num == 1);
	printf("result = %d\n", result);

	if (result)
	{
		printf("result = true\n");
	}
	else
	{
		printf("result : false\n");
	}


	return 0;
}

	/*int a = 7;
	int b = a % 3; //a��3�Ŋ��������܂�

	printf("�ϐ�a�̒l��%d�ł�\n", a);

	switch (b) //���ǂ��ɍs���̂���I������֐��iif�̂悤�ɏ����Ƃ͂܂��Ⴄ���́j
	{
	case 0:
		printf("�ϐ�a��3�Ŋ������]���0�ł�\n");
		break;
	case 1:
		printf("�ϐ�a��3�Ŋ��������܂��1�ł�\n");
		break;
	default:
		printf("�ϐ�a��3�Ŋ��������܂��2�ł�\n");
		break;
	}

	//if-else���g���ď�������
	if (b == 0) {
		printf("�ϐ�a��3�Ŋ��������܂��0�ł�\n");
	}	
	if (b == 1) {
		printf("�ϐ�a��3�Ŋ��������܂��1�ł�\n");
	}	
	else {
		printf("�ϐ�a��3�Ŋ��������܂��2�ł�\n");
	}

	//�������킢��Ȃ����H
	printf("�ϐ�a��3�Ŋ��������܂��%d�ł�\n",b);
	*/


/*�������������Ă��邩
	int keyNum = 3;
	//�v���C���[�̃p���[
	int playerPower = 5600;

	//true(�^)�̏ꍇ�Aif()�̎���1�s�����s�����
	//false(�U)�̏ꍇ�Aif()�̎���1�s�͎��s����Ȃ�
	// 
	//!= �w�肳�ꂽ���ȊO�@==�w�肳�ꂽ���̂�
	if (keyNum != 1) {
		//{}�̒��ɍD���Ȃ���������������
		printf("��1���J����\n");
		keyNum--; //��������炷
		printf("�c��̌� : %d\n", keyNum);

	}
	else {
		printf("��1���J���Ȃ�\n");
	}


	//��������΃J�M���J���邱�Ƃ��ł���@if(keyNum >= 1)
	//�͂��Â��ŊJ���邱�Ƃ��ł���@�@�@�@if(playerPower >= 50)
	//�ǂ��炩�̎�i�Ŕ���˔j����@

	//�C���f���g�ɋC��t����	�K���g����悤�ɂȂ�Ȃ���΂Ȃ�Ȃ�
//	if (1){
//		printf("aaa\n");
//		if (1)
//		{
//			printf("bbb\n");
//		}
//	}

	//|| : �_���a�@or���Z
	if (keyNum >= 1 || playerPower >= 50) {
		printf("��2���J����\n");
		//�͂����ŊJ����ꍇ�͌�������Ȃ�
		if (playerPower >= 50) {
			printf("�͂����ŊJ�����I\n");
		}
		else {
			keyNum--; //��������炷
			printf("�c��̃J�M : %d\n", keyNum);
		}
	}
	else {
		printf("��2���J���Ȃ�\n");
	}

	//��������Ό����J���邱�Ƃ��ł���@�@�@if(keyNum >= 1)
	//�͂��Ȃ��Ɩ�Ԃ��F�߂Ă���Ȃ��@�@�@�@if(playerPower >= 50)
	//���������Ă��ė͂��Ȃ��Ɣ����J���Ȃ��@
	//�����̏����𖞂����K�v������@�@�@�@�@

	// && : �_���ρ@and���Z
//	if (keyNum >= 1 && playerPower >= 50)
//		printf("��3���J����\n");
//	else
//		printf("��3���J���Ȃ�\n");

	//else if ���g�p���ď������������
	if (keyNum <= 0) {
		printf("��3���J����J�M�������Ă��Ȃ�\n");
	}
	else if (playerPower < 50) {
		printf("��3�̖�Ԃ��͂�F�߂Ă���Ȃ�\n");
	}
	else {
	printf("��3���J����");
}*/




	/*
	int numInt = 10;
	
	float numFloat = 1.234f;
	//double numDouble = 12.35;  //�ʂ̏����������������x���Ȃ邩�炨�����߂͂��Ȃ�

	numInt = (int)numFloat; //�킩���Ă�float�̃f�[�^��int�ɓ˂�����ł���

	printf("numInt = %d\n", numInt); //�����_�ȉ��͂Ȃ��Ȃ��Ă���

	//�|�P�����Q�b�g�����v�Z����

	//���p�[�Z���g���A��\������ꍇ���ӂ������ł͊����ŊǗ������
	//�S�����@�@����
	//100��     1.0
	//50.12%    0.5012
	//12.25%    0.12225
	float getRate = 0.0f;

	int getNum = 32;         //�����Ă���|�P�����̎��
	int pokemomTotal = 151;  //�|�P�����̎�ށi�S�́j
	getRate = (float)getNum / (float)pokemomTotal;
	printf("getRate = %f\n", getRate);
	*/


/*int main(void)
{
	int testScore = 30;
	
	if (testScore == 100)
		printf("�������������炦��\n");
	else if (testScore >= 80)
		printf("�J�߂���\n");
	else if (testScore <= 40)
		printf("��T�ԊO�o�֎~\n");
	else
		printf("�Ȃɂ��Ȃ�\n");  //��̎O�̏������ׂĂ𖞂����Ȃ�



	return 0;
	
}*/


	/*
	int a = 5;
	int b = a % 2;

	if (a % 2 == 0)
		printf("%d�͋����ł�\n", a);
	else
		printf("%d�j�����ł�\n", a);
		*/


	/*
	//���������Ă��鐔
	int  keyNum = 0;
	//�L�����N�^�[�̃��x��
	int  level = 10;

	//����1�ȏ㎝���Ă�����J��
	if (keyNum >= 1)
		printf("�J��\n");
	else
		printf("�J���Ȃ�\n");

	//%% ; �ϗ��ρ@and���Z
	//������ȏ㎝���Ă��āA�v���C���[�̃��x����50�ȏ�Ȃ�J��
	//�����ɏ����𖞂����K�v������
	//keyNum >= 1��true level >=50���Ƃ���true�̏ꍇtrue�ɂȂ�
	if (keyNum >= 1 && level >= 50)
		printf("open\n");
	//printf("a�̒l��%d�ł�\n",a);

	//|| ; �ϗ��a�@or���Z
	//������ȏ㎝���Ă���J��
	//�v���C���[�̃��x����50�ȏ�Ȃ�͂����ŊJ��
	//�ǂ��炩�̏����𖞂�����OK
	//kerNum >= 1��true level >=1�̂ǂ��炩��true�̏ꍇtrue�ɂȂ�
	if (keyNum >= 1 || level >= 50)
		printf("open\n");
	
	//! ; �_���ے�@not���Z
	//!�����@������true�̏ꍇfalse,������false�̏ꍇtrue�ɂȂ�
	//�u�����Ă��錮�̐���0�������Ȃ��v��false�̏ꍇtrue�ɂȂ�
	if (!(keyNum <= 0))
		printf("open\n");
		*/

	/*int a = -1;

	if (a != 0)//  if (������)
	     printf("a�̒l�͕��̐��ł�\n");//��;

	printf("a�̒l��%d�ł�\n", a);*/

int main20230424(void)
{
//	printf("�������\������Ƃ���\nprintf()\n");

	//�@�|�P�����̃R���v���[�g�����v�Z������
	//�@�|�P�����̐���151���
	
	//�S�����@�@����
	// 100%     1.1
	// 50%      0.5
	// 25%      0.25

	//���ݓo�^����Ă���|�P�����̐�
	int pokeNum = 120;
	float rate = 0.0f;
	//�R���v���[�g���̌v�Z
	rate = (float)pokeNum / 151.0f;

	printf("�R���v���[�g�� = %f %%\n", rate * 100.0f);

	

	/*
	//�����^�iint�j�ɏ���������Ə����_�ȉ���������
	float numFloat = 1.99999f;
	int numInt = (int)numFloat;
    printf("numInt = %d\n", numInt);

	//float�ɐ����̒l������
	numInt = 256;
	numFloat = (float)numInt;
	printf("numFlosat = %f\n", numFloat);

	//���������_�͌덷����������
	float floatTest = 0.0f;
	floatTest += 0.1f;
	floatTest += 0.1f;
	floatTest += 0.1f;
	floatTest += 0.1f;
	floatTest += 0.1f;
	floatTest += 0.1f;
	floatTest += 0.1f;
	floatTest += 0.1f;
	floatTest += 0.1f;
	floatTest += 0.1f;
	printf("floatTest = %f\n", floatTest);
	printf("floatTest = %1.16f\n", floatTest);
	*/

	/*
	int test = 10 + 10 * 3;
	printf("test = %d\n ", test);

	test = (10 + 10) * 3;
	printf("test = %d\n ", test);
	*/


	/*
	int hp = 100;

	hp = hp - 10;
  //(��)hp -= 10;  // hp = hp - 10�Ɠ���

	hp--; //�f�N�������g���Z�q�@�ϐ��̒l���P���炵�Ă��̕ϐ��ɑ��
	hp++; //�C���N�������g���Z�q�@�ϐ��̒l���P���炵�Ă��̕ϐ��ɑ��

	++hp;
	--hp;

	hp = 10;
	hp++;
	int a = hp;
	printf("a = %d, hp = %d\n" , a, hp);

	hp = 10;
	++hp;
	int b = hp;
	printf("b = %d,hp = %d\n", b, hp);
	*/

	/*�ϐ�
	int numInt = 10;          //����
	float numFloat = 1.234f; // ����
	char numChar = 'z';      //����

	numInt = 10 + 10; //���Z
	numInt = 10 - 10; //���Z
	numInt = 10 * 10; //��Z

	numInt = 10 / 10; //���Z
	numInt = 10 % 10; //�\�Z

	numInt = 53;

	printf("����Z %d / 5 = %d ���܂�@%d\n",
		numInt, numInt / 5, numInt % 5);
*/


	/*printf("������\������Ƃ��@%d\n", numInt);
	printf("������\������Ƃ��@%f\n", numFloat);
	printf("�P������\������Ƃ��@%c\n", numChar);

	printf("�����@%c\t���� %d\t���� %f\n", 'y', 64, 3.14f);
	*/
	return 0;
}