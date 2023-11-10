#include "DxLib.h"
#include<cmath>

//当たり判定をとる円の数
#define CIRCLE_NUM 3

//円のデータを構造体にまとめる
typedef struct CircleData
{
	//メンバをここに書く
	float x;			//x座標
	float y;			//Y座標
	float radius;		//半径
	unsigned int color;	//色
}CircleData;

//参照型の復習
//プレイヤーを動かすのを関数化
//関数内でマウスカーソルの位置をとり、引数として渡されたCircleDataの座標に設定する
void updatePlayer(CircleData* pPlayer)
{
	//ゲームの処理
	int mouseX;
	int mouseY;

	//マウスの位置を取得する
	GetMousePoint(&mouseX, &mouseY);
	pPlayer->x = (float)mouseX;
	pPlayer->y = (float)mouseY;
}

//円のデータを二つ渡して当たっているかあたっていないかを判定する関数
bool isCollision(CircleData c0, CircleData c1)
{
	//1.判定をとりたい各円の中心の距離を求める
		//ｘ座標の距離　c0.x - c1.xl
		//ｘ座標の距離  c0.y - c1.yl
	float dx = c0.x - c1.x;
	float dy = c0.y - c1.y;
	float dist(dx * dx + dy * dy);
	//2.半径の合計と距離を比較してあたりをとる
#if false
	if (dist < (c0.radius + c1.radius))
	{
		//当たっている
		return true;
	}
		//当たっていない
		return false;
#else
	//if(true)の場合trueを返す、そうでない場合falseを返す。
	//であればそのままif文の条件文の中身を返せばいいのでは
	return(dist <= (c0.radius + c1.radius));
#endif
}

//円の描写
void drawCircle(CircleData data)
{
	DrawCircle(data.x, data.y, data.radius, data.color, true);
}

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//一部の関数はDxlib_Init()の前に実行する必要がある
	ChangeWindowMode(true);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	//裏画面に描写を行う
	SetDrawScreen(DX_SCREEN_BACK);

	//円のデータ
	CircleData circle[CIRCLE_NUM]; //配列に
	for (int i = 0; i < CIRCLE_NUM; i++)
	{
	circle[i].x = 160.0f + 160.0f * i;
	circle[i].y = 240.0f;
	circle[i].radius = 32.0f;
	circle[i].color = GetColor(255, 255, 255);
	}
	//プレイヤー
	CircleData player;
	player.x = 0.0f;
	player.y = 0.0f;
	player.radius = 16;
	player.color = GetColor(255,255,255);

	// ゲームループ
	while (ProcessMessage() != -1)
	{
		//このフレームの開始時刻を覚えておく
		LONGLONG start = GetNowHiPerformanceCount();
		
		// 描画を行う前に画面をクリアする
		ClearDrawScreen();

		//ゲームの処理

		int mouseX;
		int mouseY;

		//マウスの位置を取得する
		GetMousePoint(&mouseX, &mouseY);
		player.x =(float)mouseX;
		player.y =(float)mouseY;

		//当たり判定をとる
		for (int i = 0; i < CIRCLE_NUM; i++)
		{
		bool isCol = isCollision(player, circle[i]);
		if (isCol)
		{
			//当たっている
			circle[i].color = GetColor(255, 0, 0);
		}
		else
		{
			//当たっていない
			circle[i].color = GetColor(255, 255, 255);

		}
		}
	

		drawCircle(player);
		drawCircle(circle[3]);
//		DrawCircle(circle.x, circle.y ,circle.radius, circle.color, true);

		// 画面が切り替わるのを待つ
		ScreenFlip();

		//escキーで終了
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}

		//FPS60に固定する
		while (GetNowHiPerformanceCount() - start < 16667)
		{
		
		}


	}
	
	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}