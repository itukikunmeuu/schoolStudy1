#include<stdio.h>

int main(void)
{
	int num = 11;
	int* pNum = &num;
	//pNum�̒��ɂ͕ϐ�num�̃A�h���X�������Ă���

	//pNum(�A�h���X)����ϐ�num�̒l���擾������
	printf("pNum�̒��g �F%d\n", *pNum);

	int tbl[3] = { 12,13,14 };
	//�z��̊e�v�f�̃A�h���X���擾����
	//tbl[1]�̃A�h���X���擾������
	&tbl[1]; //��{tbl[1]�̑O��&�����Ă��̃A�h���X���擾����

//	tbl;     //�z�񖼂̂݁@�z��̐擪�A�h���X
//	tbl + 1; //�z��(�擪�A�h���X)��1�𑫂�
			//�A�h���X��1�𑫂����ꍇ�A�P����1�o�C�g�����̂ł͂Ȃ�
			//�f�[�^�T�C�Y1�͂����

	//���Ⴀ(�z�񖼁@+�@�v�f�ԍ�)�̏�������
	//*�@��g�ݍ��킹�Ĕz��̎w�肵���v�f�̒��g

	printf("tbl[0]�̒l��%d�ł�\n", tbl[0]);
	printf("*tbl�̒l��%d�ł�\n", *tbl);

	printf("tbl[1]�̒l��%d�ł�\n", tbl[1]);
	printf("*(tbl+1)�̒l��%d�ł�\n", *(tbl + 1));

	printf("tbl[0]�̒l��%d�ł�\n", tbl[1]);
	printf("*(tbl+2)�̒l��%d�ł�\n", *(tbl + 2));

	return 0;
}

//�z��ƃ|�C���^
/*
int main(void)
{
	int height[3] = { 170,169,178 };

	printf("int�^�̃T�C�Y��%d�o�C�g�ł�\n", sizeof(height[0]));

	//�z��͕K����������ɕ���Ŕz�u�����

	//�z�񖼁@���̓A�h���X�ł��@�z��S�̂̐擪�A�h���X�������Ă���
	//int num[3];   num���A�h���X�@num[0]�̐擪�A�h���X�Ɠ���
	//�A�h���X�Ȃ̂Ń|�C���^�ɕۑ����邱�Ƃ��ł���
	//int* pNum = num;
	//num + 1 ?	
	//�A�h���X�ɑ΂���+1���Ă��ƁA���̃f�[�^�T�C�Y�����ꂽ�A�h���X���������
	//int�Ȃ�4Byte�Ȃ̂�4,char�Ȃ�1Byte�Ȃ̂�1�������
	
	printf("height[0]�̃A�h���X��%p�ł�\n", &height[0]);	//�������͂킩��
	//�z�񖼂��������Ɣz��̐擪�A�h���X���擾�ł���
	printf("height�̒l��%p�ł�\n", height);					

	printf("height[1]�̃A�h���X��%p�ł�\n", &height[1]);
	//�A�h���X+1���̌v�Z���s���Ƃ��̃f�[�^�T�C�Y�����ꂽ�A�h���X���擾�ł���
	printf("height+1�̒l��%p�ł�\n", height + 1);

	printf("height[2]�̃A�h���X��%p�ł�\n",&height[2]);
	//
	printf("height+2�̒l��%p�ł�\n", height + 2);


	return 0;
}*/

//�������A�A�h���X
//�|�C���^�A�A�h���X���|�C���^�ɕۑ�����
//�̕��K
/*
void function(int num)
{
	printf("�����Ƃ��ēn���ꂽ������%d�ł�\n",num);
	printf("function���Ŏg�p�ł���ϐ�num�̃A�h���X��%p�ł�\n", &num);

	num = 256;
}


int main(void)
{
	int num;
	char chr;

	//&�ϐ����@�ł��̕ϐ��̊m�ۂ���Ă���A�h���X���擾�ł���
	printf("num�̓A�h���X%p�Ɋm�ۂ���Ă��܂�\n", &num);

	num = 16;
//	function(num);
	printf("num = %d\n", num);

	//�A�h���X��ϐ��Ƃ��ĕۑ�����ɂ�
	//�A�h���X�̓|�C���^�ɕۑ�����
	int* pNum;  //int 4Byte char 4Byte   int* �́�8Byte(64bit)
	//%p�ŕ\�������Ƃ��A�A�h���X��16�i��16���ŕ\�����ꂽ
	//16�i���ꌅ�i0�`f�j��4�r�b�g�ŕ\���\�i0000 ~ 1111�j
	//�܂�16�i��16���Ƃ������Ƃ�4�ibit�j * 16(��)�@���@64(8Byte)
	
	pNum = &num; //num�̃A�h���X���|�C���^�ϐ�pNum�ɑ������
	printf("pNum = %p\n", pNum);

	//�|�C���^(�A�h���X)���炻���Ɋi�[����Ă���f�[�^�̒��g���Q�Ƃ���
	//�ǂ�����āH
	//�A�h���X�̑O��*��t����
	printf("pNum�̒��g��%d�ł�\n", *pNum);

	return 0;
}*/