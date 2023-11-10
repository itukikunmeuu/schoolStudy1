#include<iostream>
using namespace std;

//西暦を昭和に変換する関数
//昭和ではない年が指定された場合0にする
void WestenToSyouwa(int& x)
{
	if (x >= 1926 && x <= 1989) //1926年～1989が昭和
	{
		x -= 1925;
	}
	else
	{
		x = 0;
	}
}


void Syouwa()
{
	int year;

	cout << "西暦を入力してください > " << flush;
	cin >> year;  //キーボードから数値を入力する

//	cout << "入力" << year << endl;
	WestenToSyouwa(year);
	if (year != 0)
	{
		cout << "その年は昭和" << year <<"年です" << endl;
	}
	else
	{
		cout << "その年は昭和ではありません。" << endl;
	}

		
}

int main()
{
	Syouwa();
	Syouwa();

	return 0;
}
