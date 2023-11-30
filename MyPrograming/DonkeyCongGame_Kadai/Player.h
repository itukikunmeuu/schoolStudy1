#pragma once
#include "Vec2.h"
#include "Rect.h"

class SceneMain;

class Player
{
public:
	//�����Ă������
	enum Dir
	{
		kDirDown,	//��
		kDirLeft,	//��
		kDirRight,	//�E
		kDirUp		//��
	};

public:
	Player(SceneMain* pMain);
	~Player();

	void Init();
	void Update();
	void Draw() const;

	//�����o�ϐ��ɃA�N�Z�X����
	void SetHandle(int handle) { m_handle = handle; }

	//�v���C���[�̌��݈ʒu���擾����
	Vec2 GetPos() const { return m_pos; }
	//�v���C���[�̓����蔻����擾����
	Rect GetColRect() { return m_colRect; }

	void OnDamage();

private:
	SceneMain* m_pMain;
	
	int m_handle; //�O���t�B�b�N�̃n���h��

	//�\���ʒu
	Vec2 m_pos;
	//�����蔻��p�̋�`
	Rect m_colRect;

	//�����Ă������
	Dir m_dir;
	//�����A�j���[�V����
	int m_walkAnimeFrame;
	
	//�_���[�W�󂯂Ă���̃t���[����
	//���i��0
	//�����������Ƀt���[������ݒ肵��
	//�ȍ~���t���[�����炵�Ă���
	int m_damageFrame;

	int JumpPower;
	bool JumpFlag = true;
	int Jump;
};

