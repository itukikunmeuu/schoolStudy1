#pragma once
class Input;
class Scene;
/// <summary>
/// �e�V�[���̑J�ڂ��R���g���[������N���X
/// </summary>
class SceneManager
{
private:
	Scene* m_pScene = nullptr;
public:
	~SceneManager();
	/// <summary>
	/// �����Ă���V�[����Update�֐����Ăяo��
	/// </summary>
	/// <param name="input">���̓N���X</param>
	void Update(Input& input);
	/// <summary>
	/// �����Ă���V�[���̕`��Draw�֐����Ăяo��
	/// </summary>
	void Draw();

	/// <summary>
	/// ���ݎ��s���̃V�[���������Ŏw�肳�ꂽ�V�[���ɐ؂�ւ���
	/// </summary>
	/// <param name="nextScene">���̃V�[��</param>
	void ChangeScene(Scene* nextScene);
};
