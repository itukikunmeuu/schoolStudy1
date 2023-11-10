#pragma once
#include"Scene.h"

	/// <summary>
/// �|�[�Y���̃V�[���N���X
/// </summary>
	class KeyConfigScene : public Scene
	{
	public:
		KeyConfigScene(SceneManager& mgr);

		void Update(Input& input);
		void Draw();

	private:
		int m_frame = 0;

		// �X�V�����o�֐��|�C���^
		using UpdateFunc_t = void(KeyConfigScene::*)(Input& input);
		UpdateFunc_t  m_updateFunc;
		// �`�惁���o�֐��|�C���^
		using DrawFunc_t = void (KeyConfigScene::*)();
		DrawFunc_t m_drawFunc;

		// �X�V�֐�
		void AppearUpdate(Input&);	// �o����
		void NormalUpdate(Input&);		// �ʏ���
		void DisappearUpdate(Input&);	// �ޏ���

	

		// �`��֐�
		void ExpandDraw();	// �g���k���`��
		void NormalDraw();	// ��t�F�[�h�`��
		void DrawCommandList();
};

