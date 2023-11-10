#pragma once
#include <array>
#include<map>
#include<string>

enum class InputType {
	keybd,
	pad,
};
class Input
{
	friend KeyConfigScene;//�L�[�R���t�B�O����͊ی���


private:
	//�R�}���h���Ɠ��͂��y�A�ɂ����e�[�u��
	//�L�[�{�[�h�̎���keybd&key_INPUT�Z�Z��
	
	std::array<char, 256> m_keyState;
	std::array<char, 256> m_lastKeyState;

	//�R�}���h���ƃL�[�R�[�h���y�A�ɂ����e�[�u��
	std::map<std::string, int>comandTable_;
public:
	Input();
	/// <summary>
	/// ���͂̏����X�V����
	/// </summary>
	void Update();
	/// <summary>
	/// �w��̃R�}���h�������ꂽ�u�ԂȂ̂�
	/// </summary>
	/// <param name="command">�R�}���h������</param>
	/// <returns>true:�����ꂽ�u�� / false:������Ă��Ȃ�����������</returns>
	bool IsTriggered(const char* command) const;
};

