#include "DxLib.h"
#include"cassert"

void Sub(int& left, const int& right)
{
	left = right;
}

void Function()
{
	int j = 0;
	for (int i = 0; i < 10000; ++i)
	{
		Sub(j, i);
	}

}

int MyLoadGraph(const wchar_t* path)
{
	int handle = LoadGraph(path);
		assert(handle > 0);
		return handle;
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	ChangeWindowMode(true); //��t���X�N���[��
	if (DxLib_Init() == -1)
	{
		//�������Ɏ��s
		return -1; //���̃A�v���ُ͈�I�����܂���
	}
	Function();




	
	//���͕\�������`���ɂ�2���̃X�N���[��������܂�
	//����������Ńt���b�v�i����ւ��j
	//��ʂ̂�������Ȃ�����

	int a[] = { 1,3,4,8,2,5,3,6,2 };

	auto result = SetDrawScreen(DX_SCREEN_BACK);

	a[5]++;

	while (ProcessMessage() != -1)
	{
		ClearDrawScreen();
		ScreenFlip();
	}
	DxLib_End();
	return 0; //���̃A�v���͐���ɍ쓮���܂���
} 