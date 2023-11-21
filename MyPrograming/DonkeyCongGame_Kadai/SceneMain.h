#pragma once
#include "Vec2.h"
#include<Vector>
using namespace std;


	class Player;
	class Bg;
	class EnemyBase;

class SceneMain
{
public:
	SceneMain();
	virtual ~SceneMain();
	
	void Init();
	void End();

	void Update();
	void Draw() const;

	//����̍��W�����ԋ߂��ɂ���G�̍��W��Ԃ��֐�
	Vec2 GetNearEemyPos(Vec2 pos) const;
	//�M��ǉ�����֐�
	//�o�^�ł��Ȃ������ꍇ��false��Ԃ�
	//�o�^�ł��Ȃ������ꍇ�͓�����pShot�J������

private:
	//�G�L�����N�^�[�̐���
	void CreateEnemyLeft();
	void CreateEnemyRight();
	void CreateEnemyToPlayer();

private:
	//�O���t�B�b�N�̃n���h��
	int m_gameScreenHandle;
	
	int m_playerHandle;
	int m_enemyHandle;
	int m_bgHandle;

	//�v���C���[
	Player* m_pPlayer;
	//�w�i

	//�G

	//�M

	//��ʃ��C�v����
	int m_wipeFrame;

	//�G�̓o��Ԋu

	//��ʂ��h��鉉�o
	int m_shakeFrame;
	
};

