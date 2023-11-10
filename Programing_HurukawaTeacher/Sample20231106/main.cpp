#include "DxLib.h"
#include <cmath>

//度数法 degree
//弧度法 radian

//度数法で指定された角度を弧度法に変換する
double DegToRed(double deg)
{
	return DX_PI / 180 * deg;
}

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

	int handle = LoadGraph("data/Arrow.png");

	// ゲームループ
	while (ProcessMessage() != -1)
	{
		// このフレームの開始時刻を覚えておく
		LONGLONG start = GetNowHiPerformanceCount();

		// 描画を行う前に画面をクリアする
		ClearDrawScreen();

		// ゲームの処理
		//sinf(angle);
		//cosf(60.0f);

		////回転させずに描画
		//DrawRotaGraph(64, 64,
		//	1.0, //拡大率
		//	0.0, //回転
		//	handle, 
		//	true, //背景の色を抜くのか抜かないのか 
		//	false );//反転させるか判定させないのか
		//	//少数にfつけるのかなと思いがちですが、fをつけるのはfloat型、これはdoubleなのでfは必要ない

		//円周率DXLIBが#defineで定義してくれているので
		//DxLibでゲームを作るときはそれを使おう

		//DX_PI    　 :doble型で円周率を定義
		//DX_PI_F   　:float型で円周率を定義
		//DX_TWO_PI　 :double型で円周率*2を定義
		//DX_TWO_P_FI :float型で円周率*2を定義

		//０度から45度ずつ回転させて6つ描画をさせる。
		for (int i = 0; i < 6; i++)
		{
			DrawRotaGraph(64 + 96 * i,
				64, //y
				1.0, //拡大率
				//-45.0 * i, //回転
			//	DX_PI, //180度回転させてみる
			//	DX_PI / 2, //90度回転させてみる //+で計算していくと下方向に表示されるので上向きに表示させる際は-DX_PIを使用する
			//	DX_PI / 3, //60度回転
			//	DX_PI / 180 * 22, //22度回転
			//	DX_PI / 180, //1度回転
				DegToRed(-45.0 * i),
				handle,
				true,false);
		}

		for (int i = 0; i < 6; i++)
		{
			//中心点
			int startX = 64 + 96 * i;
			int startY = 64 + 128;
			DrawCircle(startX,
				startY,
				2,GetColor(255, 255, 0), true);

			//中心点から上に表示されている矢印と同じ方向に
			//長さ32の線を引きたい

			//線を伸ばす方法
			double angle = DegToRed(-45.0 * i);
			double moveX = cos(angle) * 32;
			double moveY = sin(angle) * 32;



			//右方向(0度)の方向に線を引く
			int endX = startX + moveX;
			int endY = startY + moveY;
			DrawLine(startX, startY,
				endX, endY,
				GetColor(255, 255, 255));

		}
		
		//回転デモ
		{
			//tempAngleの方向に伸びる線を引く
		static double tempAngle = 0.0;
		tempAngle += 0.02;

		//中心点
		int startX = 320;
		int startY = 400;
		DrawCircle(startX,
			startY,
			2, GetColor(255, 255, 0), true);

		//線で伸びる方向を取得する
		//cosでX成分、sinでY成分を取得する
		double moveX = cos(tempAngle) * 64;
		double moveY = sin(tempAngle) * 64;

		//開始点の座標を足して終点の座標に
		//右方向(0度)の方向に線を引く
		int endX = startX + moveX;
		int endY = startY + moveY;
		DrawLine(startX, startY,
			endX, endY,
			GetColor(255, 255, 255));
		}


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

	DeleteGraph(handle);

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}