#pragma once
#include "Scene.h"
#include <unordered_map>
#include "../Input.h"
/// <summary>
/// �L�[�R���t�B�O�̃V�[��
/// </summary>
class KeyConfigScene : public Scene
{
public:
	KeyConfigScene(SceneManager& mgr, Input& input);
	~KeyConfigScene();

	void Update(Input& input);
	void Draw();

private:
	int m_frame = 0;

	std::unordered_map<int, std::wstring> m_keynameTable;
	std::unordered_map<int, std::wstring> m_padnameTable;

	std::vector<std::string> m_menuItems;	// ����̏���ɃR�}���h����ёւ��邽�߂̔z��

	int m_currentLineIndex = 0;		// ���ݍs�̃C���f�b�N�X
	bool m_isEditingNow = false;	// ���ҏW���Ȃ̂�(�g�O��)
	bool m_isEditRequestButton = false;	// �ҏW�{�^���������ꂽ��

	Input& m_input;	// Input�N���X�̎Q�Ƃ������Ă���
	InputTable_t m_keyCommandTable;

	// �X�V�����o�֐��|�C���^
	using UpdateFunc_t = void(KeyConfigScene::*)(Input& input);
	UpdateFunc_t  m_updateFunc;
	// �`�惁���o�֐��|�C���^
	using DrawFunc_t = void (KeyConfigScene::*)();
	DrawFunc_t m_drawFunc;

	// �X�V�֐�
	void AppearUpdate(Input&);	// �o����
	void NormalUpdate(Input&);		// �ʏ���
	void EditUpdate(Input&);		// �ҏW���
	void DisappearUpdate(Input&);	// �ޏ���

	// �`��֐�
	void ExpandDraw();	// �g���k���`��
	void NormalDraw();	// ��t�F�[�h�`��

	void DrawCommandList();	// �R�}���h���X�g�̕`��(�e�L�X�g�`��)

	void CommitCurrenKeySetting();

	// �����̃L�[�ǁ[�ǂ���L�[������𓾂�
	std::wstring GetKeyName(int keycode);
	std::wstring GetPadName(int padstate);
};

