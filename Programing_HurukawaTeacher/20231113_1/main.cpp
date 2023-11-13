#include "DxLib.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// 一部の関数はDxLib_Init()の前に実行する必要がある
	ChangeWindowMode(true);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	SetDrawScreen(DX_SCREEN_BACK);

	int screen = MakeScreen(640, 480, true);

	// ゲームループ
	while (ProcessMessage() != -1)
	{
		// このフレームの開始時刻を覚えておく
		LONGLONG start = GetNowHiPerformanceCount();

		// 描画を行う前に画面をクリアする
		ClearDrawScreen();

		// ゲームの処理
		SetDrawScreen(screen);

		//ClearDrawScreen();//画面をクリアしていないので前の状態に上書きされて線が引ける

		//画面を覆う半透明(6%の不透明度)の資格を表示している
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 16);
		DrawBox(0, 0, 640, 480, 0x000000, true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);


		//マウスの現在位置と、左クリックがされているかをチェック
		int mouseX, mouseY;
		GetMousePoint(&mouseX, &mouseY);
		bool isLeft = (GetMouseInput() & MOUSE_INPUT_LEFT);

		//左クリックが押されていたら丸を描画する
		if (isLeft)
		{
			DrawCircle(mouseX, mouseY, 8, GetColor(255, 255, 0), true);
			//DrawCircle(mouseX, mouseY,8,GetColor(255,255,0),true);
		}

		//デフォルトのバックバッファへの書き込みに戻す
		SetDrawScreen(DX_SCREEN_BACK);
		ClearDrawScreen();
		DrawGraph(0, 0, screen, true);

		//10進、16進表記の復習
		int x = 10;  //10進数の10,16進数のaが入る
		int y = 0x10;//0xで始まる数字は16進数
					 //16進数の10、10進数の16が入る

		DrawFormatString(0, 0, 0xffffff, "%d", x); //10
		DrawFormatString(0, 16, 0xffffff, "%d", y);//16
		DrawFormatString(0, 32, 0xffffff, "0x%x", x); //0xa


		// 画面が切り替わるのを待つ
		ScreenFlip();

		// escキーでゲーム終了
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}

		// FPS60に固定する
		while (GetNowHiPerformanceCount() - start < 16667)
		{
			// 16.66ミリ秒(16667マイクロ秒)経過するまで待つ
		}
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}