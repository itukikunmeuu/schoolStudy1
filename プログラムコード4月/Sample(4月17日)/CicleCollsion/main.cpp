#include "DxLib.h"



// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    //一部の関数はDxlib_Init()の前に実行する必要がある
    ChangeWindowMode(true);



    if (DxLib_Init() == -1)        // ＤＸライブラリ初期化処理
    {
        return -1;            // エラーが起きたら直ちに終了
    }



    SetDrawScreen(DX_SCREEN_BACK);

    int x = 320;
    int moveX = 8;

    // ゲームループ
    while (ProcessMessage() != -1)
    {

        //このフレームの開始時刻を覚えておく
        LONGLONG start = GetNowHiperfoemanceCount();

        // 描画を行う前に画面をクリアする
        ClearDrawScreen();



        //キャラクターの移動
        x += 1;



        // 画面が切り替わるのを待つ
        ScreenFlip();


        //escキーでゲーム終了
        if (CheckHitKey(KEY_INPUT_ESCAPE))
        {
            break;
        }

        //FPS60に固定する
        while (GetNowPerfowmanxeCount() - start < 16667)
        {
            //16.66ミリ秒（16667マイクロ秒）経過するまで待つ
        }
    }

    DxLib_End();                // ＤＸライブラリ使用の終了処理



    return 0;                // ソフトの終了 
}