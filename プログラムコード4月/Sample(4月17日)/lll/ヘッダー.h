#pragma once


//�v���g�^�C�v�錾

//������\�����邽�߂̊֐�
void dispWin(void);
//������\�����邽�߂̊֐�
void dispLose(void);
//�O�[�A�`���L�A�p�[��\�����邽�߂̊֐�
void dispHandl(int hand);
//�O�[�����p�[�̂悤�ɕ\������֐�
void dispBattle(int playerHand, int enemyHand);
//2-1 �����̂悤�ȕ\�����s���֐�
void dispResult(int win, int lose);
//�����_���Ȏ�(�O�[���`���L���p�[)�𐶐����ĕԂ��֐�
int createRandHand(void);
//�v���C���[�̎�A�G�̎�������Ƃ��ĕԂ�
//�����G1�@�����G-1�@���������G0��Ԃ�
int getBattleResult(int PlayerHand, int enemyHand);