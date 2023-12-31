#include<stdio.h>

int main(void)
{
	int a;
	int* ptA;
	a = 10;
	//ptA = XXX a; //ポインタに変数のアドレスを格納したい
	ptA = &a;
		//ポインタの場所にある変数の値を表示したい
		printf("ポインタptAに格納されている値は%dです\n",*ptA);
}

//ポインタ
/*
int main(void)
{
	int a;
	int* ptA; //ポインタ　（int型の）アドレスを格納するための変数

	a = 3;			//変数3を代入
	ptA = &a;		//ポインタに変数aのアドレスを代入する

	//どちらも変数aのアドレス（メモリ上の場所）が表示される
	printf("変数aのアドレスは%pです\n", &a);
	printf("ポインタptAの値は%pです\n", ptA);

	//ポインタからそこに格納されている値を取得したい
	printf("変数aの値は%dです\n", a);
	printf("ptAに格納されている値は%dです\n", *ptA);

	//& は変数からそのアドレスを取得するための演算子
	//* はアドレス（ポインタ）からその中身を取得するための演算子

	return 0;
}
*/
//ポインタ
/*
int main(void)
{
	char c = 'A';		//文字はchar型に格納する
	int i = 10;			//整数はint型に格納する
	float f = 1.23f;	//小数はfloat型に格納する

	//&i　アドレスは何に格納する？　ポインタに格納する
	int* ptA;
	//int * ptA;  //どちらでもOK　上のほうがメジャー
	float* ptB = &f;
	char* ptC = &c;

	printf("ポインタptAの値は%pです\n", ptA);

	int* ptD, ptE;

	return 0;
}*/
//復習
/*
void function(void)
{
	int a = 7;
	printf("functionの変数aの中身は%dです\n", a);
}

int main(void)
{
	int a;			//変数が宣言された時点でメモリ上に
					//int型のサイズ文データを保存する領域が確保される
					//int型は4byte（32bit）なのでそ文確保される
					//メモリ上のどこに確保されるかは不明（OS任せ）
	a = 10;			//確保したメモリに変数を保存する

	//aを参照するとき、aの内容をOSに問い合わせる必要がある
	//OSは変数の先頭の位置を覚えている
	//データ型がわかればそこから始まって何バイト分かその変数の内容かがわかる
	//データの先頭位置+データ型からその中身の詳細がわかる
	printf("変数aの中身は%dです\n", a);

	float b;
	b = 1.23f;

	printf("変数bの中身は%fです\n", b);

	//関数の呼び出し
	function();

	//配列
	//配列はどのようにメモリ確保されるのか？
	//
	//配列は必ずメモリ上に連続して配置される
	//おいて問題のない場所（ほかに確保されているメモリを破壊しない場所）
	//を選んで配置してくれる
	char c[5];
	printf("c[3]の中身は%dです\n", c[3]);

	//配列2
	char d[4] = { 0,0,0,0 };
//	int num = 5;
//	d[num] = 8; //d[5]に値を書き込もうとしている
//	num = -1;
//	d[num] = 4; //d[-1]に値を書き込もうとしている

	//DxLibでプログラムを作ったとき
	//グラフィックデータをメモリに読み込んだ（LoadGraph()）
	//これもメモリ上に置かれる

	//グラフィックデータのロードでメモリがいっぱいになった体

	//LoadGraphしたらDeleteGraphする！

	//配列3
	int e[8];	//メモリが確保できないので止まる


	//OSは各変数のメモリ上の開始位置を覚えている
	//開始位置+データ型でどこからどこまでが一つの変数データなのかがわかり
	printf("a = %d\n", a);
	
	//配列も配列の開始位置を覚えている
	//配列はメモリ上に必ず連続して配置されているので
	//配列の開始位置+データ型+要素番号
	//を使用して各データにアクセスできる

	//開始位置？
	//メモリから先頭から番号が振られている
	//※0からスタートではないが通し番号が振られている
	//
	//OSは開始位置を覚えている、と言いましたが、
	//メモリ上のアドレスを覚えている
	//
	//変数main：：aは0x0020から始まる、みたいな覚え方をしている



	return 0;
}*/