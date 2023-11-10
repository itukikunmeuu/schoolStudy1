#include "Input.h"
#include <DxLib.h>
#include <string>

using namespace std;

Input::Input()
{
}

void Input::Update()
{
    m_lastKeyState = m_keyState;    // 前のフレームの情報を代入
    GetHitKeyStateAll(m_keyState.data());   // 現在の入力を取得
}

bool Input::IsTriggered(const char* command) const
{
    string cmd = command;
    if (cmd == "OK")
    {
        return !m_lastKeyState[KEY_INPUT_RETURN] && m_keyState[KEY_INPUT_RETURN];
    }
    else if (cmd == "pause")
    {
        return !m_lastKeyState[KEY_INPUT_P] && m_keyState[KEY_INPUT_P];
    }
}
