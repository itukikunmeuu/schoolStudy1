#pragma once
#include <iostream>

//モンスターの基底クラス
class EnemyBase
{
public:
	EnemyBase() {}
	virtual ~EnemyBase() { cout << "Base" << endl; }

	//上書き(override)したい関数の頭に
	//Virtualをつける

	//EnemyBaseというEnemyを生成することはない
	//なのでGetName（）は必ず上書きしてほしい
	//絶対に上書きしてほしい関数は「純粋仮想関数」にする
	virtual const char* GetName() = 0;
//	virtual const char* GetName() { return "ななし"; }

protected:
	int m_hp = 0; //こんな初期化も可能
};

//スライム
class EnemySlime : public EnemyBase
{
public:
	EnemySlime() {}
	virtual ~EnemySlime() { cout << "Slime" << endl; }

	//スライムを継承してスライムベスを作る「可能性がある」
	//ので一応virtualにしておく
	virtual const char* GetName() override{ return "スライム"; }
};

//ドラキー
class EnemyDoraky : public EnemyBase
{
public:
	EnemyDoraky() {}
	virtual ~EnemyDoraky() {}
	virtual const char* GetName() override { return "ドラキー"; }
};

//ドラゴン
class EnemyDoragon : public EnemyBase
{
public:
	EnemyDoragon() {}
	virtual ~EnemyDoragon() {}
	virtual const char* GetName() override { return "ドラゴン"; }
};
