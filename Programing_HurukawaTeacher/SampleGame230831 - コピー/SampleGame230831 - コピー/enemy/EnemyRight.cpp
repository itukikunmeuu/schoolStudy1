#include <DxLib.h>

#include "EnemyRight.h"

#include "Game.h"

namespace
{
	constexpr float kSpeed = 4.0f;

	constexpr int kGraphWidth = 32;
	constexpr int kGraphHeight = 32;

	constexpr float kGraphHalfWidth = kGraphWidth / 2.0f;
	constexpr float kGraphHalfHeight = kGraphHeight / 2.0f;
}

EnemyRight::EnemyRight()
{
}

EnemyRight::~EnemyRight()
{
}

void EnemyRight::Update()
{
	// ���݂��Ȃ��G�͏������Ȃ�
	if (!m_isExist) return;

	m_pos += m_vec;
	// �����蔻��̍X�V
	UpdateCollision();

	// �x�N�g�����������Ă݂�
	// ��ʒ����𒴂�����������Ă���
	if (m_pos.x < Game::kScreenWidth / 2)
	{
		// �ړ��x�N�g����ω������鎖�ő��x���グ��
		// ���Ɉړ�����ʂ�傫�����邱�Ƃő��������Ă���悤�Ɍ�����
		m_vec.x -= 0.5f;
	}

	// ��ʊO�ɏo���瑶�݂�����
	if (m_pos.x < 0.0f - kGraphHalfWidth)
	{
		m_isExist = false;
	}
}

void EnemyRight::Start()
{
	m_isExist = true;

	m_pos.x = static_cast<float>(Game::kScreenWidth + kGraphHalfWidth);
	m_pos.y = static_cast<float>(GetRand(Game::kScreenHeight - kGraphHeight) + kGraphHalfHeight);

	// 1�t���[��������̈ړ��x�N�g�������肷��
	m_vec.x = -kSpeed;
}