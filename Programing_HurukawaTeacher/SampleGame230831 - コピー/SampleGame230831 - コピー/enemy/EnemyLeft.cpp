#include <DxLib.h>

#include "EnemyLeft.h"

#include "Game.h"

namespace
{
	constexpr float kSpeed = 4.0f;

	constexpr int kGraphWidth = 32;
	constexpr int kGraphHeight = 64;

	constexpr float kGraphHalfWidth = kGraphWidth / 2.0f;
	constexpr float kGraphHalfHeight = kGraphHeight / 2.0f;
}

EnemyLeft::EnemyLeft() :
	EnemyBase(),	// �����I�ɌĂԏꍇ�̗�
	m_sinRate(0.0f)
{
	// ���N���X�̃R���X�g���N�^�𖾎��I�ɌĂ΂Ȃ��Ă������ŌĂ΂��
}

EnemyLeft::~EnemyLeft()
{
	// �f�X�g���N�^���Ă΂��@�͂��c
}

void EnemyLeft::Update()
{
	// ���݂��Ȃ��G�̏����͂��Ȃ�
	if (!m_isExist) return;

	m_besePos += m_vec;

	m_pos = m_besePos;
	m_sinRate += 0.1f;
	m_pos.y += sinf(m_sinRate) * 32;

	// �����蔻��̍X�V
	UpdateCollision();

	if (Game::kScreenWidth + kGraphHalfWidth < m_pos.x) m_isExist = false;
}

void EnemyLeft::Start()
{
	// ��ʒ����ɓG�L�����N�^�[��o�ꂳ����
	m_isExist = true;

	m_pos.x = static_cast<float>(0 - kGraphHalfWidth);
	m_pos.y = static_cast<float>(GetRand(Game::kScreenHeight - kGraphHeight) + kGraphHalfHeight);

	m_pos = m_besePos;

	m_vec.x = kSpeed;
	m_vec.y = 0.0f;
}
