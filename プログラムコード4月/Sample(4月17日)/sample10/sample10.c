#include<stdio.h>
#include "kadai.h"

int main(void)
{
	//作成した関数を呼び出し
	//表示した*の数をprint表示する」
	int num = kadai(8);
	printf("*の数　= %d\n", num);

	return 0;
}



/*
//プロトタイプ宣言
void f1(int x);

int main(void)
{
	int inputNum = 0;
	printf("整数を入力してください\n");
	scanf_s("%d", &inputNum);
	int num = 0;
	f1(1);
	
	while (num = inputNum)
	{
		num = num + inputNum;
		num++;
	}
		printf("*の数は%dです\n", inputNum);

	return 0;
}*/

void f1(int x) {
	printf("引数%dが渡されました\n", x);
}
//プロトタイプ宣言
/*
void f(int x);			 //引数の値を表示する
void f2(int x);			//引数の値を表示する
void f3(int x,int y);	//引数の値を表示する

int main(void)
{
	f(2);
	f2(2);
	//作成した関数を呼び出し
	//表示した*の数をprint表示する


	return 0;
}*/
	//整数を入力
	/*
	int inputNum = 0;
	printf("整数を入力してください\n");
	scanf_s("%d", &inputNum);
	printf("整数=%d\n", inputNum);
	*/
	//小数を入力
	/*
	float inputFloat = 0.0f;
	printf("小数を入力してください\n");
	scanf_s("%f", &inputFloat);
	printf("小数=%f\n", inputFloat);
	*/
	//文字を入力
	/*
	char inputChar = 'A';
	printf("半角1文字を入力してください\n");
	inputChar = getchar();
	printf("半角1文字=%c\n", inputChar);
	*/