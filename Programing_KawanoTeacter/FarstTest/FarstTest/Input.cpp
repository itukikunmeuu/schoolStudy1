#include "Input.h"
#include <DxLib.h>

void Input::Update()
{
    m_lastKeyState = m_keyState;    // 前のフレームの情報を代入
    GetHitKeyStateAll(m_keyState.data());   // 現在の入力を取得
}

bool Input::IsTriggered(const char* command) const
{

    return !m_lastKeyState[KEY_INPUT_RETURN] && m_keyState[KEY_INPUT_RETURN];
}
