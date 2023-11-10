#include<stdio.h>
#include<stdlib.h> //rand.standを使うのに必要
#include<time.h>   //timeを使うのに必要


//ランダムな数値の生成
int main(void)
{
	// rand()使用準備
	srand((unsigned int)time(NULL)); //0秒に実行したときと1秒に実行したときで違うさいころを使う

	int randNum = 0;		//ランダムに生成された数値を保存するための変数
	for (int i = 0; i < 8; i++)
	{
		randNum = rand();		//rand()関数の戻り値をrandNumに代入する
		printf("ランダムな数字:%d\n", randNum % 3);
	}


	return 0;
}



// scanf_sを利用してキーボードから数値を入力する
/*
int main(void)
{
	//printfは文字列を表示するための関数
	printf("文字列を表示する\n");

	//scanf_sはキーボードからの入力を受け付けるための関数
	int inputNum = 0;  //プレイヤーが入力した数字を保存するための関数
	scanf_s("%d", &inputNum); //キーボードから整数の入力を受け付ける

	printf("入力した数字:%d\n", inputNum);

	return 0;
}
*/