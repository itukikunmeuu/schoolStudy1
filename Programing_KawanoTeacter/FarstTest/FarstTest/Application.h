#pragma once
/// <summary>
/// �A�v���P�[�V�����S�̂��Ǘ�����N���X
/// �V���O���g���N���X
/// </summary>
class Application
{
private:
	Application() {};//�V���O���g���̂��߂ɃR���X�g���N�^���v���C�x�[�g�ɂ���
	// �R�s�[������̋֎~
	Application(const Application& app) = delete;//�����I�ɃR�s�[�R���X�g���N�^��private�ɐ錾
	//private: �N���X��(const�@�N���X��& ref)=delete;
	                                             //��������邱�ƂŃR�s�[�R���X�g���N�^������ɑ���̂�h��
	void operator =(const Application& app) = delete;//������Z�q�����łɔp�~

	/// <summary>
	/// �㏈�����s��
	/// </summary>
	void Terminate();
public:
	/// <summary>
	/// Application�̃V���O���g���C���X�^���X��Ԃ�
	/// </summary>
	/// <returns>Application�C���X�^���X�̎Q�Ƃ�Ԃ�</returns>
	static Application& GetInstance();

	bool Init();
	void Run();

};

