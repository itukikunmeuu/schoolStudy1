#include<stdio.h>

void DispPrintf(void) {
	for (int i = 0; i < 5; i++)
	{
		printf("関数が実行されました\n");
	}
	return;
}

int main(void)
{
	printf("プログラムが開始されました\n");
	DispPrintf();  //DispPrintf()関数を呼び出す
	printf("プログラムを終了します\n");
	return 0; //main()の終了

}
//前回の復習
/*
	//1から10までの数を、3の倍数だけ除いて足し算するプログラム
	//1+2+4+5+7+8+10]
	int answer = 0;
	for (int i = 0; i < 10; i++) {
		//3の倍数の時は足し算を行わずに次の繰り返し処理へ
		if (i % 3 == 0) {
			continue;
		}

		answer += (i + 1);
	}
	printf("答え　%d\n", answer);
	*/
//前回の復習
/*
	//プレイヤーのHP
	int playerHp = 50;
	//敵の攻撃力
	int enemyAttack = 3;
	//敵の攻撃回数
	int enemyAttackNum = 10;

	//敵の攻撃回数回ダメージを食らう
	for (int i = 0; i < enemyAttackNum; i++) {
		printf("%d回目の攻撃！\n", playerHp);

		//奇数回目の攻撃は受ける
		//偶数回目の攻撃は回避する
		//攻撃回数が奇数の時、iの値は偶数、逆もまた然り
		//iが奇数の時にcontinueする
		if (i % 2 == 1) {
			printf("回避した！¥n");
		    continue;
		}



		playerHp -= enemyAttack;
		printf("残りHP　%d\n", playerHp);
		if (playerHp <= 0) {
			printf("死んだ！\n");
			break; //breakで繰り返しを強制的にやめる
		}
	}

	while (1) {
		printf("無限ループ\n");
		if (1) {
			printf("無限ループ\n");
			break;
		}
	}
	*/
//前回の復習
/*
	//決まった回数繰り返す場合for使うことが多い
	for (
		int i = 0;		//for文の初期化処理
		i < 5;			//繰り返し条件
		i++				//継続処理　繰り返される中身が終わった後実行される
		)
	{
		//繰り返される中身
	}

	//きれいに書き直し
	int loopNum = 16;
	for (int i = 0; i < loopNum; i++) {
		printf("%d回目の繰り返し\n",i+1);
	}

	//何かしらの条件を満たすまで繰り返す場合whileを使うことが多い
	int playerHp = 50;
	//プレイヤーのHPが0以下になるまでダメージを繰り返し受ける
	while (playerHp > 0) { //繰り返す条件を各店に注意
		printf("残りHP　%d\n", playerHp);
		playerHp -= 7;
	}

	//do-while文
	do {
		playerHp -= 7;
		printf("do残りHP　%d\n", playerHp);
	} while (playerHp > 0);
	*/

//前回の復習
/*
	int num = 5;
	switch (num) {
	case 0:
		printf("numは0\n");
		break;
	case 1:
		printf("numは1\n");
		break;
	case 2:
		printf("numは2\n");
		break;
	case 3:
		printf("numは3\n");
		break;
	case 4:
		printf("numは4\n");
		break;
	default:
		printf("numはそれ以外\n");
		break;
	}
	*/

//前回の復習
/*
	int num = 3;
	if (num % 2 == 0) {
		printf("%dは偶数です\n", num);
	}
	else {
		printf("%dは奇数です\n", num);
	}

	//条件の書き方
	int hp = 100;
	if (hp == 100) { //hp と　100が全く同じ、を判定する
		printf("HPがピッタリ100\n");
	}
	int hp = 100;
	if (hp != 100) { //hp と　100が全く同じ、を判定する
		printf("HPが100ではない\n");
		//HP20以下ならピンチ
		if (hp <= 20) {//20よりも小さい場合は（hp < 20）
			printf("ピンチ\n");
		}
		if (hp >= 80) {//20よりも小さい場合は（hp < 20）
			printf("余裕\n");
		}

		//複数の条件を同時に判断する
		int mp = 50;
		//HPが50以上、MPが５０以上両方を満たす
		if (hp >= 50 && mp >= 50) {
			printf("HP,MP両方５０以上\n");
		}
		//HPが50以上、MPが50以上どちらかを満たす
		if (hp >= 50 || mp >= 50) {
			printf("HP,MPどちらか５０以上\n");
		}
		//HPが50以上、ではない
		if (!(hp >= 50)) {
			printf("HPが50以上ではない\n");
		}

		//if文のネスト
		//HPが50以上、MPが50以上両方を満たす　を書き換える
		if (hp >= 50) {
			if (mp >= 50) {
				printf("HP,MP両方50以上\n"); //
			}
		}




		//else　if 文
		if (hp >= 50) {
			printf("HPが50以上\n");
		}
		else if (hp >= 25) {
			printf("HPが25以上");
		}
		else if (hp >= 10) {
			printf("HPが10以上");
		}
		else if (hp >= 5) {
			printf("HPが5以上");
		}
		else {
			printf("HPが5未満\n");
		}

		*/

//前回の復習
/*
	//+;足し算
	//-;引き算
	//*;掛け算
	//／；割り算
	//printf("10+5 = %d\n",10+5);
	//変数に対しても演算できる
	int num = 10;
	int num2 = 7;
	printf("%d+5 = %d\n", num, num2, num + num2);
	printf("%d-5 = %d\n", num, num2,num - num2);
	printf("%d*5 = %d\n", num, num2,num * num2);
	printf("%d/5 = %d\n", num, num2,num / num2);
	//printfで文字の％を表示したい場合は％％とする
	printf("%d%%5 = %d\n", num, num2, num % num2);

	//複合代入演算子
	int hp = 10;
	//ダメージを受けたのでHPを減らしたい
	//hp = hp-7;
	hp -= 7; //こっちで書こう
	//回復したのでHPを増やしたい
	hp += 7;

	//1増やしたい、減らしたいの特殊な書き方
	hp++; //hp += 1;と同じ
	++hp; //hp ++と同じ

	hp--; //hp -= 1と同じ
	*/

//前回の復習
/*
	//printfを使用して文字列を表示
	//\nは改行を表す
	printf("hello world! \n こんにちは世界\m");
	printf("hello world! \n こんにちは世界\m");

	//変数は　型名　変数名;で宣言される
	int numInt = 10;				//int型　整数を使う
	float numFloat = 1.23f;			//float　小数を使う
									//1.23f　のfはfloatの少数であることを表す
									//1.23だけだとdoubleと認識される
	char numChar = 'B';				//char型　文字を一文字扱う
									//半角1文字　全角は不可

	//変数名は半角英数と'_'を使用して名前を付ける
	//int 1num = 10; //ng 変数名の先頭が数字
	//float num*float = 10.0; //ng 使えない記号がひっている

	// = で代入を行う
	int test = 10;
	printf("test = %d\n", test); //%dで整数を表示
	test = 50;
	printf("test = %d\n", test);
	//整数を表示したい %d
	//小数を表示したい %f
	//文字（一文字）を表示したい　%c
	printf("%d %f %c\n", numInt, numFloat, numChar);

	//代入する値は変数を指定できる
	test = numInt;
	printf("test = %d\n", test);
	test = numFloat; //int型にfloat型を代入
	printf("test = %d\n", test); //小数点以下がなくなる
	*/
