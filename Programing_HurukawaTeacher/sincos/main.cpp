#include "DxLib.h"
#include <cmath>

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	// �ꕔ�̊֐���DxLib_Init()�̑O�Ɏ��s����K�v������
	ChangeWindowMode(true);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	SetDrawScreen(DX_SCREEN_BACK);

	// �Q�[�����[�v
	float angle = 0.0f;


	while (ProcessMessage() != -1)
	{
		// ���̃t���[���̊J�n�������o���Ă���
		LONGLONG start = GetNowHiPerformanceCount();

		// �`����s���O�ɉ�ʂ��N���A����
		ClearDrawScreen();

		// �Q�[���̏���
		constexpr int kCenterX = 320;
		constexpr int kCenterY = 240;
		constexpr float kBarLen = 100;

		//���S��
		DrawCircle(kCenterX, kCenterY, 2, GetColor(255, 255, 255), true);
		//���akBarLen�̉~
		DrawCircle(kCenterX, kCenterY, kBarLen, GetColor(255, 255, 255), false);

		//���S����^������ɒ�����e��
		DrawLine(kCenterX, kCenterY, kCenterX, kCenterY- kBarLen,GetColor(255, 255, 255));

		angle += 0.1f;

		//���x�̕����ɒ�����e���ɂ�
		constexpr float kAngle = 60.0f; //kAngle�x�̕����ɒ���kBarLen�̒�������������
		//��������kAngle�Ƃ͉��̊p�x�H
		//����l�E������0�x�Ƃ��āA�����v����kAngle�̕����ɐL�΂�����

		//�}�ɂ���΂������������A�v���O�����ŏ����ꍇ��
		//X,Y���W�ɕϊ�����K�v������B
		float offsetX = cosf(angle) * kBarLen;
		float offsetY = sinf(angle) * kBarLen;

		//���S����kAngle
		DrawLine(kCenterX, kCenterY, kCenterX + offsetX, kCenterY - offsetY, GetColor(255, 255, 255));



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