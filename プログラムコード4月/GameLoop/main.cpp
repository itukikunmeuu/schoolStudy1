#include "DxLib.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//�ꕔ�̊֐���DxLib_Iint()�̑O�Ɏ��s����K�v������
	ChangeWindowMode(1);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	//�\��ʂł͂Ȃ��A����ʂɕ`�悷��
	SetDrawScreen(DX_SCREEN_BACK);

	//�~�̕\���ʒu
	int posX = 240;
	//�~�̈ړ�����
	int moveX = 12;	//�E�����Ɉړ�������

	//�O���t�B�b�N�f�[�^���������ɓǂݍ���
	//��while���[�v���œǂݍ��܂Ȃ��悤�ɋC��t����I
	//while���[�v���œǂݍ���ł��܂���1�b�Ԃ�60��O���t�B�b�N�f�[�^��ǂݍ���ł��܂�
	int player_Hand = LoadGraph("data/a.png");

	//�v���C���[�̕\���ʒu��ϐ��ő҂�
	int playerX = 320;
	int playerY = 240;

	//�v���C���[�̈ړ���
	int playerMoveY = 4;

	//�Q�[�����I�����Ȃ������ɃQ�[���̏����͍s����i1�b�Ԃ�60�񏈗����s����j
	while (ProcessMessage() != -1) //windows����ʂ����ƌ���Ȃ�����J��Ԃ� 
	{
		//�`����s���O�ɉ�ʂ��N���A����
		ClearDrawScreen();
		//////////////////////////////
		//        �ړ�����			//
		////////////////////////////// 
		//�~�̈ʒu��ύX����
		posX += moveX; //moveX��+4,��������-4�����Ƃ�Ȃ�
		//��ʒ[�܂ōs������i�s������ς���
		if (posX > 640) //�~�̒��S����ʉE�[�����E�ɍs�����ꍇ
		{
			posX = 640; //��ʊO�ɏo�Ă������ʓ��ɖ߂�
			moveX = -4; //�E�Ɉړ����Ă����̂����Ɉړ����������̂ňړ�������ύX
		}
		if (posX < 0) //��ʍ��[�������ɏo���ꍇ
		{
			posX = 0; //��ʓ��ɖ߂�
			moveX = 12; //�E�Ɉړ���������
		}
		//�R���g���[���[�i�L�[�{�[�h�j�ŃL�����N�^�[���ړ�������

		//GetJoypadInputState()���g�p����
		//padState�Ƀp�b�h�̉�����Ă����Ԃ��擾����
		int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		if ((padState & PAD_INPUT_UP) != 0)
		
		{
			//������Ă���
			playerY -= 4;	//��ʊO�ɏo�悤�Ƃ���
			if (playerY < 0)
			{
				playerY = 0;
			}
		}
		if ((padState & PAD_INPUT_DOWN) != 0)

		{
			//������Ă���
			playerY += 4;
			playerY -= 4;	//��ʊO�ɏo�悤�Ƃ���
			if (playerY < 480 - 32)
			{
				playerY = 480 - 32;
			}
		}
		if ((padState & PAD_INPUT_LEFT) != 0)

		{
			//������Ă���
			playerY -= 4;
			playerY -= 4;	//��ʊO�ɏo�悤�Ƃ���
			if (playerY < 0)
			{
				playerY = 0;
			}
		}
		if ((padState & PAD_INPUT_RIGHT) != 0)

		{
			//������Ă���
			playerY += 4;
			playerY -= 4;	//��ʊO�ɏo�悤�Ƃ���
			if (playerY < 640 - 32)
			{
				playerY = 640 - 32;
			}
		}



		//�v���C���[�L�����N�^�[�̏㉺�ړ�
		/*
		//�v���C���[�̈ړ������@�㉺�Ɉړ�������
		playerY += playerMoveY; //�v���C���[�̈ړ�
		if (playerY > 480 - 32) //��ʉ��[�������ɍs�����ꍇ�̏���
								//��ʉ��[�̍��W-�O���t�B�b�N�̍����Ŕ���
		{
			playerY = 480 - 32;
			playerMoveY = -4;
		}
		if (playerY < 0)
		{
			playerY = 0;
			playerMoveY = 4;
		}
		*/

		//////////////////////////
		//		�`�揈��		//
		///////////////////////// 
		//�~���E�ɓ���������
		DrawCircle(posX, 240, 16, GetColor(255, 255, 255), 1);

		//�ǂݍ��񂾃O���t�B�b�N�f�[�^��`�悷��
		DrawGraph(320, 240, player_Hand, 1);

		//��ʂ��؂�ւ��̂�҂�
		ScreenFlip();

		//�Q�[�����I������A��I�������Ƃ�
		if (0) break;
	}

	//�ǂݍ��񂾃O���t�B�b�N�f�[�^������������������
	DeleteGraph(player_Hand);


	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}