#include "DxLib.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// �ꕔ�̊֐���DxLib_Init()�̑O�Ɏ��s����K�v������
	ChangeWindowMode(true);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	SetDrawScreen(DX_SCREEN_BACK);

	int screen = MakeScreen(640, 480, true);

	// �Q�[�����[�v
	while (ProcessMessage() != -1)
	{
		// ���̃t���[���̊J�n�������o���Ă���
		LONGLONG start = GetNowHiPerformanceCount();

		// �`����s���O�ɉ�ʂ��N���A����
		ClearDrawScreen();

		// �Q�[���̏���
		SetDrawScreen(screen);

		//ClearDrawScreen();//��ʂ��N���A���Ă��Ȃ��̂őO�̏�Ԃɏ㏑������Đ���������

		//��ʂ𕢂�������(6%�̕s�����x)�̎��i��\�����Ă���
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 16);
		DrawBox(0, 0, 640, 480, 0x000000, true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);


		//�}�E�X�̌��݈ʒu�ƁA���N���b�N������Ă��邩���`�F�b�N
		int mouseX, mouseY;
		GetMousePoint(&mouseX, &mouseY);
		bool isLeft = (GetMouseInput() & MOUSE_INPUT_LEFT);

		//���N���b�N��������Ă�����ۂ�`�悷��
		if (isLeft)
		{
			DrawCircle(mouseX, mouseY, 8, GetColor(255, 255, 0), true);
			//DrawCircle(mouseX, mouseY,8,GetColor(255,255,0),true);
		}

		//�f�t�H���g�̃o�b�N�o�b�t�@�ւ̏������݂ɖ߂�
		SetDrawScreen(DX_SCREEN_BACK);
		ClearDrawScreen();
		DrawGraph(0, 0, screen, true);

		//10�i�A16�i�\�L�̕��K
		int x = 10;  //10�i����10,16�i����a������
		int y = 0x10;//0x�Ŏn�܂鐔����16�i��
					 //16�i����10�A10�i����16������

		DrawFormatString(0, 0, 0xffffff, "%d", x); //10
		DrawFormatString(0, 16, 0xffffff, "%d", y);//16
		DrawFormatString(0, 32, 0xffffff, "0x%x", x); //0xa


		// ��ʂ��؂�ւ��̂�҂�
		ScreenFlip();

		// esc�L�[�ŃQ�[���I��
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}

		// FPS60�ɌŒ肷��
		while (GetNowHiPerformanceCount() - start < 16667)
		{
			// 16.66�~���b(16667�}�C�N���b)�o�߂���܂ő҂�
		}
	}

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}