#include "DxLib.h"




// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//�ꕔ�̊֐���Dxlib_Init()�̑O�Ɏ��s����K�v������
	ChangeWindowMode(true);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	SetDrawScreen(DX_SCREEN_BACK);

	Enemy enemy;
	enemy.init();
	//�G�̈ʒu��ύX����
	int x = 120;
	int y = 120;

	//����͒��ړ���Ă��邪���ۂɂ͂��낢��ȏ������������ʉ�ʔ����ɂȂ��Ă��܂����z��
	int x = -120;
	int y = 120:

	// �Q�[�����[�v
	while (ProcessMessage() != -1)
	{
		//���̃t���[���̊J�n�������o���Ă���
		LONGLONG start = GetNowHiPerformanceCount();
		
		// �`����s���O�ɉ�ʂ��N���A����
		ClearDrawScreen();

		//

		// ��ʂ��؂�ւ��̂�҂�
		ScreenFlip();

		//esc�L�[�ŏI��
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}

		//FPS60�ɌŒ肷��
		while (GetNowHiPerformanceCount() - start < 16667)
		{
		
		}


	}
	
	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}