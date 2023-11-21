#include "Input.h"
#include <DxLib.h>
#include <string>

using namespace std;

namespace {
    struct  KeyCondHeader
    {
        char id[4] = "kyc";
        float version = 1.0f;
        size_t dataCount = 0;
    };
}

Input::Input()
{
}

void Input::Update()
{
    m_lastKeyState = m_keyState;    // ‘O‚ÌƒtƒŒ[ƒ€‚Ìî•ñ‚ğ‘ã“ü
    GetHitKeyStateAll(m_keyState.data());   // Œ»İ‚Ì“ü—Í‚ğæ“¾
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
