#include "DxLib.h"





// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(true);


	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}



	//�O���t�B�b�N�f�[�^���������ɓǂݍ���
	//�ǂݍ��񂾃f�[�^���g�������ꍇ�͂��̔ԍ����w�肵�Ă���B
	//�Ƃ���������Ԃ��Ă����i�n���h���ƌĂ΂��j
	//���̃n���h�����g�p���ĕ\������O���t�B�b�N���w�肷��
	int handle = LoadGraph("sai.png");

	DrawGraph(320, 240, handle, 1);

	DrawPixel(320, 240, GetColor(255, 255, 255));	// �_��ł�
	DrawLine(0,120,60,480, GetColor(255, 0, 0));
	DrawLine(0, 240, 120, 560, GetColor(255, 0, 0));
	DrawLine(0, 140, 140, 560, GetColor(255, 0, 0));
	DrawLine(0, 160, 160, 560, GetColor(255, 0, 0));
	DrawLine(0, 180, 180, 560, GetColor(255, 0, 0));


	//�F�̎w��G�@GetColor(255,255,255)
	//��ڂ̈����@�Grgb��r�i�ԕ����j
	//��ڂ̈����@�Grgb��g�i�Ε����j
	//�O�ڂ̈����@�Grgb�̂��i�����j
	WaitKey();				// �L�[���͑҂�

	//�������ォ��O���t�B�b�N�f�[�^���폜����
	//����ȍ~�g��Ȃ��A�Ƃ�����ԂɂȂ�����K���폜����
	DeleteGraph(handle);

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}