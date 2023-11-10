[9:45] 江藤　沙空

#include "DxLib.h"





typedef struct Pos



{



    float x;



    float y;



}Pos;





// 構造体の宣言



// プレイヤー管理用の構造体



typedef struct Player



{



    int handle;



    Pos pos;



}Player;





// プレイヤーを描面するための関数



void drawPlayer(Player pl)



{



    //    player.handle;



    //    player.pos.x;



    //    player.pos.y;



    DrawGraph((int)pl.pos.x, (int)pl.pos.y, pl.handle, 0);



}





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





    // プレイヤー関連の情報



    Player player;





    player.handle = LoadGraph("data/player.png");    // vcxprojと同じフォルダにある画像を読み込む



    player.pos.x = 320.0f;



    player.pos.y = 240.0f;







    // ゲームループ



    while (ProcessMessage() != -1)



    {



        // 描画を行う前に画面をクリアする



        ClearDrawScreen();





        // update



        int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);



        if ((padState & PAD_INPUT_UP) != 0)        // 上キー押されている



        {



            player.pos.y -= 2.5f;



            if (player.pos.y < 0)    // 画面外に出ようとした



            {



                player.pos.y = 0;



            }



        }



        if ((padState & PAD_INPUT_DOWN) != 0)    // 下キー押されている



        {



            player.pos.y += 2.5f;



            if (player.pos.y > 480 - 32)



            {



                player.pos.y = 480 - 32;



            }



        }



        if ((padState & PAD_INPUT_LEFT) != 0)    // 左キー押されている



        {



            player.pos.x -= 2.5f;



            if (player.pos.x < 0)



            {



                player.pos.x = 0;



            }



        }



        if ((padState & PAD_INPUT_RIGHT) != 0)    // 右キー押されている



        {



            player.pos.x += 2.5f;



            if (player.pos.x > 640 - 32)



            {



                player.pos.x = 640 - 32;



            }



        }





        // draw



        DrawGraph((int)player.pos.x, (int)player.pos.y, player.handle, 0);



        drawPlayer(player);





        // 画面が切り替わるのを待つ



        ScreenFlip();



    }





    DeleteGraph(player.handle);





    DxLib_End();                // ＤＸライブラリ使用の終了処理





    return 0;                // ソフトの終了



}