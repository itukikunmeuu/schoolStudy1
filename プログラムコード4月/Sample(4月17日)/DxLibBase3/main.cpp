
#include "DxLib.h"



#define ENEMY_NUM    5



        typedef struct Player
    {
        int handle;
        float x;
        float y;
    }Player;




    void drawPlayer(Player player)
    {
        DrawGraph((int)player.x, (int)player.y, player.handle, 0);



    }



    typedef struct Enemy
    {
        int handle;
        float x;
        float y;
        float moveX;
        float moveY;

    }Enemy;



    // プログラムは WinMain から始まります
    int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
    {
        // 一部の関数はDxLib_Init()の前に実行する必要がある
        ChangeWindowMode(1);



        if (DxLib_Init() == -1)        // ＤＸライブラリ初期化処理
        {
            return -1;            // エラーが起きたら直ちに終了
        }



        SetDrawScreen(DX_SCREEN_BACK);



        Player player;



        // プレイヤー関連の情報
        player.handle = LoadGraph("data/player.png");
        player.x = 320.0f;
        player.y = 240.0f;



        // 敵関連の情報
    //    int enemyHandle = LoadGraph("data/enemy.png");
        int tempHandle = LoadGraph("data/enemy.png");



        Enemy enemy;



        enemy.handle[ENEMY_NUM];
        float enemyX[ENEMY_NUM];
        float enemyY[ENEMY_NUM];
        float enemyMoveX[ENEMY_NUM];
        float enemyMoveY[ENEMY_NUM];
        // 敵の初期化
        for (int i = 0; i < ENEMY_NUM; i++)
        {
            enemyX[i] = (float)(GetRand(640 - 32));
            enemyY[i] = (float)(GetRand(480 - 32));
            enemyMoveX[i] = 2.5f;
            if (GetRand(1))    enemyMoveX[i] *= -1.0f;
            enemyMoveY[i] = 2.5f;
            if (GetRand(1))    enemyMoveY[i] *= -1.0f;
        }



        // ゲームループ
        while (ProcessMessage() != -1)
        {
            // 描画を行う前に画面をクリアする
            ClearDrawScreen();



            // update
            int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
            if ((padState & PAD_INPUT_UP) != 0)        // 上キー押されている
            {
                player.y -= 2.5f;
                if (player.y < 0)    // 画面外に出ようとした
                {
                    player.y = 0;
                }
            }
            if ((padState & PAD_INPUT_DOWN) != 0)    // 下キー押されている
            {
                player.y += 2.5f;
                if (player.y > 480 - 32)
                {
                    player.y = 480 - 32;
                }
            }
            if ((padState & PAD_INPUT_LEFT) != 0)    // 左キー押されている
            {
                player.x -= 2.5f;
                if (player.x < 0)
                {
                    player.x = 0;
                }
            }
            if ((padState & PAD_INPUT_RIGHT) != 0)    // 右キー押されている
            {
                player.x += 2.5f;
                if (player.x > 640 - 32)
                {
                    player.x = 640 - 32;
                }
            }



            // 敵のupdate
            for (int i = 0; i < ENEMY_NUM; i++)
            {
                enemyX[i] += enemyMoveX[i];
                enemyY[i] += enemyMoveY[i];
                if (enemyX[i] < 0)
                {
                    enemyX[i] = 0;
                    enemyMoveX[i] *= -1.0f;
                }
                if (enemyX[i] > 640 - 32)
                {
                    enemyX[i] = 640 - 32;
                    enemyMoveX[i] *= -1.0f;
                }
                if (enemyY[i] < 0)
                {
                    enemyY[i] = 0;
                    enemyMoveY[i] *= -1.0f;
                }
                if (enemyY[i] > 480 - 32)
                {
                    enemyY[i] = 480 - 32;
                    enemyMoveY[i] *= -1.0f;
                }
            }
            // draw
            drawPlayer(player);
            // 敵の描画
            for (int i = 0; i < ENEMY_NUM; i++)
            {
                enemyHandle[i] = tempHandle;
                DrawGraph((int)enemyX[i], (int)enemyY[i], enemyHandle[i], 0);
            }



            // 画面が切り替わるのを待つ
            ScreenFlip();
        }



        DeleteGraph(player.handle);
        DeleteGraph(tempHandle);



        DxLib_End();                // ＤＸライブラリ使用の終了処理



        return 0;                // ソフトの終了 
    }