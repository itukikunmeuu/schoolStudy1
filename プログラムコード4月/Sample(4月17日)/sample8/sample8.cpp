#include<stdio.h>

//"�֐������s����܂���\n"�ƕ\�����邽�߂̊֐�
void dispPrintf(void) {
	printf("�֐������s����܂���\n");
	return;
}

//�����Ƃ��ēn���ꂽ���̒l��
//�����1�𑫂����l��\�����邽�߂̊֐�
void f(int x) {
	printf("�n���ꂽ�ϐ��̒l��%d�ł�\n", x);
	x++;
	printf("1�𑫂����l��%d�ɂȂ�܂�\n", x);
	return;
}

int main(void)
{
//	printf("�v���O�������J�n����܂���\n");
//	dispPrintf();
//	printf("�v���O�������I�����܂�\n");
	f(3);


	return 0;
}