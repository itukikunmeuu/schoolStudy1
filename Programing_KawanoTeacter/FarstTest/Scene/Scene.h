#pragma once
class Input;
class SceneManager;
/// <summary>
/// �V�[�����N���X
/// �����ȃV�[���̊�ɂȂ�N���X
/// </summary>
class Scene
{
protected:
	SceneManager& m_manager;
public:
	/// <summary>
	/// ��������SceneManager�̎Q�Ƃ��󂯎���Ă���
	/// </summary>
	/// <param name="manager">SceneManager�̎Q��</param>
	Scene(SceneManager& manager);
	virtual ~Scene() {};

	/// <summary>
	/// �V�[���̍X�V
	/// </summary>
	/// <param name="input">���̓I�u�W�F�N�g</param>
	virtual void Update(Input& input) = 0;
	/// <summary>
	/// �V�[���̕`��
	/// </summary>
	virtual void Draw() = 0;
};
