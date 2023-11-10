#include<iostream>
#include<cmath> //数学関数

//include<stdio.h>
//include<stdlib.h>
//↓C++で上に含まれる関数を使いたい！
//#include<cstdio>
//#include<cstdlib>

//<cmath>
//↓　ｃで上に含まれる関数を使いたい！
//<math.h>

using namespace std;

int main()
{
	//直角三角形の斜辺の長さを求めるプログラム
	double a, b;  //底辺と高さ

	cout << "直角を挟む2辺の長さを入力してください　>" << flush;
	cin >> a >> b;

	//斜辺の長さを計算する
	double result = (a * a + b * b); //sqrt(x) でｘの平方根を求める
	cout << "斜辺の長さは" << result << "です。" << endl;

	//abs(x)  　:x
	//floor(x)　:
	//cell(x)   :
	//fmod(x,y) :x
	//sqrt(x)   :x
	//...等　   :


	return 0;
}