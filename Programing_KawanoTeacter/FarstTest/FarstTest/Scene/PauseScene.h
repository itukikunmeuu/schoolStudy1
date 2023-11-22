#pragma once
#include "Scene.h"

class Input;
class ScneManager;
/// <summary>
/// �|�[�Y���̃V�[���N���X
/// </summary>
class PauseScene : public Scene
{
public:
	PauseScene(SceneManager& mgr);

	void Update(Input& input);
	void Draw();

private:
	int m_frame = 0;

	// �X�V�����o�֐��|�C���^
	using UpdateFunc_t = void(PauseScene::*)(Input& input);
	UpdateFunc_t  m_updateFunc;
	// �`�惁���o�֐��|�C���^
	using DrawFunc_t = void (PauseScene::*)();
	DrawFunc_t m_drawFunc;

	// �X�V�֐�
	void AppearUpdate(Input&);	// �o����
	void NormalUpdate(Input&);		// �ʏ���
	void DisappearUpdate(Input&);	// �ޏ���

	// �`��֐�
	void ExpandDraw();	// �g���k���`��
	void NormalDraw();	// ��t�F�[�h�`��
};

