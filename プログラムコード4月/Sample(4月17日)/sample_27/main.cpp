#include "DxLib.h"


//�N���X�錾
class Enemy
{
	//�����o�ϐ��A�����o�֐��ɂ�private,public�Ƃ�������������
	//�����o�ϐ��́A

	//public:��private:�������ĂȂ��ꏊ�ɏ����������o�[��private�����o
	int m_pub000;

	//private:�������Ƃɏ����������o(�ϐ��A�֐�)��private�����o
private:
	int m_pri000;  //private�����o

	//private:�������Ƃɏ����������o(�ϐ��A�֐�)��private�����o
public:
	int m_pub00; //private�����o
	void pubFunc();

	//pribate:public�@���x�����Ă��悢
private:
	int m_pri003; //private�����o
	void ppriFunc();


public:	//�O������A�N�Z�X�\�ɂ���

	//�����o�ϐ����͂��̃v���O�����������l�������������ł���̓����o�ϐ�
	//�Ƃ킩��悤�ɖ��O��t���邱�Ƃ�����
	//���͕ϐ����̑O�Ɂ@m_�@��t���܂��@      handle -> m_handle
	//�ق��ɖڕϐ����̑O�Ɂ@�Q�@������l��@handle -> _handle
	//�ϐ����̍Ō�Ɂ@�Q�@������l�����܂��@handle -> handle_
	//���[���͂ǂ�ł��\���܂��񂪁A�K�����ꂵ�Ă�������
	//�`�[������̏ꍇ�̓`�[���łǂ̂悤�ȃ��[���ɂ���̂����߂Ă�������
	int m_handle;		//�O���t�B�b�N�n���h��
	int m_posX;		//X���W
	int m_posY;		//Y���W
	int m_moveX;		//X�����̈ړ���
	int m_moveY;		//Y�����̈ړ���

	//�R���X�g���N�^
	//���Ԃ��쐬���ꂽ�Ƃ��i���������m�ۂ��ꂽ�Ƃ��j�����I�ɌĂ΂��֐�
	Enemy();
	//�f�X�g���N�^
	//���������������鎞�Ɏ����I�ɌĂ΂��֐�
//	//�I�����ɖY�ꂸ�ɂ���Ă����Ȃ��Ƃ����Ȃ�
	//�߂�l�Ȃ��A�������ݒ�ł��Ȃ��A�֐��̓N���X���̑O�Ɂ`������
	~Enemy();

	//�N���X�͍\���̂ɉ����ăN���X���Ŋ֐����쐬���邱�Ƃ��ł���
	//�N���X���̊֐��������o�֐��Ƃ���
	void init();
//	void update();
	void draw();
};

//Enemy�N���X�̃R���X�g���N
//�R���X�g���N�^�Œl���������������ꍇ�͓��ʂȏ�����������
//�R���X�g���N�^�������q�Ƃ���

//�R���X�g���N�^�������q�Ɋւ���
//�R���X�g���N�^�����َq���g���Ă��g��Ȃ��Ă����ʂ͓���
//�����R���X�g���N�^�����َq���g��
//�E�������x�I�ɗL��
//�E�R���X�g���N�^�����َq�킩���Ă܂��A�s�[��
Enemy::Enemy()
{
	m_handle = LoadGraph("data/obj.png");
	m_posX = (320);
	m_posY = (240);
	m_moveX = (0);
	m_moveY = (0);
	//�l��������������A0�N���A�����肷��
	// 
	//�����o�֐����瓯���N���X���̃����o�ϐ��ɃA�N�Z�X�ł���
	//�A�N�Z�X����ۂ�enemy.handle�̂悤�ȏ����������Ȃ��Ă��Ahandle�݂̂ŃA�N�Z�X�ł���

	//�����o�ϐ��̓R���X�g���N�^�������q�ŏ���������悤�ɂ���
	m_handle = LoadGraph("data/obj.png");
//	m_posX = 320;
//	m_posY = 240;
//	m_moveX = 0;
//	m_moveY = 0;
	
}

//Enemy�N���X�̃f�X�g���N�^
Enemy :: ~Enemy()
{
	//�I�����ɖY�ꂸ�ɂ���Ă����Ȃ��Ƃ����Ȃ�����������
	DeleteGraph(m_handle);
}

//�����o�֐������s�������Ƃ��͊֐����̑O�Ɂ@�N���X���@::����
void Enemy :: init()
{
}

void Enemy :: draw()
{
	//�N���X������Ȃ�private�����o�Apublic�����o�Ƃ��ɃA�N�Z�X�\

	DrawGraph(m_posX, m_posY, m_handle, false);
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

	SetDrawScreen(DX_SCREEN_BACK);

	Enemy enemy;
	//�����o�֐��̌Ăяo��
	//�����o�ϐ��Ɠ������@.(�h�b�g)�łȂ��Ń����o�֐����Ăяo��
	enemy.init();

	//public�����o�ɂ̓N���X�O����A�N�Z�X�ł���
	//private�����o�ɂ̓N���X�O����A�N�Z�X�ł��Ȃ�
	//�N���X�O�H�@���̃N���X�̃����o�֐����̓N���X���A����ȊO�̓N���X�O
	//������Enemy�N���X�̊O


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