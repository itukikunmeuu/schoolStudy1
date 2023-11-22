#include "Input.h"
#include <DxLib.h>
#include <string>
#include <algorithm>

using namespace std;

namespace
{
    struct KeyConfHeader
    {
        char id[4] = "kyc"; // �Ō��'\0'�����Ă�̂�4�o�C�g
        float version = 1.0f;
        size_t dataCount = 0;
        // �󔒂�4�o�C�g(�p�f�B���O)
    };
}

const InputTable_t Input::GetCommandTable() const
{
    InputTable_t ret = m_commandTable;
    for (const auto& ex : m_exclusiveKeyConfigCommands)
    {
        ret.erase(ex);
    }

    return ret;
}

Input::Input()
{
    m_commandTable["OK"] = { {InputType::keybd, KEY_INPUT_RETURN} ,
                             {InputType::pad,   PAD_INPUT_A} };
    m_commandTable["cancel"] = { {InputType::keybd, KEY_INPUT_ESCAPE} ,
                             {InputType::pad,   PAD_INPUT_B} };     // B�{�^��

    m_commandTable["pause"] = { {InputType::keybd,  KEY_INPUT_P},
                                {InputType::pad,    PAD_INPUT_R} }; // �X�^�[�g�{�^��
    m_commandTable["keyconf"] = { {InputType::keybd,  KEY_INPUT_K},
                                {InputType::pad,    PAD_INPUT_L} }; // �L�[�R���t�B�O

    m_commandTable["jump"] = { {InputType::keybd, KEY_INPUT_Z} ,
                             {InputType::pad,   PAD_INPUT_C} };     // X�{�^��
    m_commandTable["attack"] = { {InputType::keybd, KEY_INPUT_X} ,
                             {InputType::pad,   PAD_INPUT_X} };     // Y�{�^��

    m_commandTable["up"] = { {InputType::keybd,  KEY_INPUT_UP},
                             {InputType::pad,    PAD_INPUT_UP} };
    m_commandTable["down"] = { {InputType::keybd,  KEY_INPUT_DOWN},
                             {InputType::pad,    PAD_INPUT_DOWN} };
    m_commandTable["left"] = { {InputType::keybd,  KEY_INPUT_LEFT},
                             {InputType::pad,    PAD_INPUT_LEFT} };
    m_commandTable["right"] = { {InputType::keybd,  KEY_INPUT_RIGHT},
                             {InputType::pad,    PAD_INPUT_RIGHT} };

    m_exclusiveKeyConfigCommands = {"up", "down", "left", "right"};


    Load(L"key.conf");
}

void Input::Update()
{
    m_lastInputDate = m_inputDate;  // ���O���͂��R�s�[���Ă���

    // �n�[�h�E�F�A���̓`�F�b�N
    char keystate[256]; // �L�[�{�[�h�p
    GetHitKeyStateAll(keystate);   // ���݂̃L�[�{�[�h���͂��擾
    int padstate = GetJoypadInputState(DX_INPUT_PAD1);  // �p�b�h���̎擾

    // �o�^���ꂽ���ƃn�[�h�̏����Ƃ炵���킹�Ȃ���A
    // m_inputData�̓��e���X�V���Ă���
    for (const auto& cmd : m_commandTable)
    {
        // �R�}���h�̖��O������̓f�[�^�����
        auto& input = m_inputDate[cmd.first];
        for (const auto& hardIO : cmd.second)
        {
            input = false;
            // �L�[�{�[�h�̃`�F�b�N
            if (hardIO.first == InputType::keybd)
            {
                if (keystate[hardIO.second])
                {
                    input = true;
                    break;
                }
            }
            else if (hardIO.first == InputType::pad)
            {
                if (padstate & hardIO.second)
                {
                    input = true;
                    break;
                }
            }
        }
    }
}

