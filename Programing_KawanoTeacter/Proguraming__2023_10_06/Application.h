#pragma once
/// <summary>
/// �A�v���P�[�V�����S�̂��Ǘ�����N���X
/// </summary>
class Application
{
private:
	Application(){}
public:
	/// <summary>
	/// Apprication�̃V���O���g���C���X�^���X�̎Q�Ƃ�Ԃ�
	/// </summary>
	/// <returns>Apprication�C���X�^���X</returns>
	static Application& GetInstance() {
		static Application instance;
		return instance;
	}
	void Init();
	void Run();
};

