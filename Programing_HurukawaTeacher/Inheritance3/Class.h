#pragma once
#include <iostream>
using namespace std;

//継承元となるクラス　基底クラス
//基底クラスのクラス名は～～Baseのような名前を付けられることが多い
class EnemyBase
{
public:
	EnemyBase() :
		m_hp(0)
	{}
	//デストラクタにはVirtualをつける
	virtual ~EnemyBase(){}

	//virtualをつけることで仮想関数にする
	//継承先に同じ名前、同じ引数の関数がある場合
	//その関数で上書きされる
	virtual void Attack() = 0; //=0で純粋仮想
								//継承して
	void DispHp()
	{
		cout << "HP:" << m_hp << endl;
	}

private:
	int m_hp;

};

//EnemyBaseを継承して敵のクラスを作っていく
class EnemySlime
{
public:
	EnemySlime(){}
	virtual ~EnemySlime(){}

	void Attack()
	{
		cout << "体当たり" << endl;
	}

	//DispHpはすべてのモンスターできょうるうの処理なので
	//EnemyBaseに任せる(同じ関数を何度も書かない)
};

//EnemySlimeを継承してEnemyMetalSlimeを作る
class EnemyMetalSlime : public EnemySlime
{
public:
	EnemyMetalSlime() {}
	virtual ~EnemyMetalSlime(){}

	void Attack()
	{
		cout << "メラ" << endl;
	}
};