#include "DxLib.h"



//定数
namespace
{
    //初期配置
    constexpr int kStartPosX = 320;
    constexpr int kStartPosY = 240;
    //移動速度
    constexpr int kSpeed = 2;

}

class Player
{
public:
    int m_handle;   //グラフィックハンドル
    int m_posX;     //表示座標ｘ
    int m_posY;     //表示座標Ｙ
    bool m_isTurn;  //左右反転フラグ

    //コントラクタ　メモリを確保した時点で勝手に呼ばれる関数
    Player();                   //引数なしコンストラクタ
    Player(int x, int y);       //引数で初期位置を設定できるコンストラクタ

    //メンバー関数
    void init();
    void update();
    void draw();
};
#if false
//Playerクラスのコンストラクタ
Player::Player()
{
    //グラフィックのロード
    m_handle = LoadGraph("data/player.png");
    m_posX = kStartPosX;
    m_posY = kStartPosY;
    //グラフィック反転フラグ
    m_isTurn = false;
}
#endif

Player::Player(int x, int y)
{
    //グラフィックのロード
    m_handle = LoadGraph("data/player.png");
    m_posX = x;
    m_posY = y;
    //グラフィック反転フラグ
    m_isTurn = false;
}


//メンバー関数の実装
//関数名の前にクラス名::を書いてやってこのクラスのdraw関数です、と宣言する
void Player::draw()
{
    if (m_isTurn)
    {
        DrawTurnGraph(m_posX, m_posY, m_handle, false);
    }
    else
    {
        DrawGraph(m_posX, m_posY, m_handle, false);
    }
}

void Player::init()
{
    //グラフィックのロード
    m_handle = LoadGraph("data/player.png");
    m_posX = kStartPosX;
    m_posY = kStartPosY;
    //グラフィック反転フラグ
    m_isTurn = false;
}

//Playerクラスのデストラクタ
Player::~Player()
{
    //メモリが解放されるときに必ず読んでほしい処理を書く
    DeleteGraph(m_handle)
}



//プレイヤーの更新

void Player::update()
{
    int pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);
    if (pad & PAD_INPUT_UP)
    {
        //上キーが押されている
        m_posY -= kSpeed;  //上方向に移動させる
    }
    if (pad & PAD_INPUT_DOWN)
    {
        //上キーが押されている
        m_posY += kSpeed;  //上方向に移動させる
    }
    if (pad & PAD_INPUT_LEFT)
    {
        //上キーが押されている
        m_posX -= kSpeed;  //上方向に移動させる
        m_isTurn = false;
    }
    if (pad & PAD_INPUT_RIGHT)
    {
        //上キーが押されている
        m_posX += kSpeed;  //上方向に移動させる
        m_isTurn = true;
    }
}

//プレイヤーの描画

void drawPlayer(Player player)

{
    if (player.m_isTurn)
    {
        DrawTurnGraph(player.m_posX, player.m_posY, player.m_handle, false);   //左右反転
    }
    else
    {
        DrawGraph(player.m_posX, player.m_posY, player.m_handle, false);
    }
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

    //プレイヤー
    Player player;
 //   Player player2(220, 240); //ちょっと古い
    Player player2{ 420,340 };  //最新は波かっこ

    //プレイヤーの初期化
    player.init();
    player2.init();
    Player playerTbl[4] =
    {
        Player(),
        Player(100, 200),
        Player(200, 200),
    };

        // ゲームループ
        while (ProcessMessage() != -1)
        {
            //このフレームの開始時刻を覚えておく
            LONGLONG start = GetNowHiPerformanceCount();
            // 描画を行う前に画面をクリアする
            ClearDrawScreen();
            //ゲーム処理
            player.update();
            player2.update();

            player.update();
            //描画
            player.draw();
            player2.draw();

            for (int i = 0; i < 4; i++)
            {
                playerTbl[i].draw();
            }
            //drawPlayer(player);
            player.draw();
            player2.draw();

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


    //グラフィックをメモリから消除
    DeleteGraph(player.m_handle);
    DxLib_End();                // ＤＸライブラリ使用の終了処理
    return 0;                // ソフトの終了 
}