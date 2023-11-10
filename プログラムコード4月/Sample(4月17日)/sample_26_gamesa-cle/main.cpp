#include "DxLib.h"
#include "player.h"
#include  "enemy.h"
#include <cmath> //数学関数を使用したい



namespace
{
    //敵の数
    constexpr int kEnemyNum = 3;
    //敵の位置情報
    constexpr int kEnemyIntervalX = 160;
}

//プレイヤーと敵が当たっているか確認する
//クラス、構造体と引数として渡す場合はポインタ、参照渡し推奨
//値私だとデータのコピーに時間がかかるため
bool isCollision(Player& player,Enemy& enemy)
{
    //判定に必要なプレイヤー情報の取得
    float playerPosX = (float)player.getPosX();
    float playerPosY = (float)player.getPosY();
    float playerRadius = (float)player.getRadius();

    //判定に必要に敵情報の取得
    float enemyPosX = (float)enemy.getPosX();
    float enemyPosY = (float)enemy.getPosY();
    float enemyRadius = (float)enemy.getRadius();

    //X座標の差
    float dx = playerPosX - enemyPosX;
    //Y座標の差
    float dy = playerPosY - enemyPosY;

    //dx dyのdはdistanceの略称
    //三平方の定理を使用して距離を求めた
    float dist = sqrt(dx * dx + dy * dy);

    if (dist < (playerRadius + enemyRadius))
    {
        //当たった
        return true;
    }
    return false;
}

//プレイヤーの座標を表示する関数
void dispPlayerPos(const Player& player)
{
    int x = player.getPosX();
    int y = player.getPosY();
    DrawFormatString(8, 8, GetColor(255, 255, 255), "(%3d,%3d)", x, y);
}

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

    Player player;
    player.init();



    Enemy enemy[kEnemyNum];

    for (int i = 0; i < kEnemyNum; i++)
    {
        enemy[i].init();
        enemy[i].setPosX(kEnemyIntervalX * (i + 1));
    }



    // ゲームループ
    while (ProcessMessage() != -1)
    {
        //このフレームの開始時刻を覚えておく
        LONGLONG start = GetNowHiPerformanceCount();

        // 描画を行う前に画面をクリアする
        ClearDrawScreen();



        //ゲーム処理
        player.update();
        for (int i = 0; i < kEnemyNum; i++)
        {
            enemy[i].update();




            //当たり判定
            if (isCollision(player,enemy[i]))
            {
                //当たっている
                enemy[i].setHit(true);
            }
            else
            {
                //当たっていない
                enemy[i].setHit(false);
            }
        }
        //描画
        player.draw();
        for (int i = 0; i < kEnemyNum; i++)
        {
            enemy[i].draw();
        }
        dispPlayerPos(player);


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

    DxLib_End();                // ＤＸライブラリ使用の終了処理



    return 0;                // ソフトの終了 
}