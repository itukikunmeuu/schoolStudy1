#include<stdio.h> //printf(),scanf_s()のプロトタイプ宣言が書かれている
//#include<stdlib.h> //rand(),srand()のプロトタイプ宣言が書かれている

//敵の数を定数として定義
#define ENEMY_NUM 5


//配列、for文での配列の利用
//#defineマクロを使用したサイズについておさらい
int main(void)
{
	//敵複数体のHPをランダムに生成して表示する
	srand((unsigned int)time(NULL));

	//配列で複数体分のHP用変数を準備する
	int enemyHp[ENEMY_NUM];

	//ランダムにHPを設定する
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		//HPは50~100
		enemyHp[i] = rand();
		
	}

	//設定したHPを表示する
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		printf("%d体目:%d\n", i + 1, enemyHp[i]);
	}

	return 0;
}

/*
//defineマクロを使用する
//プリプロセッサ→コンパイルの前に文字列を置き換えてくれる
//...と今は覚えておこう
//defineマクロ　→文字列の置き換えルールを指定することができる
//指定した文字をさらに指定した文字に変換する

//書き方
//#define 置き換え元の文字列A 置き換え先の文字列B
//コンパイルする前にAをBに置き換えてくれる
#define ENEMY_NUM 10



//#define ENEMY_NUM 5
// ↑のマクロを定義した場合
// int playerHp = DEFAULT_HP; こう書いておくと...
// int playerHp = 50; コンパイル前にDEFAULT_HPを50に置き換えてくれる

//↑が厳密な#defineの意味だが 
// 実際に利用するときは
// 「定数」を定義するときによく利用する

//defineマクロの置き換え前の文字列は
//・すべて大文字
//・単語と単語の間を＿（アンダースコア）でつなぐ
//というルールになっているのが一般的


//for文と配列の組み合わせ
int main(void)
{

	//敵のHPデータを格納するための配列
	int enemyHp[ENEMY_NUM];

	printf("敵のHPの値を入力してください\n");
	for (int i = 0; i < 3; i++)
	{
		printf("%d体目の敵のHPはいくつですか?\n", i + 1);
		//キーボードから値を入力する
		fscanf_s("%d", &ENEMY_NUM[i]);

	}

	for(int i = 0; i < 3; i++)
	{
		printf("%d体目の敵のHPは%dです\n", i + 1, ENEMY_NUM[i]);
	}
	return 0;
}
*/

//配列の各要素を参照してprintfで表示する
//for文を利用して配列の中身を簡単に記述する
/*
int main(void)
{
	//配列を宣言して初期化して値を入れる
	int enemyHp[5] = { 100,200,300 };

//	printf("1番目の敵のHPは%dです\n", enemyHp[0]);
//	printf("2番目の敵のHPは%dです\n", enemyHp[1]);
//	printf("3番目の敵のHPは%dです\n", enemyHp[2]);
//	printf("4番目の敵のHPは%dです\n", enemyHp[3]);
//	printf("5番目の敵のHPは%dです\n", enemyHp[4]);

//	↓for文を用いた形に書き換える

	//5体分のHPを表示したいので5回繰り返し処理を行う
	for (int i = 0; i < 5; i++)
	{
		//iの値と終了条件に注目する
		//終了条件　i<5 5の部分配列の要素数と同じ
		// 
		//iの値
		//1週目: i = 0
		//2週目: i = 1
		//3週目: i = 2
		//4週目: i = 3
		//5週目: i = 4
		printf("%d番目の敵のHPは%dです\n", i + 1, enemyHp[i]);
	}
	for (int i = 1; i <= 5; i++)
	{
		//iの値					//配列の要素は0から始まるが？
		//1週目: i = 0
		//2週目: i = 1
		//3週目: i = 2
		//4週目: i = 3
		//5週目: i = 4			//配列の要素数が5の場合[5]が使えない
	}
//	for文の中で実際に何が行われているか詳しく見てみる
	{
		int i = 0; //文の初期化処理が行われる
	//	if(i < 5)を満たしていれば繰り返し処理を行う
		// i=0の状態で繰り返し処理が行われる
		printf("%d番目の敵のHPは%dです\n", i + 1, enemyHp[i]);

	//	繰り返し処理の後の処理を行う
		i++;	//	iは1+1なので2
//////////////////////////////////////////

	//...中略

	//繰り返し処理の後の処理を行う
		i++;    // iは4+1なので5
//////////////////////////////////////////
	//if(i<5)を満たしていれば繰り返し処理を行う
	//i=1の
	}

	//通常の変数（配列ではない変数）の場合
//	int playerHp = 999;
//	printf("プレイヤーのHPは%dです\n",playerHp);

	return 0;
}*/
//配列を宣言してそこに値を入れる
//配列の要素を指定して値を入れる
//初期化子を利用して初期化と同時に値を入れる
/*
int main(void)
{
	//敵キャラクター100体分のHPを管理したい
	//配列を使う
	//型名　配列名[要素数];
	int enemyHP[3] = {100,120,240};
//	enemyHP[0] = 100;
//	enemyHP[1] = 120;
//	enemyHP[2] = 240;

//  配列の宣言と同時に初期化を行う場合は要素数省略できる
//  省略した場合は初期化子の数分の要素が用意される
	int enemyMp[] = { 20,0,80 };
//  int enemyAttack[]; //要素数を指定していないのでエラー

//	左辺のほうが要素数が多い場合　左辺5に対して右辺3
//	配列の要素数と初期化子の数が違う場合の挙動
	int anemyAttack[5] = { 10,20,30 };

//	右辺のほうが要素数が多い場合　左辺2に対して右辺3
//	コンパイルエラー　ビルドが通らない
//	int enemySpeed[2] = {100,200,300}; //エラー

//	ng例　1つの配列に多くの種類のデータを入れない
//	下記例では、HP、攻撃力、防御力を1つの配列に入れている
	int enemyData[9];
	enemyData[0] = 100; //1体目の敵のHP
	enemyData[1] = 200; //2体目の敵のHP
	enemyData[2] = 300; //3体目の敵のHP

	enemyData[3] = 10; //1体目の敵の攻撃力
	enemyData[4] = 20; //2体目の敵の攻撃力
	enemyData[5] = 30; //3体目の敵の攻撃力

	enemyData[6] = 10; //1体目の敵の防御力
	enemyData[7] = 20; //2体目の敵の防御力
	enemyData[8] = 30; //3体目の敵の防御力

	enemyData[6];  //これはHP？攻撃力？防御力？　これだけ見てわからない




	//通常の変数
	int pleyerHp;
	pleyerHp = 3;

	return 0;
}*/

