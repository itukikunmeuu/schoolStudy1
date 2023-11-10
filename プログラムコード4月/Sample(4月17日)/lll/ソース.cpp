#include<stdio.h>
#include<stdlib.h>
#include<time.h>


/*
	//プレイヤーの手と敵の手を引数として受け取り
	// 最終的に【グー　vs　パー】のように表示する関数
	void dispBattle(int playerHand,int enemyHand)
	{
		//プレイヤーの手　vs　敵の手となるように表示を行う
		// それぞれグーチョキパーはdispHand()引数を使用して表示する

		//プレイヤーの手を表示する
	//	dispHand(playerHand);
		// vsを表示する
		printf(" vs ");
		//敵の手を表示する
	//	dispHand(enemyHand);

		return;
	}*/
/*

	//プレイヤーの勝利数、プレイヤーの敗北数の2つを引数として受け取り。
	//プレイヤー勝利数のほうが多い場合は「勝ち」
	//プレイヤーの勝利数のほうが少ない場合は「負け...」
	//プレイヤーの勝利数がおなし場合は「引き分け」
	//と表示する関数
	void dispResult(int win,int lose)
	{
		printf("%d - %d", win, lose);//最終的な勝敗数表示
		//勝敗に応じた結果を表示する
		if (win > lose)
		{
			printf("勝った回数　%d 負けた回数　%d\n", win, lose);

			printf("勝ち！");
		}
		else if(win < lose)
		{
			printf("勝った回数　%d 負けた回数　%d\n", win, lose);
			printf("負け...");
		}
		else
			printf("引き分け");
		}
		return;
	}*/
//グーチョキパーを表示するための関数
//引数として0が渡されたらグーと表示
//引数として1が渡されたらチョキと表示
//引数として2が渡されたらパーと表示
/*void dispHand(int hand)
{
	/*
	if (hand == 0)
	{
		printf("グー");
	}
	else if (hand == 1)
	{
		printf("チョキ");
	}
	else if (hand == 2)
	{
		printf("パー");
	}
}*/

//ランダムな手（グー。チョキ、パー）を生成して返す関数
//敵の手をこの関数を使用して生成するように変更
int createRansHand(void)
{
	return rand() % 3;
}


//プレイヤーの手、敵の手を引数として渡して
//プレイヤーが勝っている場合は1
//プレイヤーが負けている場合は-1
//あいこの場合は0
//を返す関数を生成する
//実際の判定部分を使用して行うように変更
int getBattleResult(int playerHand,int enemyHand)
{
	//勝敗判定
	int result = 0; //勝ちなら1負けなら-1、あいこなら0を入れる
	//引き分けなら0を返す
	if (playerHand == enemyHand) {
		//あいこ
		result == 0;
		}
	if (playerHand == 0) {
		if (enemyHand == 1) {
			result = 1;
		}

		else if (enemyHand == 2) {
			result = 1;
		}
		//勝ってたら1を返す
		if (playerHand == enemyHand) {
			//勝ち
			result == -1;
		}
		else if (enemyHand == 2) {
			result = 1;
		}
		//負けたら-1を返す
		if (playerHand == enemyHand) {
			//負け
			result == 1;
		}
		else if (enemyHand == 2) {
			result = -1;
		}
	}
		//ここに来た地点で相子はあり得ない
		//勝ちか負けしかありえない

		//勝ちのパターンをチェックする
		if ((playerHand == 0) && (enemyHand == 1)) {
			return 1;
		}
		if ((playerHand == 1) && (enemyHand == 2)) {
			return 1;
		}
		if ((playerHand == 2) && (enemyHand == 0)) {
			return 1;
		}
		//ここに来た時点であいこと勝ちのパターンはすべて除外されている
		return -1;

}


int main(void)
{
	printf("return 0;まで来たら関数がわかる\n");
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
	int playerHand = 0;
	for (int i = 0; i < 3; i++)
	{
		printf("========================\n");
		scanf_s("%d", &a);								//入れた値を出力
		randNum = rand();								//rand()関数の戻り値をrandNumに代入する
		num = randNum % 3;
		printf("%dを入力したよ", a);						//入れた値がなんなのかを表示させる
		if (a == 0) {									//入れた値がなんなのかを求める
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

		//int getBattleResult(int playerHand.int enemyHand)
		//を使用して勝敗判定を行う
		int result = getBattleResult(playerHand, enemyHand);

		if (result == 0) {
			//あいこ
			printf("あいこで...\n");
			continue;
		}
		else if (result == 1) {
			//勝ち
			dispWin();//関数を呼び出す
			winCount++
		}
		else {
			//負け
			dispLose();//関数を呼び出す
			loseCount++
		}
		/*
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
		*/
	}
	
	if (winCount > 1) {									//勝者を決める
		printf("勝った回数　%d 負けた回数　%d\n", winCount, loseCount);
		printf("勝者　プレイヤー！！\n");
		printf("コンピューター【え、負けちゃった。つぎは負けないからなまた挑戦しろよ！】\n");
	}
	else
	{
		printf("勝った回数　%d 負けた回数　%d\n", winCount, loseCount);
		printf("勝者　コンピューター\n");
		printf("コンピューター【残念、僕の勝ちだね＾＾】");
	}
	

	return 0;
}


