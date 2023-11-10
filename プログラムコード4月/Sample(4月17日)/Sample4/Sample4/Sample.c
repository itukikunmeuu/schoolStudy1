#include<stdio.h>

int main(void)
{
	//falseは　0
	//trueは　0以外
	if (4)
	{
		printf("実行される\n");
	}
	int keyNum = 0;
	if (keyNum)
	{
		printf("鍵持っている %d\n", keyNum);
	}
	else
	{
		printf("鍵持ってない\n");
	}

	int num = 0;
	int num2 = 1;

	//falseは0
	//trueは1
	printf("(num == 1)の中身を表示%d\n", num == 1);  //false
	printf("(num == 0)の中身を表示%d\n", num == 0);  //true

	printf("%d\n", num == 0 && num2 == 1); //true
	printf("%d\n", num == 0 || num2 == 0); //true

	printf("%d\n", num == 3 && num2 == 3); //false
	printf("%d\n", num == 3 || num2 == 3); //false

	//falseは0
	//trueは0以外

	int result = (num == 1);
	printf("result = %d\n", result);

	if (result)
	{
		printf("result = true\n");
	}
	else
	{
		printf("result : false\n");
	}


	return 0;
}

	/*int a = 7;
	int b = a % 3; //aを3で割ったあまり

	printf("変数aの値は%dです\n", a);

	switch (b) //次どこに行くのかを選択する関数（ifのように条件とはまた違うもの）
	{
	case 0:
		printf("変数aを3で割った余りは0です\n");
		break;
	case 1:
		printf("変数aを3で割ったあまりは1です\n");
		break;
	default:
		printf("変数aを3で割ったあまりは2です\n");
		break;
	}

	//if-elseを使って書き換え
	if (b == 0) {
		printf("変数aを3で割ったあまりは0です\n");
	}	
	if (b == 1) {
		printf("変数aを3で割ったあまりは1です\n");
	}	
	else {
		printf("変数aを3で割ったあまりは2です\n");
	}

	//条件文器いらないが？
	printf("変数aを3で割ったあまりは%dです\n",b);
	*/


/*鍵をいくつ持っているか
	int keyNum = 3;
	//プレイヤーのパワー
	int playerPower = 5600;

	//true(真)の場合、if()の次の1行が実行される
	//false(偽)の場合、if()の次の1行は実行されない
	// 
	//!= 指定された数以外　==指定された数のみ
	if (keyNum != 1) {
		//{}の中に好きなだけ処理をかける
		printf("扉1が開いた\n");
		keyNum--; //鍵を一つ減らす
		printf("残りの鍵 : %d\n", keyNum);

	}
	else {
		printf("扉1が開かない\n");
	}


	//鍵があればカギを開けることができる　if(keyNum >= 1)
	//力ずづくで開けることができる　　　　if(playerPower >= 50)
	//どちらかの手段で扉を突破する　

	//インデントに気を付ける	必ず使えるようにならなければならない
//	if (1){
//		printf("aaa\n");
//		if (1)
//		{
//			printf("bbb\n");
//		}
//	}

	//|| : 論理和　or演算
	if (keyNum >= 1 || playerPower >= 50) {
		printf("扉2が開いた\n");
		//力ずくで開ける場合は鍵を消費しない
		if (playerPower >= 50) {
			printf("力ずくで開けた！\n");
		}
		else {
			keyNum--; //鍵を一つ減らす
			printf("残りのカギ : %d\n", keyNum);
		}
	}
	else {
		printf("扉2が開かない\n");
	}

	//鍵があれば鍵を開けることができる　　　if(keyNum >= 1)
	//力がないと門番が認めてくれない　　　　if(playerPower >= 50)
	//鍵を持っていて力がないと扉を開けない　
	//両方の条件を満たす必要がある　　　　　

	// && : 論理積　and演算
//	if (keyNum >= 1 && playerPower >= 50)
//		printf("扉3が開いた\n");
//	else
//		printf("扉3が開かない\n");

	//else if を使用して条件分岐を書く
	if (keyNum <= 0) {
		printf("扉3を開けるカギを持っていない\n");
	}
	else if (playerPower < 50) {
		printf("扉3の門番が力を認めてくれない\n");
	}
	else {
	printf("扉3が開いた");
}*/




	/*
	int numInt = 10;
	
	float numFloat = 1.234f;
	//double numDouble = 12.35;  //別の書き方だが処理が遅くなるからおすすめはしない

	numInt = (int)numFloat; //わかっててfloatのデータをintに突っ込んでいる

	printf("numInt = %d\n", numInt); //小数点以下はなくなっている

	//ポケモンゲット率を計算する

	//何パーセントか、を表示する場合もふつう内部では割合で管理される
	//百分率　　割合
	//100％     1.0
	//50.12%    0.5012
	//12.25%    0.12225
	float getRate = 0.0f;

	int getNum = 32;         //持っているポケモンの種類
	int pokemomTotal = 151;  //ポケモンの種類（全体）
	getRate = (float)getNum / (float)pokemomTotal;
	printf("getRate = %f\n", getRate);
	*/


