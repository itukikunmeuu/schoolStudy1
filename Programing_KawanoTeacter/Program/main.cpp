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
	ChangeWindowMode(true); //非フルスクリーン
	if (DxLib_Init() == -1)
	{
		//初期化に失敗
		return -1; //このアプリは異常終了しました
	}
	Function();




	
	//実は表示される描画先には2枚のスクリーンがあります
	//これを高速でフリップ（入れ替え）
	//画面のちらつきをなくして

	int a[] = { 1,3,4,8,2,5,3,6,2 };

	auto result = SetDrawScreen(DX_SCREEN_BACK);

	a[5]++;

	while (ProcessMessage() != -1)
	{
		ClearDrawScreen();
		ScreenFlip();
	}
	DxLib_End();
	return 0; //このアプリは正常に作動しました
} 