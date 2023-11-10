#include <DxLib.h>
#include <cassert>

#include "EnemyBase.h"

#include "Game.h"

namespace
{
	constexpr int kGraphWidth = 32;
	constexpr int kGraphHeight = 32;
}

EnemyBase::EnemyBase() :
	m_handle(-1),
	m_isExist(false)
	// m_pos�͈����Ȃ��̃R���X�g���N�^���Ă΂��
	// �����Ȃ��̃R���X�g���N�^���Ăԏꍇ�͏ȗ��ł���
{
}

EnemyBase::~EnemyBase()
{
}

void EnemyBase::Init()
{
}

void EnemyBase::Update()
{
	// ���݂��Ȃ��G�͏������Ȃ�
	if (!m_isExist) return;
}

void EnemyBase::Draw() const
{
	// ���݂��Ȃ��G�͕`�悵�Ȃ�
	if (!m_isExist) return;
	// �O���t�B�b�N���ݒ肳��Ă��Ȃ���Ύ~�܂�
	assert(m_handle >= 0);
	// ���S�ʒu����Ƃ��ĕ`�悷��
	DrawRotaGraph(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y),
		1.0, 0.0,
		m_handle, false, false);

#ifdef _DEBUG
	m_colRect.Draw(0xff0000, false);
#endif
}

void EnemyBase::UpdateCollision()
{
	//m_colRect.SetLT(m_pos.x - kGraphWidth / 2, m_pos.y - kGraphHeight / 2, kGraphWidth, kGraphHeight);
	m_colRect.SetCenter(m_pos.x, m_pos.y, kGraphWidth, kGraphHeight);
}
