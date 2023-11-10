#include<iostream>
#include "Class.h"
using namespace std;

namespace
{
	constexpr int kEnemyNum = 8;
}

int main()
{
	cout << "�p���̕��K" << endl;

	///////////////////////////////////////////////////
	//���N���X�̃|�C���^��
	//�p����̃N���X�̃A�h���X�����邱�Ƃ��ł���
	//////////////////////////////////////////////////

	EnemyBase* pEnemy[kEnemyNum];

	for (int i = 0; i < kEnemyNum; i++)
	{
		if (rand() % 2)
		{
			pEnemy[i] = new EnemySlime;
		}
		else
		{
			pEnemy[i] = new EnemyMetalSlime;
		}
	}

	//�ǂ̓G�������Ă��悤��Attack�݂̂�ok
	for (int i = 0; i < kEnemyNum; i++)
	{
		pEnemy[i]->Attack();
	}

	//Slime,MetalSlime�̂ǂ��炪�����Ă��Ă�
	//delete�݂̂�OK
	for (int i = 0; i < kEnemyNum; i++)
	{
		delete pEnemy[i];
	}

//	pEnemy->Attack();
//	pEnemy->DispHp();

//	delete pEnemy;

	return 0;
}