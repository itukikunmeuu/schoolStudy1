#pragma once
#include<array>
#include<map>
#include<string>



class Input
{

private:


public:
	Input();
	/// <summary>
	/// ���̓��͂��X�V����
	/// </summary>
	void Update();
	/// <summary>
	/// �w��̃R�}���h�������ꂽ�u�ԂȂ̂�
	/// </summary>
	/// <param name="command"></param>
	/// <returns>true:�����ꂽ�u�� / false:������Ă��Ȃ����������ς�</returns>
	bool IsTriggered(const char* command) const;
};

