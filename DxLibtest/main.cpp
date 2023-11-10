#include "DxLib.h"





// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(true);


	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}



	//グラフィックデータをメモリに読み込む
	//読み込んだデータを使いたい場合はこの番号を指定してくれ。
	//という数字を返してくれる（ハンドルと呼ばれる）
	//このハンドルを使用して表示するグラフィックを指定する
	int handle = LoadGraph("sai.png");

	DrawGraph(320, 240, handle, 1);

	DrawPixel(320, 240, GetColor(255, 255, 255));	// 点を打つ
	DrawLine(0,120,60,480, GetColor(255, 0, 0));
	DrawLine(0, 240, 120, 560, GetColor(255, 0, 0));
	DrawLine(0, 140, 140, 560, GetColor(255, 0, 0));
	DrawLine(0, 160, 160, 560, GetColor(255, 0, 0));
	DrawLine(0, 180, 180, 560, GetColor(255, 0, 0));


	//色の指定；　GetColor(255,255,255)
	//一つ目の引数　；rgbのr（赤部分）
	//二つ目の引数　；rgbのg（緑部分）
	//三つ目の引数　；rgbのｂ（青部分）
	WaitKey();				// キー入力待ち

	//メモリ上からグラフィックデータを削除する
	//これ以降使わない、という状態になったら必ず削除する
	DeleteGraph(handle);

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}