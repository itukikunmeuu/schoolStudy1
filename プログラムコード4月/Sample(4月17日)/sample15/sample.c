#include<stdio.h> //printf,scanf_s
#include<stdlib.h> //ramd(),srand()

//������̘A��
//"abc"��"def"��A������"abcdef"�Ƃ���������ɕϊ�����
//���Ɏg���́H

//�Q�[���ł̓t�@�C���p�X�̍쐬�ȂǂɎg�����肷��
//�t�@�C���p�X�H�@�@�t�@�C���̃R���s���[�^��̒u���ꏊ
//�@C:\user\teacher\desktop\fukuoka\�v���O���~���O1�����ۑ�.txt


int main(void)
{
	char str1[100] = "Hello!";
	char str2[] = "G_Gengo";

	//(�������镶����A����������邱�Ƃ��ł���T�C�Y�A�������镶����2)
	strcar_s(str1, sizeof(str1), str2);

	printf("%s\n", str1);

	return 0;
}

//sizeof���Z�q���g�p����
//�f�[�^�^��z��̍��v�o�C�g�����擾���邱�Ƃ��ł���
/*
int main(void)
{
	printf("���s���ł�int�^��%d�o�C�g�ł�\n", sizeof(int));
	printf("���s���ł�int�^��%d�o�C�g�ł�\n", sizeof(char));
	printf("���s���ł�int�^��%d�o�C�g�ł�\n", sizeof(float));
	//char�@��1�o�C�g
	//�܂�str[]�̃T�C�Y��10�o�C�g�Ȃ�z��̗v�f����10���Ƃ킩��
	//char str[] = "C_Gengo"l
	//printf("�z��str�̂΂��Ƃ�����%d�ł�\n",(int)sizeof(str))

	char str[100];

	printf("������𔼊p�œ��͂��Ă�������\n");
	scanf_s("%s", str, 100);

	printf("�z��str�̃o�C�g����%d�ł�\n", (int)sizeof(str));

	printf("������̒�����%d�ł�\n", srtlen(str));

	return 0;
}*/
//strlen()�ŕ�����̒������v������
/*
int main(void)
{
	char str[100];
	int length;

	printf("������𔼊p�œ��͂��Ă�������\n");
	scanf_s("%s", str, 100);

	//strlen()�֐��A������̒������擾���邽�߂̊֐�
	//�����Ƃ��ĕ�������w�肷��
	// ������̒�����߂�l�Ƃ��ĕԂ��Ă����
	length = strlen(str);

	//strlen()�֐����Ԃ��Ă���钷����NULL����(\0)�͊܂܂�Ȃ�
	printf("%s��%d�����ł�\n", str, length);

	return 0;
}*/
// scanf_s()���g�p���ăL�[�{�[�h������͂��ꂽ������z��Ɋi�[����
/*
int main(void)
{
	//�L�[�{�[�h����󂯎�镶������i�[���邽�߂̔z��
	char str[100];

	printf("������𔼊p�œ��͂��Ă�������\n");

	scanf_s("%s", str,100);  //&str�ł͂Ȃ�
	printf("%s�����͂���܂���\n", str);

	//�Q�l�@scanf_s�Ő��l����
	int num = 0;
	scanf_s("%d", &num);
	return 0;
}*/
//������̏�����
/*
int main(void)
{
	char str[] = "C_Gengo";

	//str = "D_Gengo"; //�G���[

//	printf(str);
	printf("�������%s�ł�\n", str);
	return 0;
}*/
//������
/*
int main(void)
{
	char str[8];

	str[0] = 'c';
	str[1] = '_';
	str[2] = 'G';
	str[3] = 'e';
	str[4] = 'n';
	str[5] = 'g';
	str[6] = 'o';
	str[7] = '\0'; //\n�Ƃ�\t�̐e��

	printf(str); //printf��char�̔z����w�肷��ꍇ�͔z�񖼂݂̂������Ƃ���
	printf("\n");

	char str2[5];
	str2[0] = 'A';
	str2[1] = 'B';
	str2[2] = '\0'; //������̓r���H�ɂm�t�k�k����
	str[3] = 'C';
	str2[4] = 'D';

}
*/
//����
/*
int main(void)
{
	//'A' �V���O���R�[�e�[�V�����̒��ɔ��p�ꕶ��
	//�������@char�^�ɕۑ�����

	//"������"�@�_�u���R�[�e�[�V�����̒��ɕ�������
	//��������@printf�����g�p����
	//�������String Text�Ƃ������Ă΂�������邱�Ƃ�����

	//"A" �_�u���R�[�e�[�V�����̒��ɔ��p1����
	//�����������

	//���܂ł�printf()�̊֐��̈����Ƃ��ĕ�������w�肵�Ă���
	printf("�\��������������\n");

	return 0;
}*/