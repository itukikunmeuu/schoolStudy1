#include<stdio.h>

//2�̒l��,��(int �ȉ����ׂĂ���)��n���Ă��̍��v��Ԃ��֐�
//int add()

//2�̒lx,y��n���Ă��̍���Ԃ��֐�(�P���Ȉ����Z��OK)
//int sub()

//2�̒lx,y��n���Ă��̏�Z���ʂ�Ԃ��֐�
//int mul()

//2�̒lx,y��n����x��y����Ԃ��֐�
//int pow()

int add(int x, int y)
{
	int z = x + y;
	return z;
}
int sub(int x, int y)
{
	int z = x - y;
	return z;
}
int mul(int x, int y)
{
	int z = x * y;
	return z;
}
int pow(int x, int y)
{
	int z = x / y;
	return z;
}


//�߂�l�̗��K
int main(void)
{
	int x = 4;
	int y = 3;

	int result = add(x,y);
	printf("add = %d\n", result);

	result = sub(x,y);
	printf("sub = %d\n", result);

	result = mul(x,y);
	printf("mul = %d\n", result);

	result = pow(x,y);
	printf("pow = %d\n", result);

	return 0;
}

//�߂�l
/*
int goukei(int x, int y) {
	return (x+y);
}

//�߂�l�̕׋�
int main(void)
{
	int a = goukei(1, 3);
	printf("���v��%d�ł�\n",a);
	return 0;
}
*/

//��r�֐�
/*
//2�̒l�̂����A�ǂ��炪�傫�������r����֐�
void bigger(int x, int y)
{
	printf("z = %f\n", z);
	printf("2�̈����̂����A�傫���ق���\������\n");
	if (x > y) {
		printf("%d�̂ق����傫���ł�\n", x);
	}
	else
	{
		printf("%d�̂ق����傫���ł�\n", y);
	}
	return;
}

int main(void)
{
	bigger(1, 5);
	return 0;
}

*/

//�֐��̕��K
/*
//�֐�������
// 1.����������������Ă���ꏊ����������ꍇ
//��.�Q�[���̏ꍇ�_���[�W�����Ȃ�
//�@�_���[�W����->HP�����炵�āA��ʂ�h�炵�āA�v���C���[���Ԃ��_�ł���
//�@�������������㏑���������ȁA�Ǝv������֐���

// 2.�p�b�g���ĉ�������Ă��邩�킩��Ȃ�����
//   �\�[�X�����Ă��킩��Ȃ������ɕ�����₷������������
//�@float angle = acos(cross(dir,toEnemy));
//  printf("angle = %f\n",angle);
//  ��
//void calcAngle(void) //�֐�����������p�x���v�Z���鏈�����ȁB�Ƃ킩��
//{
//	float angle = acos(cross(dir, toEnemy));
//	printf("angle = %f\n", angle);
//	return;
//}


void dispWin(void)
{
	printf("�����I\n");
	return;
}

//��������̂��񂷂�
//�����ɉ������������s�����Ƃ��ł���
void dispNumber(int num)
{
	printf("num = %d\n", num);
	return;
}


//�֐��̒��œn���ꂽ�l��ύX����
void addNumber(int num)
{
	printf("num = %d\n", num);
	num += 10;
	printf("num+10 = %d\n", num);
	return;
}


//�֐��̒��ł�if,for,while�Ȃǎg����
//�����͕��ʂ̕ϐ��̂悤�Ɉ�����
void forFonction(int num)
{
	for (int i = 0; i < num; i++);
	printf("test\n");
}



//�֐��̕��K
int main(void)
{
//	dispWin();
	int inputNum = 0;
	scanf_s("%d", &inputNum);
//	dispNumber(inputNum);
//	addNumber(inputNum);
//	printf("inputNum = %d\n", inputNum);
	forFonction(inputNum);


	return 0;
}
*/