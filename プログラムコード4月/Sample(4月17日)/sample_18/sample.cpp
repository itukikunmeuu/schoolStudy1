#include<stdio.h>

//�e�X�g�̐��уf�[�^�\����
typedef struct Test
{
	int kokugo;
	int sansuu;
	int rika;
	int syakai;
}Test;

//���k�̃f�[�^�\����
typedef struct Student
{
	int no;
	float height;
	float weight;
	//�\���̂��\���̂̃����o�[�Ƃ��Ď���
	Test exam;
}Student;

int main(void)
{
	Student student2 = { 2,169.5f,54.5f,{80,70,90,65} };

	printf("2�l�ڂ̐��k�̏o�Ȕԍ���%d�ł�\n", student2.no);
	printf("2�l�ڂ̐��k�̐g����%fcm�ł�\n", student2.height);
	printf("2�l�ڂ̐��k�̎Z���̓_����%d�ł�\n", student2.exam.sansuu);

	return 0;
}

//typedef��p�����\���̐錾
/*
typedef struct Student
{
	int no;
	float height;
	float weight;
}Student;

int main(void)
{
	Student student1 = {1, 170.5f,58.0f};

	printf("1�l�ڂ̐��k�̏o�Ȕԍ���%d�ł�\n", student1.no);
	printf("1�l�ڂ̐��k�̐g����%fcm�ł�\n", student1.height);
	printf("1�l�ڂ̐��k�̑̏d��%fkg�ł�\n", student1.weight);

	return 0;
}*/

//�\���̖̂��O��
/*
//���k�̃f�[�^�Ǘ��p�\���̂̒�`

//Student �ł��@student �ł��ǂ���ł��Z�@��₱�����Ȃ邩���ʕt���̂��ߑ啶���Ə������ɕ�����
typedef struct Student
{
	int no;
	float height;
	float weight;
}Student;
//���O�̕ύX�@�ύX����Ƃ��̂��Ƃ̍\���̂ŊȒP�ɂ����\���̂��g�p���邱�Ƃ��ł���
//	typedef struct Student Student;

int main(void)
{
	//�������Ȃ��̍\���̕ϐ��̐錾
	Student student1 = {1,170.5f,58.0f};
	//�������t���̍\���̕ϐ��̐錾
	struct Student student2 = {2,169.0f,54.5f};

	//�\���̂ɍ\���̂�������
	student1 = student2;

	printf("1�l�ڂ̐��k�̏o�Ȕԍ���%d�ł�\n", student1.no);
	printf("1�l�ڂ̐��k�̐g����%fcm�ł�\n", student1.height);
	printf("1�l�ڂ̐��k�̑̏d��%fkg�ł�\n", student1.weight);

	return 0;
}*/

//�\���̂̎g����
/*
int main(void)
{
//	int num; //�^���@�ϐ����G
//	struct Sudent student1; //struct �\���̖��@�ϐ���;
	//�������t���̍\���̕ϐ��̐錾
	struct Sudent student1 = { 1,170.5f,58.0f };

	//.	���g�p���č\���̂̃����o�ɃA�N�Z�X����
	student1.height = 170.5f;

	return 0;
}*/