#pragma once
#include "Scene.h"

/// <summary>
/// �^�C�g���V�[���N���X
/// </summary>
class TitleScene : public Scene
{
public:
	TitleScene(SceneManager& manager);
	~TitleScene();
	virtual void Update(Input& input);
	virtual void Draw();

private:
	int  m_handle = 0;
	int m_frame = 0;

	// �X�V�����o�֐��|�C���^
	void(TitleScene::* m_updateFunc)(Input& input);
	// �`�惁���o�֐��|�C���^
	using DrawFunc_t = void (TitleScene::*)();
	DrawFunc_t m_drawFunc;

	// �X�V�֐�
	void FadeInUpdate(Input&);	// �t�F�[�h�C�����
	void NormalUpdate(Input&);	// �ʏ���
	void FadeOutUpdate(Input&);	// �t�F�[�h�A�E�g���

	// �`��֐�
	void FadeDraw();	// �t�F�[�h���`��
	void NormalDraw();	// ��t�F�[�h�`��
};