bool Input::IsTriggered(const char* command) const
{
    auto it = m_inputDate.find(command);
    // �v�f���Ȃ�������false��Ԃ�
    if (it == m_inputDate.end()) return false;

    return m_inputDate.at(command) && !m_lastInputDate.at(command);

}

bool Input::IsPressing(const char* command) const
{
    auto it = m_inputDate.find(command);
    // �v�f���Ȃ�������false��Ԃ�
    if (it == m_inputDate.end()) return false;

    return m_inputDate.at(command);
}

bool Input::IsReleased(const char* command) const
{
    auto it = m_inputDate.find(command);
    // �v�f���Ȃ�������false��Ԃ�
    if (it == m_inputDate.end()) return false;

    return !m_inputDate.at(command) && m_lastInputDate.at(command);
}

void Input::Save(const std::string& path)
{
    FILE* fp = nullptr; // �t�@�C���|�C���^
    auto err = fopen_s(&fp, path.c_str(), "wb");
    // �w�b�_�̏�������
    KeyConfHeader header;
    header.dataCount = m_commandTable.size();
    fwrite(&header, sizeof(header), 1, fp);

    // �f�[�^�{�̂���������ł���
    for (const auto& cmd : m_commandTable)
    {
        const auto& commandStr = cmd.first; // �R�}���h������
        uint8_t size = commandStr.size();   // �R�}���h������̃T�C�Y���擾
        fwrite(&size, sizeof(size), 1, fp); // �R�}���h������̃o�C�g������������
        fwrite(commandStr.data(), commandStr.size(), 1, fp);    // ������̏�������

        const auto& InputData = cmd.second; // �Ή��������
        uint8_t inputTypeSize = InputData.size();   // �Ή�������͂̐�(��{�I��2, �L�[�{�[�h�ƃp�b�h)
        fwrite(&inputTypeSize, sizeof(inputTypeSize), 1, fp);   // 2����������
        for (const auto& input : InputData)
        {
            const auto& type = input.first; // �L�[�{�[�h���p�b�h��
            const auto& state = input.second;   // ���ۂ̓���ID

            fwrite(&type, sizeof(type), 1, fp);
            fwrite(&state, sizeof(state), 1, fp);
        }
    }

    fclose(fp);
}

void Input::Load(const std::wstring& path)
{
    auto handle = FileRead_open(path.c_str());

    if (handle == 0)
    {
        return;
    }
    // �w�b�_�̓ǂݍ���
    KeyConfHeader header;
    FileRead_read(&header, sizeof(header), handle);

    // �f�[�^�̓ǂݍ���
    for (int i = 0; i < header.dataCount; i++)
    {
        uint8_t cmdStrSize = 0; // �R�}���h������̃T�C�Y
        FileRead_read(&cmdStrSize, sizeof(cmdStrSize), handle); // �R�}���h������T�C�Y�ǂݍ���
        std::string cmdStr; // �R�}���h������
        cmdStr.resize(cmdStrSize);  // �R�}���h������T�C�Y�Ń��T�C�Y
        FileRead_read(cmdStr.data(), cmdStr.size()*sizeof(char), handle);   // �R�}���h������̓ǂݍ���

        auto& command = m_commandTable[cmdStr]; // �R�}���h�e�[�u������Ώۂ̃R�}���h�̎Q�Ƃ��擾

        uint8_t inputTypeSize;  // ���͎�ʐ����擾���Ă���(��{�I�ɂ�2�������Ă�)
        FileRead_read(&inputTypeSize, sizeof(inputTypeSize), handle);   // ��ʐ��̎擾
        for (int j = 0; j < inputTypeSize; j++) // �擾������ʐ��������[�v����
        {
            InputType type;
            int state;

            FileRead_read(&type, sizeof(type), handle); // ��ʂ�ǂ݂���
            FileRead_read(&state, sizeof(state), handle);   // ���ۂ̓��̓X�e�[�g����ǂݍ���

            command[type] = state;  // �R�}���h�ɔ��f������
        }
    }

    FileRead_close(handle);
}
