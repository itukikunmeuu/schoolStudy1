#include<stdio.h>
#define NUM 3

//�}�N����錾���Ă��邾��
//DEBUG�Ƃ����}�N��������A�Ƃ������Ƃ𗘗p����
//DEBUG�Ƃ��Ă��邯���int���l�ɓ��Ɏw��͂Ȃ��i�킩��₷�����O�Ƃ��ĕt����Ƃ悢�j

#define PRINT_DEBUG 

int main(void)
{
	float sum = 0;
	int test[NUM];

	for (int i = 0; i < NUM; i++)
	{
		printf("%d�Ԗڂ̐��k�̓_������͂��Ă�������\n", i + 1);
		scanf_s("%d", &test[i]);
	}

	for (int i = 0; i < NUM; i++)
	{
#ifdef PRINT_DEBUG
		printf("%d�Ԗڂ̐��k��%d�_�ł�\n", i + 1,test[i]);
#endif 
		sum += test[i];
	}

//�}�N��DEBUG�𖢒�`�ɖ߂�
//#undef PRINT_DEBUG


#ifndef PRINT_DEBUG
	printf("���v�_��%f�ł�\n", sum);
#else PRINT_DEBUG
	printf("PRINT_DEBUG�Ȃ��ł�\n");
#endif

	printf("%d�l�̕��ϓ_��%f�_�ł�\n", NUM, sum / NUM);

	return 0;
}