#include <DxLib.h>
#include "Game.h"
#include "SceneMain.h"
#include "Pad.h"

#include "Player.h"

namespace
{
	//�ړ����x
	constexpr float kSpeed = 3.0f;

	//�L�����N�^�[�̃T�C�Y
	constexpr int kGraphWidth = 32;
	constexpr int kGraphHeight = 32;

	//�����̃T�C�Y
	constexpr int kGraphHalfWidth = kGraphWidth / 2.0f;
	constexpr int kGraphHalfHeight = kGraphHeight / 2.0f;

	//�L�����N�^�[�A�j���[�V����
	constexpr int kUseFrame[] = { 0,1,2,1 };

	//�A�j���[�V����1�R�}�̃t���[����
	constexpr int kAnimeFrameNum = 12;

	constexpr int kAnimFrameCycle = _countof(kUseFrame) * kAnimeFrameNum;
									// _countof()�Ŕz��̃T�C�Y���擾�ł���
									// _countof(kUseFrame)
	//�_���[�W���o�t���[����
	constexpr int kDamageFrame = 60;

}

Player::Player(SceneMain* pMain) :
	m_pMain(pMain),
	m_handle(-1),
	m_pos(Game::kScreenWidth / 2,Game::kScreenHeight / 2),
	m_dir(kDirDown),
	m_walkAnimeFrame(kAnimeFrameNum),
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
	//�_���[�W���o�̐i�s
	m_damageFrame--;
	if (m_damageFrame < 0) m_damageFrame = 0;

	//�p�b�h�̏\���L�[���g�p���ăv���C���[���ړ�������
	int pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	bool isMove = false; //�ړ������ǂ���

	//�ړ��ʂ����悤�ɂ���
	Vec2 move{ 0.0f,0.0f }; //��������R���X�g���N�^��{} ()�ł��ł��邪{}�̂ق�������

	if (pad & PAD_INPUT_LEFT)
	{
		move.x--;
		///*m_dir = kDirLeft;*/
		isMove = true;
	}
	if (pad & PAD_INPUT_RIGHT)
	{
		move.x++;
		///*m_dir = kDirRight;*/
		isMove = true;
	}
		//���K��
		move.Normalize();
		//�����̕ύX
		move *= kSpeed;
		//���W�Ƀx�N�g���𑫂�
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

		//�����蔻��̍X�V
		m_colRect.SetCenter(m_pos.x, m_pos.y, kGraphWidth, kGraphHeight);

		//�U��,�ړ��֌W
		////if (isMove)
		////{
		////	//�������[�V����
		////	m_walkAnimeFrame++;
		////	if (kAnimFrameCycle <= m_walkAnimeFrame)m_walkAnimeFrame = 0;
		////}
		////else
		////{
		////	m_walkAnimeFrame = kAnimeFrameNum;
		////}

	

}

void Player::Draw() const
{
	//�_���[�W���o�@2�t���[�����o�ŕ\�����\���ؑ�
	//0�F�\�������
	//1�F�\�������
	//2�F��\��
	//3�F��\��
	//4�F�\��������@...
	//%�S���邱�Ƃ�01230123012301230123...�ɕϊ�����
	if (m_damageFrame % 4 >= 2) return;

	int animeEle = m_walkAnimeFrame / kAnimeFrameNum;

	int srcX = kGraphWidth * kUseFrame[animeEle];
	int srcY = kGraphHeight * m_dir;

	DrawRectRotaGraph(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y),
		srcX, srcY,
		kGraphWidth, kGraphHeight,
		1.0, 0.0,
		m_handle, true, false);
#ifdef  _DEBUG
	m_colRect.Draw(0x0000ff, false);
#endif //_DEBUG

}

void Player::OnDamage()
{
	//�_���[�W���o�x���͍ēx�H���Ȃ�
	if (0 < m_damageFrame)return;
	//���o�t���[������ݒ肷��
	m_damageFrame = kDamageFrame;
}
