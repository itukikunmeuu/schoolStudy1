#include <iostream>
#include "Class.h"
using namespace std;

namespace
{
	//一度に登場する敵の最大数
	constexpr int kEnemyMax = 8;
}

//ドラゴンクエスト先頭画面の実装を書き換える
int main()
{
	cout << "継承を活用する" << endl;

	//EnemyBaseにはどの敵でも入れることができるので
	//一度に登場する最大数準備しておけばOK
	EnemyBase* pEnemy[kEnemyMax];
	for (int i = 0; i < kEnemyMax; i++)
	{
		pEnemy[i] = nullptr;
	}

	//出てくるメモリの開放
	pEnemy[0] = new EnemySlime;
	pEnemy[1] = new EnemyDoraky;
	pEnemy[2] = new EnemyDoragon;

	for (int i = 0; i < kEnemyMax; i++)
	{
		//pEnemy[i] == nullptrの場合、以降の処理を行わずに次のループへ
		if (!pEnemy[i])continue;

		cout << pEnemy[i]->GetName() << "が現れた!" << endl;
	}

	//確保したメモリの開放
	for (int i = 0; i < kEnemyMax; i++)
	{
		if (pEnemy[i])
		{
			delete pEnemy[i];
			pEnemy[i] = nullptr;
		}
	}
}



/*
//継承を活用して↓のをもっとスマートに書く
int main()
{
	cout << "継承を活用する" << endl;

	//EnemySlime型のポインタにはEnemySlimeを、
	//EnemyDraky型のポインタにはEnemyDrakyを入れていた（他も同様）
	//ポインタの型とその指し示す先のデータ型は一致していないといけない

	//※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※
	//継承を行ってクラスを作成した場合、
	//基底クラスのポインタに継承先のポインタを格納することがd系る
	//※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※
//	EnemyBase* pEnemy = new EnemyBase; //今まで：ポインタと実際に確保するデータ型一致
	EnemyBase* pEnemy = new EnemySlime; //基底クラスのポインタにその継承先のポインタを格納

//	EnemyBase* pEnemy = new EnemyDoraky; 
//	EnemyBase* pEnemy = new EnemyDoragon;

	delete pEnemy;
	pEnemy = nullptr;

	return 0;
}
*/

/*
//ドラゴンクエストに先頭画面をどう実装する？
//継承を活用しないとこんな感じに
int main()
{
	cout << "継承を使用する" << endl;

	EnemySlime* pSlime[8];
	EnemyDoraky* pDoraky[8];
	EnemyDoragon* pDoragon[3];
	//モンスターの数が増えると
	//メモリの確保は現れたモンスターの分のみすればよいが
	//ポインターはモンスターの種類*一度に洗われる数準備しないといけない？

	//モンスターがそれぞれ一体ずつ現れる
	pSlime[0] = new EnemySlime;
	pDoraky[0] = new EnemyDoraky;
	pDoragon[0] = new EnemyDoragon;


	//全員GetName()しているんだからfor文で回したい
	cout << pSlime[0]->GetName() << "が現れた！" << endl;
	cout << pDoraky[0]->GetName() << "が現れた！" << endl;
	cout << pDoragon[0]->GetName() << "が現れた！" << endl;

	delete pSlime[0];
	delete pDoraky[0];
	delete pDoragon[0];

	return 0;
}
*/