#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int main(void)
{
	printf("コンピューター【僕と勝負しようよ】\n");		//コンピュータの文字を表示させる
	printf("0を入力するとグーと表示するよ\n");			//ルール説明の文章を作る
	printf("1を入力するとチョキと表示するよ\n");		//ルール説明の文章を作る
	printf("2を入力するとパーと表示するよ\n");			//ルール説明の文章を作る
	int a = 0;
	srand((unsigned int)time(NULL));					//数字を入力する
	int randNum = 0;
	int num = 0;
	int winCount = 0;									 //勝った回数を数える
	int loseCount = 0;									 //負けた回数を数える
	for (int i = 0; i < 3; i++)
	{
		printf("========================\n");
		scanf_s("%d", &a);								//入れた値を出力
		randNum = rand();								//rand()関数の戻り値をrandNumに代入する
		num = randNum % 3;
		printf("%dを入力したよ",a);						//入れた値がなんなのかを表示させる
		if (a == 0){									//入れた値がなんなのかを求める
			printf("グー\n");
		}
		else if (a == 1) {
			printf("チョキ\n");
		}
		else {
			printf("パー\n");
		}


		if (num == 0)									//コンピュータが何の値が何なのかを求める
		{
			printf("グー\n");
		}
		else if (num == 1)
		{
			printf("チョキ\n");
		}
		else
		{
			printf("パー\n");

		}

		if (a == 0 && num == 1) {						//どちらの勝ちなのかを決める
			printf("勝ち\n");							//勝った場合は+1して値を増やす
			winCount++;
			printf("勝った回数は%dだよ\n", winCount);
		}
		else if (a == 1 && num == 2) {
			printf("勝ち\n");
			winCount++;
			printf("勝った回数は%dだよ\n", winCount);
		}
		else if (a == 2 && num == 0)
		{
			printf("勝ち\n");
			winCount++;
			printf("勝った回数は%dだよ\n", winCount);
		}
		else if (a == num) {
			printf("あいこで...\n");
			i--;
			continue;
		}
		else
		{
			printf("負け\n");
			loseCount++;
		}

	}
	if (winCount > 1) {									//勝者を決める
		printf("勝った回数　%d 負けた回数　%d\n",winCount,loseCount);
		printf("勝者　プレイヤー！！\n");
		printf("コンピューター【え、負けちゃった。つぎは負けないからなまた挑戦しろよ！】\n");
	}
	else
	{
		printf("勝った回数　%d 負けた回数　%d\n",winCount,loseCount);
		printf("勝者　コンピューター\n");
		printf("コンピューター【残念、僕の勝ちだね＾＾】");
	}
	return 0;
}


