#include <DxLib.h>
#include <cassert>

#include "EnemyToPlayer.h"
#include "Player.h"

#include "Game.h"

namespace
{
	constexpr float kSpeed = 4.0f;

	// �L�����N�^�[�̃T�C�Y
	constexpr int kGraphWidth = 32;
	constexpr int kGraphHeight = 32;

	constexpr float kGraphHalfWidth = kGraphWidth / 2.0f;
	constexpr float kGraphHalfHeight = kGraphHeight / 2.0f;
}

EnemyToPlayer::EnemyToPlayer() :
	m_pPlayer(nullptr)
{
	// m_pPlayer�ɂ�SceneMain�Ŋ��Ƀ��������m�ۂ���Player��
	// �ǂ��ɒu����Ă���̂��A�̏������Ă��������̂ł����ł̓������m�ۂ��Ȃ�
}

EnemyToPlayer::~EnemyToPlayer()
{
	// m_pPlayer�̊m�ۉ����SceneMain���Ǘ�����̂�
	// ���l�ɉ�����s��Ȃ�
}

void EnemyToPlayer::Update()
{
	// ���݂��Ȃ��G�͏������Ȃ�
	if (!m_isExist) return;

	m_pos += m_vec;
	// �����蔻��̍X�V
	UpdateCollision();

	// ��ʊO�ɏo���瑶�݂�����
	if ((m_vec.x < 0.0f) &&
		(m_pos.x <= 0.0f - kGraphHalfWidth))
	{
		m_isExist = false;
	}
	if ((0.0f < m_vec.x) &&
		(Game::kScreenWidth + kGraphHalfWidth < m_pos.x))
	{
		m_isExist = false;
	}
	if ((m_vec.y < 0.0f) &&
		(m_pos.y <= 0.0f - kGraphHalfHeight))
	{
		m_isExist = false;
	}
	if ((0.0f < m_vec.y) && 
		(Game::kScreenHeight + kGraphHalfHeight < m_pos.y))
	{
		m_isExist = false;
	}
}

void EnemyToPlayer::Start()
{
	m_isExist = true;
	
	// ��ʂ̏㉺���E�����ꂩ����o�ꂷ��
	switch (GetRand(3))
	{
	case 0:	// �ォ��
		m_pos.x = static_cast<float>(GetRand(Game::kScreenWidth - kGraphWidth) + kGraphHalfWidth);
		m_pos.y = static_cast<float>(0 - kGraphHalfHeight);
		break;
	case 1:	// ������
		m_pos.x = static_cast<float>(0 - kGraphHalfWidth);
		m_pos.y = static_cast<float>(GetRand(Game::kScreenHeight - kGraphHeight) + kGraphHalfHeight);
		break;
	case 2:	// ������
		m_pos.x = static_cast<float>(GetRand(Game::kScreenWidth - kGraphWidth) + kGraphHalfWidth);
		m_pos.y = static_cast<float>(Game::kScreenHeight + kGraphHalfHeight);
		break;
	case 3:	// �E����
		m_pos.x = static_cast<float>(Game::kScreenWidth + kGraphHalfWidth);
		m_pos.y = static_cast<float>(GetRand(Game::kScreenHeight - kGraphHeight) + kGraphHalfHeight);
		break;
	default:
		assert(false);
		break;
	}

	assert(m_pPlayer);
	// �G�̏����ʒu����^�[�Q�b�g�ʒu�Ɍ������x�N�g���𐶐�
	m_vec = m_pPlayer->GetPos() - m_pos;
	// ���K��(�x�N�g���̑傫�����o���o���Ȃ���)
	m_vec.Normalize();
	// �x�N�g���̒������X�s�[�h��
	m_vec *= kSpeed;
}