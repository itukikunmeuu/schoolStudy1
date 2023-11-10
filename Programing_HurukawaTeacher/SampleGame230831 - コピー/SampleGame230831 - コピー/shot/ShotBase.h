#pragma once
#include "Vec2.h"
#include "Rect.h"

class SceneMain;
class Player;

/// <summary>
/// �v���C���[�̍U���̊��N���X
/// </summary>
class ShotBase
{
public:
	ShotBase();
	virtual ~ShotBase();

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw()  = 0;


	bool IsExist() const { return m_isExist; }
	/// �����蔻��̋�`���擾����
	Rect GetColRect() const { return m_colRect; }

	void SetMain(SceneMain* pMain) { m_pMain = pMain; };
	void SetPlayer(Player* pPlayer) { m_pPlayer = pPlayer; }

	/// <summary>
	/// �e���X�^�[�g������
	/// </summary>
	/// <param name="pos">���ˈʒu</param>
	virtual void Start(Vec2 pos) = 0;

protected:
	// SceneMain�̊֐����Ăяo���|�C���^���o���Ă���
	SceneMain* m_pMain;
	//�V���b�g��ł����v���C���[�̃|�C���^���o���Ă���
	Player* m_pPlayer;

	bool m_isExist;	// ���݂��Ă��邩�t���O(�g�p�����ǂ���)

	// �\���ʒu
	Vec2 m_pos;
	// �����蔻��̋�`
	Rect m_colRect;
	// �ړ���	1�t���[��������̈ړ��x�N�g��������
	Vec2 m_vec;
};

