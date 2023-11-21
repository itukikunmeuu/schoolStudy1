#include<DxLib.h>
#include<cassert>
#include "Pad.h"
#include "Rect.h"

#include "SceneMain.h"

#include "Player.h"

//�o�ꂷ��G


#include "Game.h"

namespace
{
	//��ʂ����C�v����̂ɂ�����t���[����
	constexpr int kWipeFrame = 30;
}

SceneMain::SceneMain():
	m_shakeFrame(0),
	m_wipeFrame(0)
{
	//�Q�[����ʕ`���̐���
	//��ʃT�C�Y�Ɠ����傫���̃O���t�B�b�N�f�[�^�𐶐�����
	m_gameScreenHandle = MakeScreen(Game::kScreenWidth, Game::kScreenHeight, true);

	//�O���t�B�b�N�̃��[�h
	m_playerHandle = LoadGraph("data/Player_.png");
	assert(m_playerHandle != -1);
	m_enemyHandle = LoadGraph("data/Enemy_.png");
	assert(m_enemyHandle != -1);

	//�v���C���[�������̊m��
	m_pPlayer = new Player{ this };
	m_pPlayer->SetHandle(m_playerHandle);
	
	//�w�i�̃������̊m��

	//�G�̏���
	//m_pEnemy(vector�������Ȃ���΃T�C�Y��0)

	//resize�֐���kEnemyMax�����f�[�^��ۑ��ł���悤�ɂ���
	
}

SceneMain::~SceneMain()
{
	//MakeScreen�Ő��������O���t�B�b�N���폜����
	DeleteGraph(m_playerHandle);
	DeleteGraph(m_enemyHandle);
	DeleteGraph(m_bgHandle);

	//�v���C���[�̃������J��
	delete m_pPlayer;
	m_pPlayer = nullptr;
	

	//�w�i�̃������J��

	//���������m�ۂ���Ă���G��T���ĊJ�����Ă���
}

void SceneMain::Init()
{
	assert(m_pPlayer);//m_pPlayer == nullptr�̏ꍇ�Ƃ܂�

	m_pPlayer->Init();
}

void SceneMain::End()
{
}

void SceneMain::Update()
{
	m_pPlayer->Update();

	Rect playerRect = m_pPlayer->GetColRect();


	//��ʗh��̃t���[���J�E���g�_�E��
	m_wipeFrame--;
}

void SceneMain::Draw() const
{
	//�o�b�N�o�b�t�@�ɒ��ڏ������ނ̂ł͂Ȃ�
	//�����Ő��������O���t�B�b�N�f�[�^�ɑ΂��ď�������
	SetDrawScreen(m_gameScreenHandle);

	//�`���X�N���[�����N���A����
	ClearDrawScreen();

	//�f�o�b�N�\��
	DrawString(8, 8, "SceneMain", 0xffffff);

	Vec2 PlayerPos = m_pPlayer->GetPos();
	DrawFormatString(8, 24, 0xffffff,
		"�v���C���[�̍��W(%.2f,%.2f)", PlayerPos.x, PlayerPos.y);

	//�Q�[����ʂ��o�b�N�o�b�t�@�ɕ`�悷��
	int screenX = 0;
	int screenY = 0;
	if (m_shakeFrame > 0)
	{
		//��ʗh��
		screenX = GetRand(8) - 4;
		screenY = GetRand(8) - 4;
	}

	//���t���[�����Z�����kWipeFrame(30)�܂ŕω�����
	float wipeRate = static_cast<float>(m_wipeFrame) / static_cast<float>(kWipeFrame);
	int wopeHeight = Game::kScreenHeight * wipeRate;

	//��ʂ̏ォ��1���C�����`����s���Ă���
	for (int y = 0; y < Game::kScreenHeight; y++)
	{
		int x = y;
		DrawRectGraph(0, y,
			x, y, Game::kScreenWidth, 1,
			m_gameScreenHandle, true, false);
	}
	
}

Vec2 SceneMain::GetNearEemyPos(Vec2 pos) const
{
	//�G�����Ȃ��ꍇ�͓K���ȍ��W��Ԃ�
	Vec2 result{ 0,0 };
	//�ŏ��̓G�`�F�b�N�ς݃t���O
	bool isFirst = true;

	clsDx();
	//��ԋ߂��G�L�����N�^�[�̍��W��result�ɓ����
	///for(const auto& enemy : m_pEmemy)

	//���ׂĂ̓G�̃`�F�b�N���s�����̂ł�������ʂŊm��
	return result;
}

void SceneMain::CreateEnemyLeft()
{
}

void SceneMain::CreateEnemyRight()
{
}

void SceneMain::CreateEnemyToPlayer()
{
}
