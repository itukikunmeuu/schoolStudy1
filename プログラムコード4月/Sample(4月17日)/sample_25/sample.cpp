#include<iostream>
using namespace std;

//引数なし
void printMsg(void)
{
	cout << "test" << endl;
}
//NG 戻り値が違うだけでの同盟関数は作成できない
//void printMsg(void)
//{
//	cout << "test2" << endl;
//}

//引数の値が違えば同じ関数名の関数を作成できる
//void printMsg(int score = 50) //ng 引数を省略した場合、引数なしと見分けがつかないのでNG
void printMsg(int num,int score = 50)
{
	cout  <<  "テストの点"  << score << endl;
}

void printMsg(int num)
{
	cout << "num:" << num << endl;
}

//C++では関数の引数にデフォルトの値を設定できる
struct Player
{
	int hp;
	int mp;
};

//仮引数の後に　＝　50のように省略した場合に設定される数値を指定できる
//これをデフォルト引数という
//デフォルト引数が設定されている場合、引数を省略することができる
//省略した場合、仮引数には設定した値が入る
void initPlayer(Player& player, int hp = 100, int mp = 50)
{
	player.hp = hp;
	player.mp = mp;
}

int main()
{

	printMsg();
	printMsg(10);
	printMsg(10,50);
	/*
	Player player;
	initPlayer(player,200,0);

	//キャラクター選択可能
	//100種類キャラクターがいる
	//1体は体力自慢　HP200、MP0
	//1体は魔法使い　HP50、MP100
	//それ以外の98体はHP100、MP50

	cout << "HP:" << player.hp << endl;
	cout << "HP:" << player.mp << endl;
	*/
	return 0;
}

