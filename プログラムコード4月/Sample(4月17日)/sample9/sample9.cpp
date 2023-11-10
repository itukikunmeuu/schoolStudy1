#include<stdio.h>

//2つの値ｘ,ｙ(int 以下すべてそう)を渡してその合計を返す関数
//int add()

//2つの値x,yを渡してその差を返す関数(単純な引き算でOK)
//int sub()

//2つの値x,yを渡してその乗算結果を返す関数
//int mul()

//2つの値x,yを渡してxのy条を返す関数
//int pow()

int add(int x, int y)
{
	int z = x + y;
	return z;
}
int sub(int x, int y)
{
	int z = x - y;
	return z;
}
int mul(int x, int y)
{
	int z = x * y;
	return z;
}
int pow(int x, int y)
{
	int z = x / y;
	return z;
}


//戻り値の練習
int main(void)
{
	int x = 4;
	int y = 3;

	int result = add(x,y);
	printf("add = %d\n", result);

	result = sub(x,y);
	printf("sub = %d\n", result);

	result = mul(x,y);
	printf("mul = %d\n", result);

	result = pow(x,y);
	printf("pow = %d\n", result);

	return 0;
}

//戻り値
/*
int goukei(int x, int y) {
	return (x+y);
}

//戻り値の勉強
int main(void)
{
	int a = goukei(1, 3);
	printf("合計は%dです\n",a);
	return 0;
}
*/

//比較関数
/*
//2つの値のうち、どちらが大きいかを比較する関数
void bigger(int x, int y)
{
	printf("z = %f\n", z);
	printf("2つの引数のうち、大きいほうを表示する\n");
	if (x > y) {
		printf("%dのほうが大きいです\n", x);
	}
	else
	{
		printf("%dのほうが大きいです\n", y);
	}
	return;
}

int main(void)
{
	bigger(1, 5);
	return 0;
}

*/

//関数の復習
/*
//関数化する基準
// 1.同じ処理が書かれている場所が複数ある場合
//例.ゲームの場合ダメージ処理など
//　ダメージ処理->HPを減らして、画面を揺らして、プレイヤーが赤く点滅する
//　同じ処理を今後書きそうだな、と思ったら関数化

// 2.パット見て何をやっているかわからない処理
//   ソースを見てもわからない処理に分かりやすい処理をつける
//　float angle = acos(cross(dir,toEnemy));
//  printf("angle = %f\n",angle);
//  ↓
//void calcAngle(void) //関数名を見たら角度を計算する処理だな。とわかる
//{
//	float angle = acos(cross(dir, toEnemy));
//	printf("angle = %f\n", angle);
//	return;
//}


void dispWin(void)
{
	printf("勝ち！\n");
	return;
}

//引数ありのかんすう
//引数に応じた処理を行うことができる
void dispNumber(int num)
{
	printf("num = %d\n", num);
	return;
}


//関数の中で渡された値を変更する
void addNumber(int num)
{
	printf("num = %d\n", num);
	num += 10;
	printf("num+10 = %d\n", num);
	return;
}


//関数の中ではif,for,whileなど使える
//引数は普通の変数のように扱える
void forFonction(int num)
{
	for (int i = 0; i < num; i++);
	printf("test\n");
}



//関数の復習
int main(void)
{
//	dispWin();
	int inputNum = 0;
	scanf_s("%d", &inputNum);
//	dispNumber(inputNum);
//	addNumber(inputNum);
//	printf("inputNum = %d\n", inputNum);
	forFonction(inputNum);


	return 0;
}
*/