#include "KeyConfigScene.h"
#include <DxLib.h>
#include "../Input.h"
#include "../Application.h"
#include "SceneManager.h"
#include "../StringUtility.h"

namespace
{
	constexpr int kAppeaInterval = 60;
	constexpr int kMenuMargin = 60;
}

KeyConfigScene::KeyConfigScene(SceneManager& mgr, Input& input) : 
	Scene(mgr),
	m_input(input)
{
	m_keyCommandTable = input.GetCommandTable();
	m_updateFunc = &KeyConfigScene::AppearUpdate;
	m_drawFunc = &KeyConfigScene::ExpandDraw;

	// ���j���[�ɕ��ԏ������
	m_menuItems = {
		"jump",		// �W�����v
		"attack",	// �U��
		"OK",		// �I��or�m��
		"cancel",	// �L�����Z��
		"pause",	// �|�[�Y�{�^��
		"keyconf"	// �L�[�R���t�B�O�{�^��
	};

	m_keynameTable[KEY_INPUT_A] = L"�`�L�[";
	m_keynameTable[KEY_INPUT_B] = L"�a�L�[";
	m_keynameTable[KEY_INPUT_C] = L"�b�L�[";
	m_keynameTable[KEY_INPUT_D] = L"�c�L�[";
	m_keynameTable[KEY_INPUT_E] = L"�d�L�[";
	m_keynameTable[KEY_INPUT_F] = L"�e�L�[";
	m_keynameTable[KEY_INPUT_G] = L"�f�L�[";
	m_keynameTable[KEY_INPUT_H] = L"�g�L�[";
	m_keynameTable[KEY_INPUT_I] = L"�h�L�[";
	m_keynameTable[KEY_INPUT_J] = L"�i�L�[";
	m_keynameTable[KEY_INPUT_K] = L"�j�L�[";
	m_keynameTable[KEY_INPUT_L] = L"�k�L�[";
	m_keynameTable[KEY_INPUT_M] = L"�l�L�[";
	m_keynameTable[KEY_INPUT_N] = L"�m�L�[";
	m_keynameTable[KEY_INPUT_O] = L"�n�L�[";
	m_keynameTable[KEY_INPUT_P] = L"�o�L�[";
	m_keynameTable[KEY_INPUT_Q] = L"�p�L�[";
	m_keynameTable[KEY_INPUT_R] = L"�q�L�[";
	m_keynameTable[KEY_INPUT_S] = L"�r�L�[";
	m_keynameTable[KEY_INPUT_T] = L"�s�L�[";
	m_keynameTable[KEY_INPUT_U] = L"�t�L�[";
	m_keynameTable[KEY_INPUT_V] = L"�u�L�[";
	m_keynameTable[KEY_INPUT_W] = L"�v�L�[";
	m_keynameTable[KEY_INPUT_X] = L"�w�L�[";
	m_keynameTable[KEY_INPUT_Y] = L"�x�L�[";
	m_keynameTable[KEY_INPUT_Z] = L"�y�L�[";
	m_keynameTable[KEY_INPUT_BACK] = L"BS�L�[";
	m_keynameTable[KEY_INPUT_TAB] = L"Tab�L�[";
	m_keynameTable[KEY_INPUT_RETURN] = L"Enter�L�[";
	m_keynameTable[KEY_INPUT_LSHIFT] = L"��Shift�L�[";
	m_keynameTable[KEY_INPUT_RSHIFT] = L"�EShift�L�[";
	m_keynameTable[KEY_INPUT_LCONTROL] = L"��Ctrl�L�[";
	m_keynameTable[KEY_INPUT_RCONTROL] = L"�ECtrl�L�[";
	m_keynameTable[KEY_INPUT_ESCAPE] = L"Esc�L�[";
	m_keynameTable[KEY_INPUT_SPACE] = L"�X�y�[�X�L�[";

	m_padnameTable[PAD_INPUT_A] = L"�`�{�^��";
	m_padnameTable[PAD_INPUT_B] = L"�a�{�^��";
	m_padnameTable[PAD_INPUT_C] = L"�b�{�^��";
	m_padnameTable[PAD_INPUT_X] = L"�w�{�^��";
	m_padnameTable[PAD_INPUT_Y] = L"�x�{�^��";
	m_padnameTable[PAD_INPUT_Z] = L"�y�{�^��";
	m_padnameTable[PAD_INPUT_L] = L"�k�{�^��";
	m_padnameTable[PAD_INPUT_R] = L"�q�{�^��";
	m_padnameTable[PAD_INPUT_START] = L"�r�s�`�q�s�{�^��";
	m_padnameTable[PAD_INPUT_M] = L"�l�{�^��";
}

KeyConfigScene::~KeyConfigScene()
{
}

void KeyConfigScene::Update(Input& input)
{
	(this->*m_updateFunc)(input);
}

void KeyConfigScene::Draw()
{
	(this->*m_drawFunc)();
}

void KeyConfigScene::AppearUpdate(Input&)
{
	m_frame++;
	if (kAppeaInterval <= m_frame)
	{
		m_updateFunc = &KeyConfigScene::NormalUpdate;
		m_drawFunc = &KeyConfigScene::NormalDraw;
	}
}

