#include<iostream>
using namespace std;

//じゃんけんでプレイヤーがっているか判定する
//勝っていたらtrue　勝っていない(負け、引き分け)false
//bool型を返す関数の関数名　isXXXX
//isから始まるbool型(true ot false)を返すと関数名を見るだけでわかる
bool isWin(int player, int enemy)
{
	if (true)  //必ず勝つ
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
//	cout << "やあ、こんにちは" << endl;

	cout << "2.3 + 2.5 =" << 2.3f + 2.5f << endl;

	//int,float,char

	//bool型:trueかfalseのどちらかが入る
	//変数名もbool型の場合、頭にisを付けることが多い
	//ポインタの場合pXXXXとつけたように
	//isもこの変数がbool型だとわかるようにisを付ける
	bool isFlag;
	isFlag = true;   //flagにtrue(真)を代入
	isFlag = false;  //flagにtrue(偽)を代入

	if (isFlag)
	{
		//flag =truen の場合の処理
	}
	else
	{
		//flag = falseの場合の処理
	}

	return 0;
}

