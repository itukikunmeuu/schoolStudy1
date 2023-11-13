#pragma once

struct Size
{
	int w;
	int h;
};

/// <summary>
/// �A�v���P�[�V�����S�̂��Ǘ�����N���X
/// �V���O���g���N���X
/// </summary>
class Application
{
private:
	Size m_windowSize;

	Application();//�V���O���g���̂���private��
	//�R�s�[������̋֎~
	Application(const Application& app) = delete; //�R�s�[�R���X�g���N�^�̔p�~
	void operator =(const Application& app) = delete; //����R���X�g���N�^�̔p�~

	/// <summary>
	/// �㏈�����s��
	/// </summary>
	void Terminate();
public:
	/// <summary>
	/// Application�̃V���O���g���N���X��Ԃ�
	/// </summary>
	/// <returns>Application�C���X�^���X�̎Q�Ƃ�Ԃ�</returns>
	static Application& GetInstance()
	{
		static Application instance; //�������g�̐��G�I�u�W�F�N�g�����܂�
		return instance;
	}

	bool Init();
	void Run();

	const Size& GetWindowSize() const;
};
