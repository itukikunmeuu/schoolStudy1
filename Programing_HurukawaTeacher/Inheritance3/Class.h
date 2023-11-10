#pragma once
#include <iostream>
using namespace std;

//�p�����ƂȂ�N���X�@���N���X
//���N���X�̃N���X���́`�`Base�̂悤�Ȗ��O��t�����邱�Ƃ�����
class EnemyBase
{
public:
	EnemyBase() :
		m_hp(0)
	{}
	//�f�X�g���N�^�ɂ�Virtual������
	virtual ~EnemyBase(){}

	//virtual�����邱�Ƃŉ��z�֐��ɂ���
	//�p����ɓ������O�A���������̊֐�������ꍇ
	//���̊֐��ŏ㏑�������
	virtual void Attack() = 0; //=0�ŏ������z
								//�p������
	void DispHp()
	{
		cout << "HP:" << m_hp << endl;
	}

private:
	int m_hp;

};

//EnemyBase���p�����ēG�̃N���X������Ă���
class EnemySlime
{
public:
	EnemySlime(){}
	virtual ~EnemySlime(){}

	void Attack()
	{
		cout << "�̓�����" << endl;
	}

	//DispHp�͂��ׂẴ����X�^�[�ł��傤�邤�̏����Ȃ̂�
	//EnemyBase�ɔC����(�����֐������x�������Ȃ�)
};

//EnemySlime���p������EnemyMetalSlime�����
class EnemyMetalSlime : public EnemySlime
{
public:
	EnemyMetalSlime() {}
	virtual ~EnemyMetalSlime(){}

	void Attack()
	{
		cout << "����" << endl;
	}
};