/*
void transSeconds(int sec)

void showAverage(int val1, int val2) //val : valueの略　値
{
	printf("1つ目の値は%dです。\n", val1);
	printf("2つ目の値は%dです。\n", val2);

	//整数で計算すると小数点以下が切り捨てられるので
	//小数で計算を行うため"キャスト"を行って計算する
	float trdult = (val1 + val2) / 2;
	printf("2つ目の値の平均値は%fです。\n", (val1 + val2) / 2);
}


int main(void)
{
	showAverage(10, 15);

	return 0;
}
*/
//練習問題1
/*
void transSeconds(int sec) {
	int aHor, aMin, aSec;

	//教科書通り、それぞれの計算を1行で書く
//	aHor = sec / (60 * 60); //時間を求める
//	aMin = (sec % (60 * 60)) / 60; //分を求める
//	aSec = sec % 60; //秒を求める

	int tempSec = sec;			//temp:temporaryの略　一時的にデータを保存しておく
	aHor = tempSec / (60 * 60); //時間の計算
	tempSec %= (60 * 60);       //時間の部分を取り除く
	aMin = tempSec / 60;		//分の計算
	tempSec %= 60;
	aSec = tempSec;             //秒（そのまま）

	printf("%d秒は、%d時間%d分%d秒です。\n", sec, aHor, aMin, aSec);

	return;
}

int main(void)
{
	int timeSec = 5000;

	transSeconds(timeSec); //引数として秒数を渡す（この例では5000秒）


	return 0;
}
*/
//スタティック関数
/*
void f(void)
{
	static int num = 0;
	num++;
	printf("f関数が呼ばれたのは%d回目です\n", num);
}

int main(void)
{
	f();
	f();
	f();
	return 0;
}*/
//変数numの値に足し算したい
/*
int add(int baseNum , int addNum)
{
	return  (baseNum + addNum);
}

int main(void)
{
	int num = 0;

	printf("num = %d\n", num);

	num = add(num, 5);

	printf("num = %d\n", num);

	return 0;
}*/
//グローバル変数2
/*
int a = 16;

void f(void)
{
//	int a = 1;
	printf("関数fの中の変数aの値は%dです\n", a);
	return;
}

int main(void)
{
	int a = 2;
	printf("main関数fの中の変数aの値は%dです\n", a);
	f();
	return 0;
}
*/
//グローバル変数1
/*
int a; //グローバル変数

void f(void)
{
	int b; //ローカル変数

//	printf("関数fの中でaの値は%dです\n", a);
	printf("関数fの中でbの値は%dです\n", b);

}


int main(void)
{
//	int c; //ローカル変数
//	printf("main関数の中でaの値は%dです\n", a);
	printf("main関数の中でbの値は%dです\n", b);
	f();

	for (int i = 0; i < 5; i++)
	{
		printf("i = %d\n", i);
	}

	return 0;
}
*/