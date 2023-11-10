#include <DxLib.h>
#include <cassert>
#include "Pad.h"
#include "Rect.h"

#include "SceneMain.h"

#include "Player.h"
#include "Bg.h"

// �o�ꂷ��G
// #include "EnemyBase.h"
#include "EnemyLeft.h"
#include "EnemyRight.h"
#include "EnemyToPlayer.h"

// �o�ꂷ��V���b�g
#include "ShotMagicWand.h"

namespace
{
	// ��x�ɓo��ł���G�̍ő吔
	constexpr int kEnemyMax = 32;
	// ���t���[�������ɓG���o�ꂷ�邩
	constexpr int kEnemyInterval = 40;

	// ��x�ɓ���ł���e�̍ő吔
	constexpr int kShotMax = 256;
}

SceneMain::SceneMain() :
	m_enemyInterval(0)
{
	// �O���t�B�b�N�̃��[�h
	m_playerHandle = LoadGraph("data/image/player.png");
	assert(m_playerHandle != -1);
	m_enemyHandle = LoadGraph("data/image/enemy.png");
	assert(m_enemyHandle != -1);
	m_bgHandle = LoadGraph("data/image/bg.png");
	assert(m_bgHandle != -1);

	// �v���C���[�̃������m��
	m_pPlayer = new Player{this};
	m_pPlayer->SetHandle(m_playerHandle);

	// �w�i�̃������m��
	m_pBg = new Bg;
	m_pBg->SetHandle(m_bgHandle);

	// �G�̏���
	// m_pEnemy(vector)�������Ȃ���΃T�C�Y��0

	// resize�֐���kEnemyMax�����f�[�^��ۑ��ł���悤�ɂ���
	m_pEnemy.resize(kEnemyMax);

	// �����̓R���X�g���N�^�Ń��������m�ۂ���
	// �f�X�g���N�^�ŉ�����Ă�������
	// ����̓����_����EnemyLeft, EnemyRight, EnemyToPlayer���m�ۂ�����
	// �ǂꂩ������Ȃ��̂ł��炩���ߊm�ۂ��邱�Ƃ��ł��Ȃ��I
	// �����I�Ƀ��������m�ۂ��� Update()���ɕK�v�ɉ�����

	// ������Ԃł̓��������m�ۂ��Ă��Ȃ����Ƃ�������悤��
	// ���g�p��Ԃɂ��� nullptr�����Ă���
	// size()�Ō��ݎg�p�\�ȗv�f�����擾�\
	for (int i = 0; i < m_pEnemy.size(); i++)
	{
		m_pEnemy[i] = nullptr;
	}

	// �V���b�g�̃������m��
	m_pShot.resize(kShotMax);
	for (auto& shot : m_pShot)
	{
		shot = nullptr;
	}
}

SceneMain::~SceneMain()
{
	// ����������O���t�B�b�N�̍폜
	DeleteGraph(m_playerHandle);
	DeleteGraph(m_enemyHandle);
	DeleteGraph(m_bgHandle);

	// �v���C���[�̃��������
	delete m_pPlayer;
	m_pPlayer = nullptr;

	// �w�i�̃��������
	delete m_pBg;
	m_pBg = nullptr;

	// ���������m�ۂ���Ă���G��T���ĉ�����Ă���
	for (auto& enemy : m_pEnemy)
	{
		if (enemy != nullptr)
		{
			delete enemy;
			enemy = nullptr;	// ���g�p��Ԃƕ�����悤�ɂ��Ă���
		}
	}

	// �V���b�g�̃��������
	for (auto& shot : m_pShot)
	{
		if (!shot) continue;
		delete shot;
		shot = nullptr;
	}
}

void SceneMain::Init()
{
	assert(m_pPlayer);	// m_pPlayer == nullptr �̏ꍇ�~�܂�

	m_pPlayer->Init();

	m_pBg->Init();
}

void SceneMain::End()
{
}

void SceneMain::Update()
{
	m_pPlayer->Update();
	m_pBg->Update();

	Rect playerRect = m_pPlayer->GetColRect();

	for (auto& enemy : m_pEnemy)
	{
		if (enemy)	// nullptr�ł͂Ȃ��`�F�b�N : nullptr�łȂ�(�������������Ă���)�Ȃ瓮��
		{
			enemy->Update();

			// �g�p�ς݂̓G�L�����N�[���폜����K�v������
			if (!enemy->IsExist())
			{
				// ���������������
				delete enemy;
				enemy = nullptr;	// �g���Ă��Ȃ��ƕ�����悤��
			}
			// ���݂��Ă���G�ƃv���C���[�Ɠ����蔻��
			else if ( playerRect.IsCollsion(enemy->GetColRect()) )
			{
			//	// test
			//	printfDx("�������Ă���\n");
				m_pPlayer->OnDamage();
			}
		}
	}

	for (auto& shot : m_pShot)
	{
		if (!shot)	continue;

		shot->Update();

		if (!shot->IsExist())
		{
			delete shot;
			shot = nullptr;
		}
	}

	// �G�L�����N�^�[��o�ꂳ����
	// kEnemyInteval�t���[���o�߂��邲�ƂɃ����_���ɓG��o�ꂳ����
	m_enemyInterval++;
	if (kEnemyInterval <= m_enemyInterval)
	{
		m_enemyInterval = 0;

		switch (GetRand(2))
		{
		case 0:	// Letf
			CreateEnemyLeft();
			break;
		case 1:	// Right
			CreateEnemyRight();
			break;

			// ���e�N
		default:	assert(false); // break�Ȃ�
		case 2:	// ToPlayer
			CreateEnemyToPlayer();
			break;
		}
	}
}

