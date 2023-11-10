#include<stdio.h>
#define NUM 3

//マクロを宣言しているだけ
//DEBUGというマクロがある、ということを利用する
//DEBUGとついているけれどint同様に特に指定はない（わかりやすい名前として付けるとよい）

#define PRINT_DEBUG 

int main(void)
{
	float sum = 0;
	int test[NUM];

	for (int i = 0; i < NUM; i++)
	{
		printf("%d番目の生徒の点数を入力してください\n", i + 1);
		scanf_s("%d", &test[i]);
	}

	for (int i = 0; i < NUM; i++)
	{
#ifdef PRINT_DEBUG
		printf("%d番目の生徒は%d点です\n", i + 1,test[i]);
#endif 
		sum += test[i];
	}

//マクロDEBUGを未定義に戻す
//#undef PRINT_DEBUG


#ifndef PRINT_DEBUG
	printf("合計点は%fです\n", sum);
#else PRINT_DEBUG
	printf("PRINT_DEBUGないです\n");
#endif

	printf("%d人の平均点は%f点です\n", NUM, sum / NUM);

	return 0;
}