/*int main(void)
{
	int testScore = 30;
	
	if (testScore == 100)
		printf("お小遣いがもらえる\n");
	else if (testScore >= 80)
		printf("褒められる\n");
	else if (testScore <= 40)
		printf("一週間外出禁止\n");
	else
		printf("なにもなし\n");  //上の三つの条件すべてを満たさない



	return 0;
	
}*/


	/*
	int a = 5;
	int b = a % 2;

	if (a % 2 == 0)
		printf("%dは偶数です\n", a);
	else
		printf("%d破棄数です\n", a);
		*/


	/*
	//鍵を持っている数
	int  keyNum = 0;
	//キャラクターのレベル
	int  level = 10;

	//鍵を1つ以上持っていたら開く
	if (keyNum >= 1)
		printf("開く\n");
	else
		printf("開かない\n");

	//%% ; 倫理積　and演算
	//鍵を一つ以上持っていて、プレイヤーのレベルが50以上なら開く
	//同時に条件を満たす必要がある
	//keyNum >= 1がtrue level >=50がともにtrueの場合trueになる
	if (keyNum >= 1 && level >= 50)
		printf("open\n");
	//printf("aの値は%dです\n",a);

	//|| ; 倫理和　or演算
	//鍵を一つ以上持ってたら開く
	//プレイヤーのレベルが50以上なら力ずくで開く
	//どちらかの条件を満たせばOK
	//kerNum >= 1がtrue level >=1のどちらかがtrueの場合trueになる
	if (keyNum >= 1 || level >= 50)
		printf("open\n");
	
	//! ; 論理否定　not演算
	//!条件　条件がtrueの場合false,条件がfalseの場合trueになる
	//「持っている鍵の数が0よりも少ない」がfalseの場合trueになる
	if (!(keyNum <= 0))
		printf("open\n");
		*/

	/*int a = -1;

	if (a != 0)//  if (条件文)
	     printf("aの値は負の数です\n");//文;

	printf("aの値は%dです\n", a);*/

int main20230424(void)
{
//	printf("文字列を表示するときは\nprintf()\n");

	//　ポケモンのコンプリート率を計算したい
	//　ポケモンの数は151種類
	
	//百分率　　割合
	// 100%     1.1
	// 50%      0.5
	// 25%      0.25

	//現在登録されているポケモンの数
	int pokeNum = 120;
	float rate = 0.0f;
	//コンプリート率の計算
	rate = (float)pokeNum / 151.0f;

	printf("コンプリート率 = %f %%\n", rate * 100.0f);

	

	/*
	//整数型（int）に小数を入れると小数点以下が消える
	float numFloat = 1.99999f;
	int numInt = (int)numFloat;
    printf("numInt = %d\n", numInt);

	//floatに整数の値を入れる
	numInt = 256;
	numFloat = (float)numInt;
	printf("numFlosat = %f\n", numFloat);

	//浮動小数点は誤差が発生する
	float floatTest = 0.0f;
	floatTest += 0.1f;
	floatTest += 0.1f;
	floatTest += 0.1f;
	floatTest += 0.1f;
	floatTest += 0.1f;
	floatTest += 0.1f;
	floatTest += 0.1f;
	floatTest += 0.1f;
	floatTest += 0.1f;
	floatTest += 0.1f;
	printf("floatTest = %f\n", floatTest);
	printf("floatTest = %1.16f\n", floatTest);
	*/

	/*
	int test = 10 + 10 * 3;
	printf("test = %d\n ", test);

	test = (10 + 10) * 3;
	printf("test = %d\n ", test);
	*/


	/*
	int hp = 100;

	hp = hp - 10;
  //(別)hp -= 10;  // hp = hp - 10と同じ

	hp--; //デクリメント演算子　変数の値を１減らしてその変数に代入
	hp++; //インクリメント演算子　変数の値を１減らしてその変数に代入

	++hp;
	--hp;

	hp = 10;
	hp++;
	int a = hp;
	printf("a = %d, hp = %d\n" , a, hp);

	hp = 10;
	++hp;
	int b = hp;
	printf("b = %d,hp = %d\n", b, hp);
	*/

	/*変数
	int numInt = 10;          //整数
	float numFloat = 1.234f; // 小数
	char numChar = 'z';      //文字

	numInt = 10 + 10; //加算
	numInt = 10 - 10; //減算
	numInt = 10 * 10; //乗算

	numInt = 10 / 10; //除算
	numInt = 10 % 10; //予算

	numInt = 53;

	printf("割り算 %d / 5 = %d あまり　%d\n",
		numInt, numInt / 5, numInt % 5);
*/


	/*printf("整数を表示するとき　%d\n", numInt);
	printf("小数を表示するとき　%f\n", numFloat);
	printf("１文字を表示するとき　%c\n", numChar);

	printf("文字　%c\t整数 %d\t小数 %f\n", 'y', 64, 3.14f);
	*/
	return 0;
}