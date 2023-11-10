#include "StringUtility.h"
#include <DxLib.h>
#include <cassert>

std::wstring StringUtility::StringToWString(const std::string& str)
{
    // in : ��񑤂�string(���炩���ߕ������Ă���)
    // out : �߂�l��wstring(�����񐔂��킩��Ȃ�)
    
    // MultiByteToWideChar�́A�Q��Ăяo�����Ƃ����҂���Ă���B
    // �P��ڂ̌Ăяo���́A�ϊ��㕶����̃T�C�Y�𓾂邽��
    // �Q��ڂ̌Ăяo���ŁA�ԊҌ㕶����𓾂�

    std::wstring ret;   // �ŏI�I�ɕԂ����C�h������(�ŏ��͉��������Ă��Ȃ�)

    // �P��ڂ̌Ăяo��
    int result = MultiByteToWideChar(
        CP_ACP,     // ��̕�����̃R�[�h�y�[�W�������܂�(ACP��ANSI������=ShitfJIS)
        0,          // �ϊ��I�v�V�����ł����A����͓��Ɏw��Ȃ��ł��̂�0
        str.data(), // ���̕�����̐擪�|�C���^
        str.size(), // ���̕�����̕�����
        nullptr,    // out, optional�Ȃ̂ŁAnullptr��n���Ă���
        0);         // �����ł͈Ӗ��Ȃ��̂�0�ɂ��Ă���

    // ��x�ڂ̌Ăяo���̖߂�l���A�ϊ��㕶����̕������ɂȂ��Ă��܂��B
    assert(result >= 0);

    ret.resize(result); // �󂯎��镶����̃o�b�t�@���m�ۂ���

    result = MultiByteToWideChar(
        CP_ACP,     // ���̃R�[�h�y�[�W
        0,          // �I�v�V����
        str.data(), // ���̕�����ւ̃A�h���X
        str.size(), // ��������̕�����
        ret.data(), // �ϊ��㕶����̃A�h���X
        ret.size());// �ϊ���̕�����

    return ret;
}
