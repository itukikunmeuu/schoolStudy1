#include<stdio.h>

//�萔���`
#define NUM 16

int main(void)
{
	int test[NUM];  //test[0] test[1] test[2] test[3] test[4]

	for (int i = 0; i < NUM; i++)
	{
		test[i] = i * 10;
	}

	//�_����\������
	for (int i = 0; i < NUM; i++)
	{
		printf("%d : %d�_\n", i + 1, test[i]);
	}

	return 0;
}

/*
/*
int func(int a)
{
	int b = a * 2 + 1;
	return b;
}
*
  #define func(a) a * 2 + 1

int main(void)
{
//	printf("test : %d\n", func(5));
	// ���̂悤�ɒu��������
//	printf("test : %d\n", 5 * 2 + 1);

	printf("test : %d\n", func(1));
	printf("test : %d\n", 1 * 2 + 1);

	printf("test : %d\n", func(3));
	printf("test : %d\n", 3 * 2 + 1);

	printf("test : %d\n", 2*func(3));
	printf("test : %d\n", 2*3 * 2 + 1);

	return 0;
}*/