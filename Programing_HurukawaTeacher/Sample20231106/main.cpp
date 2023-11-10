#include "DxLib.h"
#include <cmath>

//�x���@ degree
//�ʓx�@ radian

//�x���@�Ŏw�肳�ꂽ�p�x���ʓx�@�ɕϊ�����
double DegToRed(double deg)
{
	return DX_PI / 180 * deg;
}

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

	int handle = LoadGraph("data/Arrow.png");

	// �Q�[�����[�v
	while (ProcessMessage() != -1)
	{
		// ���̃t���[���̊J�n�������o���Ă���
		LONGLONG start = GetNowHiPerformanceCount();

		// �`����s���O�ɉ�ʂ��N���A����
		ClearDrawScreen();

		// �Q�[���̏���
		//sinf(angle);
		//cosf(60.0f);

		////��]�������ɕ`��
		//DrawRotaGraph(64, 64,
		//	1.0, //�g�嗦
		//	0.0, //��]
		//	handle, 
		//	true, //�w�i�̐F�𔲂��̂������Ȃ��̂� 
		//	false );//���]�����邩���肳���Ȃ��̂�
		//	//������f����̂��ȂƎv�������ł����Af������̂�float�^�A�����double�Ȃ̂�f�͕K�v�Ȃ�

		//�~����DXLIB��#define�Œ�`���Ă���Ă���̂�
		//DxLib�ŃQ�[�������Ƃ��͂�����g����

		//DX_PI    �@ :doble�^�ŉ~�������`
		//DX_PI_F   �@:float�^�ŉ~�������`
		//DX_TWO_PI�@ :double�^�ŉ~����*2���`
		//DX_TWO_P_FI :float�^�ŉ~����*2���`

		//�O�x����45�x����]������6�`���������B
		for (int i = 0; i < 6; i++)
		{
			DrawRotaGraph(64 + 96 * i,
				64, //y
				1.0, //�g�嗦
				//-45.0 * i, //��]
			//	DX_PI, //180�x��]�����Ă݂�
			//	DX_PI / 2, //90�x��]�����Ă݂� //+�Ōv�Z���Ă����Ɖ������ɕ\�������̂ŏ�����ɕ\��������ۂ�-DX_PI���g�p����
			//	DX_PI / 3, //60�x��]
			//	DX_PI / 180 * 22, //22�x��]
			//	DX_PI / 180, //1�x��]
				DegToRed(-45.0 * i),
				handle,
				true,false);
		}

		for (int i = 0; i < 6; i++)
		{
			//���S�_
			int startX = 64 + 96 * i;
			int startY = 64 + 128;
			DrawCircle(startX,
				startY,
				2,GetColor(255, 255, 0), true);

			//���S�_�����ɕ\������Ă�����Ɠ���������
			//����32�̐�����������

			//����L�΂����@
			double angle = DegToRed(-45.0 * i);
			double moveX = cos(angle) * 32;
			double moveY = sin(angle) * 32;



			//�E����(0�x)�̕����ɐ�������
			int endX = startX + moveX;
			int endY = startY + moveY;
			DrawLine(startX, startY,
				endX, endY,
				GetColor(255, 255, 255));

		}
		
		//��]�f��
		{
			//tempAngle�̕����ɐL�т��������
		static double tempAngle = 0.0;
		tempAngle += 0.02;

		//���S�_
		int startX = 320;
		int startY = 400;
		DrawCircle(startX,
			startY,
			2, GetColor(255, 255, 0), true);

		//���ŐL�т�������擾����
		//cos��X�����Asin��Y�������擾����
		double moveX = cos(tempAngle) * 64;
		double moveY = sin(tempAngle) * 64;

		//�J�n�_�̍��W�𑫂��ďI�_�̍��W��
		//�E����(0�x)�̕����ɐ�������
		int endX = startX + moveX;
		int endY = startY + moveY;
		DrawLine(startX, startY,
			endX, endY,
			GetColor(255, 255, 255));
		}


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

	DeleteGraph(handle);

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}