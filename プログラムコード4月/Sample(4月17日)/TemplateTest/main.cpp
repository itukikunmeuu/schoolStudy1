#include "DxLib.h"
#include<cmath>

//�����蔻����Ƃ�~�̐�
#define CIRCLE_NUM 3

//�~�̃f�[�^���\���̂ɂ܂Ƃ߂�
typedef struct CircleData
{
	//�����o�������ɏ���
	float x;			//x���W
	float y;			//Y���W
	float radius;		//���a
	unsigned int color;	//�F
}CircleData;

//�Q�ƌ^�̕��K
//�v���C���[�𓮂����̂��֐���
//�֐����Ń}�E�X�J�[�\���̈ʒu���Ƃ�A�����Ƃ��ēn���ꂽCircleData�̍��W�ɐݒ肷��
void updatePlayer(CircleData* pPlayer)
{
	//�Q�[���̏���
	int mouseX;
	int mouseY;

	//�}�E�X�̈ʒu���擾����
	GetMousePoint(&mouseX, &mouseY);
	pPlayer->x = (float)mouseX;
	pPlayer->y = (float)mouseY;
}

//�~�̃f�[�^���n���ē������Ă��邩�������Ă��Ȃ����𔻒肷��֐�
bool isCollision(CircleData c0, CircleData c1)
{
	//1.������Ƃ肽���e�~�̒��S�̋��������߂�
		//�����W�̋����@c0.x - c1.xl
		//�����W�̋���  c0.y - c1.yl
	float dx = c0.x - c1.x;
	float dy = c0.y - c1.y;
	float dist(dx * dx + dy * dy);
	//2.���a�̍��v�Ƌ������r���Ă�������Ƃ�
#if false
	if (dist < (c0.radius + c1.radius))
	{
		//�������Ă���
		return true;
	}
		//�������Ă��Ȃ�
		return false;
#else
	//if(true)�̏ꍇtrue��Ԃ��A�����łȂ��ꍇfalse��Ԃ��B
	//�ł���΂��̂܂�if���̏������̒��g��Ԃ��΂����̂ł�
	return(dist <= (c0.radius + c1.radius));
#endif
}

//�~�̕`��
void drawCircle(CircleData data)
{
	DrawCircle(data.x, data.y, data.radius, data.color, true);
}

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//�ꕔ�̊֐���Dxlib_Init()�̑O�Ɏ��s����K�v������
	ChangeWindowMode(true);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	//����ʂɕ`�ʂ��s��
	SetDrawScreen(DX_SCREEN_BACK);

	//�~�̃f�[�^
	CircleData circle[CIRCLE_NUM]; //�z���
	for (int i = 0; i < CIRCLE_NUM; i++)
	{
	circle[i].x = 160.0f + 160.0f * i;
	circle[i].y = 240.0f;
	circle[i].radius = 32.0f;
	circle[i].color = GetColor(255, 255, 255);
	}
	//�v���C���[
	CircleData player;
	player.x = 0.0f;
	player.y = 0.0f;
	player.radius = 16;
	player.color = GetColor(255,255,255);

	// �Q�[�����[�v
	while (ProcessMessage() != -1)
	{
		//���̃t���[���̊J�n�������o���Ă���
		LONGLONG start = GetNowHiPerformanceCount();
		
		// �`����s���O�ɉ�ʂ��N���A����
		ClearDrawScreen();

		//�Q�[���̏���

		int mouseX;
		int mouseY;

		//�}�E�X�̈ʒu���擾����
		GetMousePoint(&mouseX, &mouseY);
		player.x =(float)mouseX;
		player.y =(float)mouseY;

		//�����蔻����Ƃ�
		for (int i = 0; i < CIRCLE_NUM; i++)
		{
		bool isCol = isCollision(player, circle[i]);
		if (isCol)
		{
			//�������Ă���
			circle[i].color = GetColor(255, 0, 0);
		}
		else
		{
			//�������Ă��Ȃ�
			circle[i].color = GetColor(255, 255, 255);

		}
		}
	

		drawCircle(player);
		drawCircle(circle[3]);
//		DrawCircle(circle.x, circle.y ,circle.radius, circle.color, true);

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