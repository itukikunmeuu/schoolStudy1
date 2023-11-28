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
	m_bgHandle = LoadGraph("data/Bg_.png");
	assert(m_bgHandle != -1);

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
	DeleteGraph(m_gameScreenHandle);

	//�������폜
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


	////��ʗh��̃t���[���J�E���g�_�E��
	//m_wipeFrame--;
}

void SceneMain::Draw() const
{

	//�`���X�N���[�����N���A����
	///ClearDrawScreen();

	m_pPlayer->Draw();

	//�f�o�b�N�\��
	DrawString(8, 8, "SceneMain", 0xffffff);

	Vec2 PlayerPos = m_pPlayer->GetPos();
	DrawFormatString(8, 24, 0xffffff,
		"�v���C���[�̍��W(%.2f,%.2f)", PlayerPos.x, PlayerPos.y);
	
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
