#include<iostream>
using namespace std;

//�g���̔z���n���Ă��ꂼ��̕W���̏d��\������֐��@�g��-105��\��
//�ϐ�����|�C���^�̐錾�O��coust�����邱�Ƃł��̒��g��ύX���邱�Ƃ��ł��Ȃ��Ȃ�
void dispStandardWaight(int height[])
{
	cout << "�W���̏d" << endl;
	for (int i = 0; i < 3; i++)
	{
		height[i] -= 105;
		cout << i + 1 << ":" << height[i] << endl;
	}
}

//�g����\������֐�
void dispHeight(const int height[])
{
	cout << "�g��" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << i + 1 << ":" << height[i] << endl;
	}
}

struct Test
{
	int testData0;
	int testData1;
};

//�|�C���^��Q�Ƃ�const�ɂ���Ƃ��̃����o�[��ύX�ł��Ȃ��Ȃ�
void testFunc(const Test* pTest)
{
	pTest->testData0 = 100;
	pTest->testData1 = 100;
}

int main()
{
	Test test;
	testFunc(&test);
#if false
	//�O�l���̐g���f�[�^
	int height[3] = { 170,180,190 };

	//�W���̏d��\������
	dispHeight(height);

	//�g���f�[�^��\������
	dispHeight(height);

	//�W���̏d��\������
	dispStandardWaight()
#endif
	return 0;
}

