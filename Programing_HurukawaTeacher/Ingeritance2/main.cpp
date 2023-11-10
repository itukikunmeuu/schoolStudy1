#include <iostream>
#include "Class.h"
using namespace std;

namespace
{
	//��x�ɓo�ꂷ��G�̍ő吔
	constexpr int kEnemyMax = 8;
}

//�h���S���N�G�X�g�擪��ʂ̎���������������
int main()
{
	cout << "�p�������p����" << endl;

	//EnemyBase�ɂ͂ǂ̓G�ł�����邱�Ƃ��ł���̂�
	//��x�ɓo�ꂷ��ő吔�������Ă�����OK
	EnemyBase* pEnemy[kEnemyMax];
	for (int i = 0; i < kEnemyMax; i++)
	{
		pEnemy[i] = nullptr;
	}

	//�o�Ă��郁�����̊J��
	pEnemy[0] = new EnemySlime;
	pEnemy[1] = new EnemyDoraky;
	pEnemy[2] = new EnemyDoragon;

	for (int i = 0; i < kEnemyMax; i++)
	{
		//pEnemy[i] == nullptr�̏ꍇ�A�ȍ~�̏������s�킸�Ɏ��̃��[�v��
		if (!pEnemy[i])continue;

		cout << pEnemy[i]->GetName() << "�����ꂽ!" << endl;
	}

	//�m�ۂ����������̊J��
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
//�p�������p���ā��̂������ƃX�}�[�g�ɏ���
int main()
{
	cout << "�p�������p����" << endl;

	//EnemySlime�^�̃|�C���^�ɂ�EnemySlime���A
	//EnemyDraky�^�̃|�C���^�ɂ�EnemyDraky�����Ă����i�������l�j
	//�|�C���^�̌^�Ƃ��̎w��������̃f�[�^�^�͈�v���Ă��Ȃ��Ƃ����Ȃ�

	//������������������������������������������������������������
	//�p�����s���ăN���X���쐬�����ꍇ�A
	//���N���X�̃|�C���^�Ɍp����̃|�C���^���i�[���邱�Ƃ�d�n��
	//������������������������������������������������������������
//	EnemyBase* pEnemy = new EnemyBase; //���܂ŁF�|�C���^�Ǝ��ۂɊm�ۂ���f�[�^�^��v
	EnemyBase* pEnemy = new EnemySlime; //���N���X�̃|�C���^�ɂ��̌p����̃|�C���^���i�[

//	EnemyBase* pEnemy = new EnemyDoraky; 
//	EnemyBase* pEnemy = new EnemyDoragon;

	delete pEnemy;
	pEnemy = nullptr;

	return 0;
}
*/

/*
//�h���S���N�G�X�g�ɐ擪��ʂ��ǂ���������H
//�p�������p���Ȃ��Ƃ���Ȋ�����
int main()
{
	cout << "�p�����g�p����" << endl;

	EnemySlime* pSlime[8];
	EnemyDoraky* pDoraky[8];
	EnemyDoragon* pDoragon[3];
	//�����X�^�[�̐����������
	//�������̊m�ۂ͌��ꂽ�����X�^�[�̕��݂̂���΂悢��
	//�|�C���^�[�̓����X�^�[�̎��*��x�ɐ���鐔�������Ȃ��Ƃ����Ȃ��H

	//�����X�^�[�����ꂼ���̂������
	pSlime[0] = new EnemySlime;
	pDoraky[0] = new EnemyDoraky;
	pDoragon[0] = new EnemyDoragon;


	//�S��GetName()���Ă���񂾂���for���ŉ񂵂���
	cout << pSlime[0]->GetName() << "�����ꂽ�I" << endl;
	cout << pDoraky[0]->GetName() << "�����ꂽ�I" << endl;
	cout << pDoragon[0]->GetName() << "�����ꂽ�I" << endl;

	delete pSlime[0];
	delete pDoraky[0];
	delete pDoragon[0];

	return 0;
}
*/