void SceneMain::Draw() const
{
	m_pBg->Draw();
	m_pPlayer->Draw();
	for (const auto& enemy : m_pEnemy)
	{
		if (enemy)	// nullptr�ł͂Ȃ��`�F�b�N
		{
			enemy->Draw();
		}
	}

	for (const auto& shot : m_pShot)
	{
		if (!shot)	continue;
		shot->Draw();
	}

	// �f�o�b�N�\��
	DrawString(8, 8, "SceneMain", 0xffffff);

	Vec2 playerPos = m_pPlayer->GetPos();
	DrawFormatString(8, 24, 0xffffff, 
		"�v���C���[�̍��W(%.2f, %.2f)", playerPos.x, playerPos.y);
	int shotCount = 0;
	for (const auto& shot : m_pShot)
		if (shot) shotCount++;
	DrawFormatString(8, 40, 0xffffff, 
		"�e�̐� %d", shotCount);
}

Vec2 SceneMain::GetNearEnemyPos(Vec2 pos) const
{
	// �G�����Ȃ��ꍇ�͓K���ȍ��W��Ԃ�
	Vec2 result{ 0, 0 };
	// �ŏ��̓G�`�F�b�N�ς݃t���O
	bool isFirst = true;

	clsDx();
	// ��ԋ߂��G�L�����N�^�[�̍��W��result�ɓ����
	for (const auto& enemy : m_pEnemy)
	{
		// �g���Ă��Ȃ��G�̓`�F�b�N���Ȃ�
		if (!enemy) continue;
		// �͈͊O�̓G�̓`�F�b�N���Ȃ�
		if (!enemy->IsExist()) continue;

		// pos��enemy�̋������`�F�b�N����
		if (isFirst)
		{
			// 1�̖ڂ̓G
			result = enemy->GetPos();
			isFirst = false;
		}
		else
		{
			// 2�̖ڈȍ~�̓G
			// result�̒��ɂ͈�ԋ߂��G�̍��W�������Ă���

			// ��ԓG�Ȃ�����X�V
			if ((enemy->GetPos() - pos).SqLength() < (result - pos).SqLength())
			{
				result = enemy->GetPos();
			}
		}
	}

	// ���ׂĂ̓G�̃`�F�b�N���s�����̂ł�����1�ʂŊm��
	return result;
}

bool SceneMain::AddShot(ShotBase* pShot)
{
	// nullptr��n���ꂽ��~�܂�
	assert(pShot);

	for (auto& shot : m_pShot)
	{
		if (shot)	continue;
		shot = pShot;
		// �o�^������I��
		return true;
	}

	// �����ɗ����Ƃ�������m_pShot�Ƀ|�C���^��o�^�ł��Ȃ�����
	delete pShot;
	return false;
}

void SceneMain::CreateEnemyLeft()
{
	for (int i = 0; i < m_pEnemy.size(); i++)
	{
		if (!m_pEnemy[i])	// nullptr�ł���`�F�b�N
		{
			m_pEnemy[i] = new EnemyLeft;
			m_pEnemy[i]->Init();
			m_pEnemy[i]->SetHandle(m_enemyHandle);
			m_pEnemy[i]->Start();
			return;// ��̕��m�ۂł�����I��
		}
	}
}

void SceneMain::CreateEnemyRight()
{
	for (int i = 0; i < m_pEnemy.size(); i++)
	{
		if (!m_pEnemy[i])
		{
			m_pEnemy[i] = new EnemyRight;
			m_pEnemy[i]->Init();
			m_pEnemy[i]->SetHandle(m_enemyHandle);
			m_pEnemy[i]->Start();
			return;
		}
	}
}

void SceneMain::CreateEnemyToPlayer()
{
	for (int i = 0; i < m_pEnemy.size(); i++)
	{
		if (!m_pEnemy[i])
		{
			// Base�������Ȃ��Ǝ��̊֐����Ăт���
			EnemyToPlayer* pEnemy = new EnemyToPlayer;

			pEnemy->Init();
			pEnemy->SetHandle(m_enemyHandle);
			pEnemy->SetPlayer(m_pPlayer);	// pEnemy��EnemyToPlayer�Ȃ̂ŌĂׂ�
			pEnemy->Start();

			// pEnemy�͂���������̂�m_pEnemy�Ɋm�ۂ����A�h���X���R�s�[���Ă���
			m_pEnemy[i] = pEnemy;

			return;
		}
	}
}

