/*��ʂ֕������\������v���O����*/
#include<stdio.h>
int main(void)
{
	int a = 1;
	int b = -1;
	printf("a = %d\n", a);
	printf("+a = %d\n", +a); //+(1)
	printf("-a = %d\n", -a); //-(1)

	printf("b = %d\n", b);
	printf("+b = %d\n", +b);  //+(-1)
	printf("-b = %d\n", -b);  //-(-1)

	printf("a+b = %d\n", a+b);

 


//	printf("1 + 2 = %d\n", 1 + 2);        //�����Z
//	printf("3 - 1 = %d\n", 3 - 1);        //�����Z
//	printf("5 * 3 = %d\n", 5 * 3);        //�|���Z
//	printf("7 / 2 �̗]��@%d\n", 7 % 2);  //����Z�i�]����o���ꍇ�j

//	printf("7 / 2 = %d\n", 7 / 2);        //����Z�i�]����o���Ȃ��Ă������ꍇ�j

	return 0;

}

/*
int main(void)
{
	//�v�f���啶���ɂ��邱�Ɓ@�L�������P�[�X
	int recoveryItemNum = 0;   //�񕜃A�C�e���̐�
	//���ƕ��̊ԂɁQ�����邱�� �X�l�[�N�P�[�X
	int recovery_item_num = 0;
	//�o���Ăق����ϐ��̕�
	unsigned int num = 123;     //�@iny �����^
	float dig = -4.0;           // float ����
	char chr = '3';             //�@char ����1�����i���p�P�����j

	/*
	
	'B'         //�����i�P�����j
	'3'         //�����i�P�����j

    "ABC"       //������i������̕��сj
	"C����"     //�S�p���܂ޕ�����
	'��'        //�S�p�����͂P�����ł͂Ȃ�
	"Z"         //������
	
	

//	printf("num = %d\n", num);
//	printf("dig = %f\n", dig);
//	printf("chr = %c\n", chr+1);

//	printf("chr = %d\n", chr);
	//�ϐ��̐錾
	int test;

	int test2;
	int test3;
    test2 = 120;
	test3 = 240;

	test = test2; //���͌v�Z���ʂł͂Ȃ�������������Ƃ�������
//	printf("test = %d\n", test);
    test = test3;
//	printf("test = % d\n", test);

/*	int test = 0x7c;

	printf("test = %d\nabc\n. test");

	printf("%d\t%d\t%d\n"., 1, 2, 3);
	printf("%d\t%d\t%d\n"., 10, 20, 30);

	printf("\\t\n");
	printf("\")
	
	




	return 0;
} */
