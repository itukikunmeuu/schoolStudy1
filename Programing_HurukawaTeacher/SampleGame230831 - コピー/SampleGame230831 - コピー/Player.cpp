#include <DxLib.h>
#include "Game.h"
#include "SceneMain.h"
#include "Pad.h"


#include "Player.h"

#include "ShotMagicWand.h"
#include "ShotBible.h"

namespace
{
	// �ړ����x
	constexpr float kSpeed = 3.0f;

	// �L�����N�^�[�̃T�C�Y
	constexpr int kGraphWidth = 32;
	constexpr int kGraphHeight = 32;
	// �����̃T�C�Y
	constexpr float kGraphHalfWidth = kGraphWidth / 2.0f;
	constexpr float kGraphHalfHeight = kGraphHeight / 2.0f;

	// �L�����N�^�[�̃A�j���[�V����
	constexpr int kUseFrame[] = { 0, 1, 2, 1 };
	// �A�j���[�V����1�R�}�̃t���[����
	constexpr int kAnimFrameNum = 12;
	// �A�j���[�V�����̂P�T�C�N���̃t���[����
	constexpr int kAnimFrameCycle = _countof(kUseFrame) * kAnimFrameNum;
									// _countof()�Ŕz��̃T�C�Y���擾�ł���
									// _countof(kUseFrame)

	// ���@�̏�̔��ˊԊu
	constexpr int kMagicWandFrame = 30;

	// �_���[�W���o�t���[����
	constexpr int kDamageFrame = 60;
}

Player::Player(SceneMain* pMain) :
	m_pMain(pMain),
	m_handle(-1),
	m_pos(Game::kScreenWidth / 2, Game::kScreenHeight / 2),
	m_dir(kDirDown),
	m_walkAnimFrame(kAnimFrameNum),
	m_magicWandFrame(0),
	m_damageFrame(0)
{
}

Player::~Player()
{
}

void Player::Init()
{
}

void Player::Update()
{
	// �_���[�W���o�̐i�s
	m_damageFrame--;
	if (m_damageFrame < 0) m_damageFrame = 0;

	// �p�b�h�̏\���L�[���g�p���ăv���C���[���ړ�������
	int pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	bool isMove = false;	// �ړ������ǂ���

	// �ړ��ʂ����悤�ɂ���
	Vec2 move{ 0.0f, 0.0f };	// ��������R���X�g���N�^��{}�@()�ł��ł��邪{}�̂ق����ǂ�

	if (pad & PAD_INPUT_UP)
	{
		move.y--;
		m_dir = kDirUp;
		isMove = true;
	}
	if (pad & PAD_INPUT_DOWN)
	{
		move.y++;
		m_dir = kDirDown;
		isMove = true;
	}
	if (pad & PAD_INPUT_LEFT)
	{
		move.x--;
		m_dir = kDirLeft;
		isMove = true;
	}
	if (pad & PAD_INPUT_RIGHT)
	{
		move.x++;
		m_dir = kDirRight;
		isMove = true;
	}

	// ���K��
	move.Normalize();
	// �����̕ύX
	move *= kSpeed;
	// ���W�Ƀx�N�g���𑫂�
	m_pos += move;

	// �c���̈ړ�����
	if (m_pos.y < kGraphHalfHeight)
		m_pos.y = kGraphHalfHeight;
	else if (Game::kScreenHeight - kGraphHalfHeight < m_pos.y)
		m_pos.y = Game::kScreenHeight - kGraphHalfHeight;
	// �����̈ړ�����
	if (m_pos.x < kGraphHalfWidth)
		m_pos.x = kGraphHalfWidth;
	else if (Game::kScreenWidth - kGraphHalfWidth < m_pos.x)
		m_pos.x = Game::kScreenWidth - kGraphHalfWidth;

	// �����蔻��̍X�V
	m_colRect.SetCenter(m_pos.x, m_pos.y, kGraphWidth, kGraphHeight);
	
	// �U���֌W
	m_magicWandFrame++;
	if (kMagicWandFrame <= m_magicWandFrame)
	{
		m_magicWandFrame = 0;
		// ���@�̏񐶐�
		ShotMagicWand* pShot = new ShotMagicWand;
		pShot->Init();
		pShot->SetMain(m_pMain);
		pShot->SetPlayer(this);
		pShot->Start(m_pos);
		//�ȍ~�X�V�⃁�����̊J����SceneMain�ɔC����
		m_pMain->AddShot(pShot);
	}
	//�����{�^������
	//�{�^�����������甭������悤�ɂ���
	if (Pad::IsTrigger(PAD_INPUT_1))
	{
		//�����������̊m��
		ShotBible* pShot = new ShotBible;

		pShot->Init();
		pShot->SetMain(m_pMain);
		pShot->SetPlayer(this);
		pShot->Start(m_pos);
		//�ȍ~�X�V�⃁�����̊J����SceneMain�ɔC����
		m_pMain->AddShot(pShot);
	}

	if (isMove)
	{
		// �����A�j���[�V����
		m_walkAnimFrame++;
		if (kAnimFrameCycle <= m_walkAnimFrame)	m_walkAnimFrame = 0;
	}
	else
	{
		if (kUseFrame[m_walkAnimFrame/kAnimFrameNum] != 1)
		{
			m_walkAnimFrame++;
		}
		else
		{
			m_walkAnimFrame = kAnimFrameNum;
		}
	}
}

void Player::Draw() const
{
	// �_���[�W���o 2�t���[���Ԋu�ŕ\����\���؂�ւ�
	// 0: �\�������
	// 1: �\�������
	// 2: ��\��
	// 3: ��\��
	// 4: �\�������	�c
	// % 4���邱�Ƃ�01230123012301230123�c�ɕϊ�����
	if (m_damageFrame % 4 >= 2) return;

	int animEle = m_walkAnimFrame / kAnimFrameNum;

	int srcX = kGraphWidth * kUseFrame[animEle];
	int srcY = kGraphHeight * m_dir;
	
	// DX���C�u�����ɂ̓��t�@�����X�y�[�W�ɏ�����Ă��Ȃ��֐����������݂���
	// Dxlib.h���m�F���Ă�����ۂ��֐���T�����茟�����Ă݂悤
	DrawRectRotaGraph(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y),
		srcX, srcY,
		kGraphWidth, kGraphHeight,
		1.0, 0.0,
		m_handle, true, false);

#ifdef _DEBUG
	m_colRect.Draw(0x0000ff, false);
#endif
}

void Player::OnDamage()
{
	// �_���[�W���o���͍ēx�H���Ȃ�
	if (0 < m_damageFrame) return;
	// ���o�t���[������ݒ肷��
	m_damageFrame = kDamageFrame;
}
