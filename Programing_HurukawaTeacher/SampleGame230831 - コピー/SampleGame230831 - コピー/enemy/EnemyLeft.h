#pragma once

#include "EnemyBase.h"

// �쐬����N���X�� : public �p����(���N���X)
// public�ȊO�ɂ�private, protected���g�p�ł��邪���public
class EnemyLeft : public EnemyBase
{
public:
	EnemyLeft();
	virtual ~EnemyLeft();

	virtual void Update() override;

	virtual void Start() override;

private:
	//����W
	//y������sin�̒l�𑫂��ď㉺�ɓ����悤�ɂ���
	Vec2 m_besePos;

	//sin()�ɗ^�������
	float m_sinRate;
};