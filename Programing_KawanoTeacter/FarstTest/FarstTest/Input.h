#pragma once
#include <array>
#include <map>
#include <unordered_map>
#include <string>

enum class InputType
{
	keybd,	// �L�[�{�[�h
	pad		// �p�b�h
};

using InputTable_t = std::unordered_map<std::string, std::map<InputType, int>>;

class KeyConfigScene;

class Input
{
	// �L�[�R���t�B�O����͊ی���
	friend KeyConfigScene;
private:
	// �R�}���h���Ɠ��͂��y�A�ɂ����e�[�u��
	// �L�[�{�[�h�̎��� keybd&KEY_INPUT_�����ŁA
	// �p�b�h�̎���pad&PAD_INPUT_����
	// ���`�F�b�N����
	InputTable_t m_commandTable;
	std::vector<std::string> m_exclusiveKeyConfigCommands;

	// �R�}���h�̓��͂��o���Ă���
	std::map<std::string, bool> m_inputDate;		// ���݂̓���
	std::map<std::string, bool> m_lastInputDate;	// ���O�̓���

	const InputTable_t GetCommandTable() const;

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
	/// <summary>
	/// �������Ă��邩�ǂ���
	/// </summary>
	/// <param name="command">�R�}���h������</param>
	/// <returns>true:�������Ă���/false:�������Ă��Ȃ�</returns>
	bool IsPressing(const char* command) const;
	/// <summary>
	/// �w��̃R�}���h���b���ꂽ�u�ԂȂ̂�
	/// </summary>
	/// <param name="command">�R�}���h������</param>
	/// <returns>true:�����ꂽ�u��/false:�������ςȂ��A������Ă��Ȃ�</returns>
	bool IsReleased(const char* command) const;

	/// <summary>
	/// ���݂̃L�[�R���t�B�O���t�@�C���ɕۑ�����
	/// </summary>
	/// <param name="path">�ۑ��ꏊ</param>
	void Save(const std::string& path);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="path"></param>
	void Load(const std::wstring& path);
};

