#include <DxLib.h>
#include <cassert>
#include "Game.h"

#include "ShotMagicWand.h"

#include "SceneMain.h"

namespace
{
	// �V���b�g�̑傫��
	constexpr float kWidth = 8.0f;
	constexpr float kHeight = 8.0f;

	constexpr float kHalfWidth = kWidth / 2.0f;
	constexpr float kHalfHeight = kHeight / 2.0f;

	// �e�̈ړ����x
	constexpr float kShotSpeed = 8.0f;

	// �o���Ă����ߋ��̈ʒu���̐�
	constexpr int kPosLogNum = 8;
	constexpr int kPosAlpha = 255 / kPosLogNum;	// �����Ă������(����)
}

ShotMagicWand::ShotMagicWand()
{
	m_posLog.resize(kPosLogNum);
}

ShotMagicWand::~ShotMagicWand()
{
}

void ShotMagicWand::Init()
{
}

void ShotMagicWand::Update()
{
	if (!m_isExist) return;

	// ���O�̕ۑ�����
	for (int i = m_posLog.size() - 1; i > 0; i--)
	{
		m_posLog[i] = m_posLog[i - 1];
	}
	m_posLog[0] = m_pos;

	m_pos += m_vec;
	// �����蔻��̍X�V
	m_colRect.SetCenter(m_pos.x, m_pos.y, kWidth, kHeight);


	// ��ʊO�ɏo������
	// �ߋ��̕\���ʒu���܂߂Ă��ׂĉ�ʊO�ɏo����I��
	bool isOut = false;
	if (m_pos.x < 0.0f - kHalfWidth)				isOut = true;
	if (Game::kScreenWidth + kHalfWidth < m_pos.x)	isOut = true;
	if (m_pos.y <= 0.0f - kHalfHeight)				isOut = true;
	if (Game::kScreenHeight + kHalfHeight < m_pos.y)isOut = true;
	// �`�F�b�N���̍��W����ʓ��Ȃ炱���ŏI��
	if (!isOut) return;

	// �ߋ����O����ʓ��ɂ��邩���`�F�b�N����
	for (const auto& posLog : m_posLog)
	{
		isOut = false;
		if (posLog.x < 0.0f - kHalfWidth)				isOut = true;
		if (Game::kScreenWidth + kHalfWidth < posLog.x)	isOut = true;
		if (posLog.y <= 0.0f - kHalfHeight)				isOut = true;
		if (Game::kScreenHeight + kHalfHeight < posLog.y)isOut = true;
		// �`�F�b�N���̍��W����ʓ��Ȃ炱���ŏI��
		if (!isOut) return;
	}

	m_isExist = false;
#if false
	if ((m_vec.x < 0.0f) &&
		(m_pos.x <= 0.0f - kHalfWidth))
	{
		m_isExist = false;
	}
	if ((0.0f < m_vec.x) &&
		(Game::kScreenWidth + kHalfWidth < m_pos.x))
	{
		m_isExist = false;
	}
	if ((m_vec.y < 0.0f) &&
		(m_pos.y <= 0.0f - kHalfHeight))
	{
		m_isExist = false;
	}
	if ((0.0f < m_vec.y) &&
		(Game::kScreenHeight + kHalfHeight < m_pos.y))
	{
		m_isExist = false;
	}
#endif
}

void ShotMagicWand::Draw()
{
	if (!m_isExist) return;
	SetDrawBlendMode(DX_BLENDMODE_ADD, 255);
	for (const auto& posLog : m_posLog)
	{
		for (int lineNum = 0; lineNum < 8; lineNum++)
		{
			int startX = static_cast<int>(m_pos.x);
			int startY = static_cast<int>(m_pos.y);
			int endX = static_cast<int>(posLog.x);
			int endY = static_cast<int>(posLog.y);

			// ��������͂���ĂȂ����e(�\�K���e)
			// �������悭���邽�߂̂���
			float angle = GetRand(359) / 360.f * DX_TWO_PI_F;
			float len = (GetRand(6) - 3) * 1.5f;

			startX += cosf(angle) * len;
			startY += sinf(angle) * len;
			endX += cosf(angle) * len;
			endY += sinf(angle) * len;

			DrawLine(startX, startY,
				endX, endY,
				0x010210, kWidth - lineNum);
		}
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

#ifdef _DEBUG
//	m_colRect.Draw(0x000000, false);
#endif
}

void ShotMagicWand::Start(Vec2 pos)
{
	assert(m_pMain);

	m_isExist = true;

	// �����ʒu�̐ݒ�
	m_pos = pos;

	// �ߋ����O�̏����������������_�ł͓����ʒu�ɂ��Ă��܂�
	// �c�����ςȈʒu�ɕ\������Ȃ�����
	for (auto& posLog : m_posLog)
		posLog = pos;

	// �������@�E�����Ɉړ�������
	//m_vec.x = kShotSpeed;
	//m_vec.y = 0.0f;
	m_vec = m_pMain->GetNearEnemyPos(m_pos) - m_pos;
	m_vec.Normalize();
	m_vec *= kShotSpeed;
}
