#pragma once
//�Ȃ��킴�킴�N���X�̃����o��private�ɂ���́H
//���ׂ�public�Ȃ�֗��ł́H

//const�@�l��������Ȃ��悤�ɂ���
//�l�������ꂽ�ق����֗��@���ԈႦ�Ă����邱�Ƃ�h�����߂�const�ł�������������Ȃ��悤�ɂ���

//�E�N���X�̏����̓N���X���g�ɂ�点��
//�E�O���珟��ɒl���������Ȃ��悤�ɂ���
//��,�G���\���ɂ������@����ɉ�ʔ����̍��W�Ɉړ�������A�݂����Ȃ��Ƃ���������@���G�͐����Ă���

class Enemy
{
public:
	//�R���g���X�^�A�f�X�g���N�^�͓���Ȃ��Ƃ����Ȃ�����public
	Enemy();
	~Enemy();

	//�N���X�O����g�������i�����WIN�@MAIN�Ŏg���j���̂�public
	void init();
	//	void update();
	void draw();

	//�N���X�O���烁���o�ϐ���ύX�������ꍇ��puclic�ȃ����o�֐���ʂ�
	void setPos(int x, int y);


private:
	//�����o�ϐ��͂��ׂ�private
	int m_handle;
	int m_posX;
	int m_posY;
};