void KeyConfigScene::NormalUpdate(Input& input)
{
	// �g�O������
	if (input.IsTriggered("OK"))
	{
		if (m_currentLineIndex < m_keyCommandTable.size())
		{
			m_isEditRequestButton = true;
		}
		else // �m��
		{
			CommitCurrenKeySetting();

			m_updateFunc = &KeyConfigScene::DisappearUpdate;
			m_drawFunc = &KeyConfigScene::ExpandDraw;
			m_frame = kAppeaInterval;
		}

		return;
	}

	if (m_isEditRequestButton)
	{
		if (input.IsReleased("OK"))
		{
			m_isEditingNow = !m_isEditingNow;
			m_updateFunc = &KeyConfigScene::EditUpdate;
			m_isEditRequestButton = false;
			return;
		}
	}

	if (input.IsTriggered("keyconf"))
	{
		m_updateFunc = &KeyConfigScene::DisappearUpdate;
		m_drawFunc = &KeyConfigScene::ExpandDraw;
		m_frame = kAppeaInterval;
	}

	auto size = m_keyCommandTable.size() + 1;
	if (input.IsTriggered("up"))
	{
		m_currentLineIndex = (m_currentLineIndex + size - 1) % size;
	}
	if (input.IsTriggered("down"))
	{
		m_currentLineIndex = (m_currentLineIndex + 1) % size;
	}
}

void KeyConfigScene::EditUpdate(Input& input)
{
	// �g�O������
	if (input.IsTriggered("OK"))
	{
		m_isEditingNow = !m_isEditingNow;
		m_updateFunc = &KeyConfigScene::NormalUpdate;

		return;
	}

	char keystate[256];
	GetHitKeyStateAll(keystate);
	int padstate = GetJoypadInputState(DX_INPUT_PAD1);

	auto strItem = m_menuItems[m_currentLineIndex];
	auto& cmd = m_keyCommandTable[strItem];
	for (int i = 0; i < 256; i++)
	{
		if (keystate[i])
		{
			cmd[InputType::keybd] = i;
			break;
		}
	}
	if (padstate)
	{
		cmd[InputType::pad] = padstate;
	}
}

void KeyConfigScene::DisappearUpdate(Input&)
{
	m_frame--;
	if (m_frame == 0)
	{
		m_manager.PopScene();
	}
}

void KeyConfigScene::ExpandDraw()
{
	Application& app = Application::GetInstance();
	const auto& size = app.GetWindowSize();

	int halfHeight = (size.h - 100) / 2;
	int centerY = size.h / 2;

	float rate = static_cast<float>(m_frame) / kAppeaInterval;	// ���݂̎��Ԃ̊���(0.0�`1.0)
	int currentHalfHeight = static_cast<int>(rate * halfHeight);

	// ������ƈÂ���`��`��
	DrawBox(kMenuMargin, centerY - currentHalfHeight, size.w - kMenuMargin, centerY + currentHalfHeight,
		0x444444, true);
	DrawBox(kMenuMargin, centerY - currentHalfHeight, size.w - kMenuMargin, centerY + currentHalfHeight,
		0xffffff, false);
}

void KeyConfigScene::NormalDraw()
{
	Application& app = Application::GetInstance();
	const auto& size = app.GetWindowSize();
	// ������ƈÂ���`��`��
	DrawBox(kMenuMargin, kMenuMargin, size.w - kMenuMargin, size.h - kMenuMargin,
		0x444444, true);

	DrawString(100, kMenuMargin + 10, L"KeyConfig Scene", 0xffffff);

	DrawBox(kMenuMargin, kMenuMargin, size.w - kMenuMargin, size.h - kMenuMargin,
		0xffffff, false);

	DrawCommandList();
}

void KeyConfigScene::DrawCommandList()
{
	constexpr int kLineHeight = 30;
	int y = kMenuMargin + 50 + 10;
	int idx = 0;
	constexpr unsigned int kDefaultColor = 0xffffff;
	for (const auto& item : m_menuItems)
	{
		auto& cmd = m_keyCommandTable[item];
		unsigned int lineColor = kDefaultColor;
		int x = kMenuMargin + 50;
		std::wstring cmdName = StringUtility::StringToWString(item);
		if (idx == m_currentLineIndex)
		{
			DrawString(x - 20, y, L"��", 0xff0000);
			x += 10;
			if (m_isEditingNow)
			{
				lineColor = 0xffaa00;
				x += 5;
			}
		}
		auto keyname = GetKeyName(cmd.at(InputType::keybd));
		auto padname = GetPadName(cmd.at(InputType::pad));
		DrawFormatString(x, y, lineColor, L"%s : keybd=%s , pad=%s",
										cmdName.c_str(), // �R�}���h��
										keyname.c_str(),	// �L�[�{�[�h�̒l
										padname.c_str());		// �p�b�h�̒l
		y += 20;
		idx++;
	}
	y += kLineHeight;
	int x = kMenuMargin + 200;
	unsigned int lineColor = kDefaultColor;
	if (m_currentLineIndex == m_keyCommandTable.size())
	{
		x += 10;
		DrawString(x - 20, y, L"��", 0xff0000);
	}
	DrawString(x, y, L"�m��", lineColor);
}

void KeyConfigScene::CommitCurrenKeySetting()
{
	// input�{�̂̃L�[�������������Ă��܂��B
	for (const auto& cmd : m_keyCommandTable)
	{
		m_input.m_commandTable[cmd.first] = cmd.second;
	}
	m_input.Save("key.conf");
}

std::wstring KeyConfigScene::GetKeyName(int keycode)
{
	wchar_t name[16];
	auto it = m_keynameTable.find(keycode);
	if (it == m_keynameTable.end())
	{
		wsprintf(name, L"%02x", keycode);
		return name;
	}
	return (it->second);
}

std::wstring KeyConfigScene::GetPadName(int padstate)
{
	wchar_t name[16];
	auto it = m_padnameTable.find(padstate);
	if (it == m_padnameTable.end())
	{
		wsprintf(name, L"%04x", padstate);
		return name;
	}
	return (it->second);
}

