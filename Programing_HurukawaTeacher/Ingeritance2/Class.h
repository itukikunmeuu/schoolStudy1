#pragma once
#include <iostream>

//�����X�^�[�̊��N���X
class EnemyBase
{
public:
	EnemyBase() {}
	virtual ~EnemyBase() { cout << "Base" << endl; }

	//�㏑��(override)�������֐��̓���
	//Virtual������

	//EnemyBase�Ƃ���Enemy�𐶐����邱�Ƃ͂Ȃ�
	//�Ȃ̂�GetName�i�j�͕K���㏑�����Ăق���
	//��΂ɏ㏑�����Ăق����֐��́u�������z�֐��v�ɂ���
	virtual const char* GetName() = 0;
//	virtual const char* GetName() { return "�ȂȂ�"; }

protected:
	int m_hp = 0; //����ȏ��������\
};

//�X���C��
class EnemySlime : public EnemyBase
{
public:
	EnemySlime() {}
	virtual ~EnemySlime() { cout << "Slime" << endl; }

	//�X���C�����p�����ăX���C���x�X�����u�\��������v
	//�̂ňꉞvirtual�ɂ��Ă���
	virtual const char* GetName() override{ return "�X���C��"; }
};

//�h���L�[
class EnemyDoraky : public EnemyBase
{
public:
	EnemyDoraky() {}
	virtual ~EnemyDoraky() {}
	virtual const char* GetName() override { return "�h���L�["; }
};

//�h���S��
class EnemyDoragon : public EnemyBase
{
public:
	EnemyDoragon() {}
	virtual ~EnemyDoragon() {}
	virtual const char* GetName() override { return "�h���S��"; }
};
