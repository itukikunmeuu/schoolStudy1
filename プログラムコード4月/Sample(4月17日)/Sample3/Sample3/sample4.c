#include<stdio.h>

int main(void)
{
	int num1 = 8;  //int; �����i���̒l���g����j
	float num2 = 1.5;  //float:�@��������������
	char num3 = 'A';  //char:  �����i���p�ꕶ���j����������

	//�L���X�g�̗�
	printf("(int)num2 = %d\n", (int)num2);

	// int�^��float�^�̒l����
	printf("num1 + num2 = %f\n", num1 + num2);  //num1 + num2��float
    printf("num1 = %d\n", num1);

	int ans = num1 + num2;
	printf("ans = %d\n", ans);

	float ans2 = ans;
	printf("ans2 = %f\n", ans2);

	int num4 = 128;
	char num5 = 127; 
	printf("num4 + num5 = %d\n", num4 + num5); //mum4+num5��



	return  0;
}


	/*
	int a,b,c;
	b = 1;
	c = 5;

	b = c;
	a = b;

	//a = b = c;
    //a = b = 1;

	printf("a=%d\n", a);
	printf("b=%d\n", b);
	printf("c=%d\n", c);

	return 0;
}*/

/*int main(void)
{
	int ans;

	int a = 2;
	int b = 3;
	int c = 5;

	ans = a + b * c; //�����Z�����|���Z���D�悳���
	printf("%d + %d * %d = %d\n",a,b,c ,ans);
} */

/*int main(void)
{
	int a;
	int b;

	b = 5;

	b++;
    a = b;   //���l�Ɍ����Ă����C�ł킩��₷�����̂�
	
	printf("a�̒l��%d�ł�\n", a);
	printf("b�̒l��%d�ł�\n", b);
}*/


/*int main(void)
{
	int hp = 100;
	int enemyAttack = 10;

	//�_���[�W���󂯂�
	hp = hp - 10;
	printf("HP;%d\n", hp);
	//������Z�q���g�p����������
	hp -= enemyAttack;

	printf("HP;%d\n", hp);

	//�r�b�g�V�t�g������
	int shiftTest = 100;
	printf("shiftTest %d\n", shiftTest << 1);  //����1�r�b�g�V�t�g
	printf("shiftTest %d\n", shiftTest >> 1);  //�E��1�r�b�g�V�t�g

	int num = 6;
	//�C���N�������g���Z�q�@�C���N�������g
	num += 1;  //num��1�𑫂���num�ɑ������@num +1. num = mim+1�Ɠ���

	//�f�N�������g���Z�q
	num--;  //num����1��������num�ɑ������@num -= 1 , mum = num -1�@�Ɠ���
	printf("num;%d\n", num);



	return 0;
}*/

/*int main(void)
{
	printf("4/21�̎���\n");

	int testnum = 16; //�e�X�g�p�̐���

	int hp = 100;
	printf("�v���C���[��HP:%d\n", hp);

	//�l�����Z���s�������ʂ�\������
	printf("�v���C���[��HP+10: %d\n", testnum + 10);
	printf("�v���C���[��HP-10: %d\n", testnum - 10);
	printf("�v���C���[��HP*10: %d\n", testnum* 10);
	printf("�v���C���[��HP/10: %d\n", testnum/ 10);
	printf("�v���C���[��HP/10�̂��܂�: %d\n", testnum % 10);

	//�l�����Z���s�������ʂ�\������
	printf("�v���C���[��HP+10: %d\n", hp + 10);
	printf("�v���C���[��HP-10: %d\n", hp - 10);
	printf("�v���C���[��HP*10: %d\n", hp * 10);
	printf("�v���C���[��HP/10: %d\n", hp / 10);
	printf("�v���C���[��HP/10�̂��܂�: %d\n", hp % 10);

	printf("\n");  //�����ɂ����̂ŉ��s

	//�ϐ��ɒl��������
	hp = 150;
	printf("�v���C���[��HP;%d\n", hp);

	//�G�̍U����
	int enemyAttack = 24;

	//���@���g���ēG�̍U���͂𔼌�������
	enemyAttack = enemyAttack / 2;
	printf("���@���g�����I\n�G�̍U���͂�%d�ɂȂ����B\n", enemyAttack);

	//�_���[�W���󂯂��@HP�����炵����
	//HP��20���炵����
	hp = hp - 20;
	printf("�_���[�W��%d�󂯂��I\n�v���C���[��HP�G%d\n",enemyAttack, hp);
	
	//HP�����𔽓]������
	hp = -hp;
	printf("hp : %n\n", hp);
	hp = -hp;
	printf("hp : %n", hp);
	return 0;} */