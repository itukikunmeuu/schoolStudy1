#include "DxLib.h"



// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    //�ꕔ�̊֐���Dxlib_Init()�̑O�Ɏ��s����K�v������
    ChangeWindowMode(true);



    if (DxLib_Init() == -1)        // �c�w���C�u��������������
    {
        return -1;            // �G���[���N�����璼���ɏI��
    }



    SetDrawScreen(DX_SCREEN_BACK);

    int x = 320;
    int moveX = 8;

    // �Q�[�����[�v
    while (ProcessMessage() != -1)
    {

        //���̃t���[���̊J�n�������o���Ă���
        LONGLONG start = GetNowHiperfoemanceCount();

        // �`����s���O�ɉ�ʂ��N���A����
        ClearDrawScreen();



        //�L�����N�^�[�̈ړ�
        x += 1;



        // ��ʂ��؂�ւ��̂�҂�
        ScreenFlip();


        //esc�L�[�ŃQ�[���I��
        if (CheckHitKey(KEY_INPUT_ESCAPE))
        {
            break;
        }

        //FPS60�ɌŒ肷��
        while (GetNowPerfowmanxeCount() - start < 16667)
        {
            //16.66�~���b�i16667�}�C�N���b�j�o�߂���܂ő҂�
        }
    }

    DxLib_End();                // �c�w���C�u�����g�p�̏I������



    return 0;                // �\�t�g�̏I�� 
}