#include<iostream>
using namespace std;

//�����Ȃ�
void printMsg(void)
{
	cout << "test" << endl;
}
//NG �߂�l���Ⴄ�����ł̓����֐��͍쐬�ł��Ȃ�
//void printMsg(void)
//{
//	cout << "test2" << endl;
//}

//�����̒l���Ⴆ�Γ����֐����̊֐����쐬�ł���
//void printMsg(int score = 50) //ng �������ȗ������ꍇ�A�����Ȃ��ƌ����������Ȃ��̂�NG
void printMsg(int num,int score = 50)
{
	cout  <<  "�e�X�g�̓_"  << score << endl;
}

void printMsg(int num)
{
	cout << "num:" << num << endl;
}

//C++�ł͊֐��̈����Ƀf�t�H���g�̒l��ݒ�ł���
struct Player
{
	int hp;
	int mp;
};

//�������̌�Ɂ@���@50�̂悤�ɏȗ������ꍇ�ɐݒ肳��鐔�l���w��ł���
//������f�t�H���g�����Ƃ���
//�f�t�H���g�������ݒ肳��Ă���ꍇ�A�������ȗ����邱�Ƃ��ł���
//�ȗ������ꍇ�A�������ɂ͐ݒ肵���l������
void initPlayer(Player& player, int hp = 100, int mp = 50)
{
	player.hp = hp;
	player.mp = mp;
}

int main()
{

	printMsg();
	printMsg(10);
	printMsg(10,50);
	/*
	Player player;
	initPlayer(player,200,0);

	//�L�����N�^�[�I���\
	//100��ރL�����N�^�[������
	//1�̗͎̂͑����@HP200�AMP0
	//1�͖̂��@�g���@HP50�AMP100
	//����ȊO��98�̂�HP100�AMP50

	cout << "HP:" << player.hp << endl;
	cout << "HP:" << player.mp << endl;
	*/
	return 0;
}

