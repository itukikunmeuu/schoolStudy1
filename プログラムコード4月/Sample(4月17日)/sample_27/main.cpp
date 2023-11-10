#include "DxLib.h"


//クラス宣言
class Enemy
{
	//メンバ変数、メンバ関数にはprivate,publicという属性がある
	//メンバ変数は、

	//public:もprivate:も書いてない場所に書いたメンバーはprivateメンバ
	int m_pub000;

	//private:よりもあとに書いたメンバ(変数、関数)はprivateメンバ
private:
	int m_pri000;  //privateメンバ

	//private:よりもあとに書いたメンバ(変数、関数)はprivateメンバ
public:
	int m_pub00; //privateメンバ
	void pubFunc();

	//pribate:public　何度かいてもよい
private:
	int m_pri003; //privateメンバ
	void ppriFunc();


public:	//外部からアクセス可能にする

	//メンバ変数名はそのプログラムを見た人が見たいだけでこれはメンバ変数
	//とわかるように名前を付けることが多い
	//私は変数名の前に　m_　を付けます　      handle -> m_handle
	//ほかに目変数名の前に　＿　をつける人や　handle -> _handle
	//変数名の最後に　＿　をつける人もいます　handle -> handle_
	//ルールはどれでも構いませんが、必ず統一してください
	//チーム政策の場合はチームでどのようなルールにするのか決めてください
	int m_handle;		//グラフィックハンドル
	int m_posX;		//X座標
	int m_posY;		//Y座標
	int m_moveX;		//X方向の移動量
	int m_moveY;		//Y方向の移動量

	//コンストラクタ
	//実態が作成されたとき（メモリが確保されたとき）自動的に呼ばれる関数
	Enemy();
	//デストラクタ
	//メモリが解放される時に自動的に呼ばれる関数
//	//終了時に忘れずにやっておかないといけない
	//戻り値なし、引数も設定できない、関数はクラス名の前に～を書く
	~Enemy();

	//クラスは構造体に加えてクラス内で関数を作成することができる
	//クラス内の関数をメンバ関数という
	void init();
//	void update();
	void draw();
};

//Enemyクラスのコンストラク
//コンストラクタで値を初期化したい場合は特別な書き方がある
//コンストラクタ初期化子という

//コンストラクタ初期化子に関して
//コンストラクタ初期菓子を使っても使わなくても結果は同じ
//だがコンストラクタ初期菓子を使う
//・処理速度的に有利
//・コンストラクタ初期菓子わかってますアピール
Enemy::Enemy()
{
	m_handle = LoadGraph("data/obj.png");
	m_posX = (320);
	m_posY = (240);
	m_moveX = (0);
	m_moveY = (0);
	//値を初期化したり、0クリアしたりする
	// 
	//メンバ関数から同じクラス内のメンバ変数にアクセスできる
	//アクセスする際はenemy.handleのような書き方をしなくても、handleのみでアクセスできる

	//メンバ変数はコンストラクタ初期化子で初期化するようにする
	m_handle = LoadGraph("data/obj.png");
//	m_posX = 320;
//	m_posY = 240;
//	m_moveX = 0;
//	m_moveY = 0;
	
}

//Enemyクラスのデストラクタ
Enemy :: ~Enemy()
{
	//終了時に忘れずにやっておかないといけない処理を書く
	DeleteGraph(m_handle);
}

//メンバ関数を実行したいときは関数名の前に　クラス名　::を書
void Enemy :: init()
{
}

void Enemy :: draw()
{
	//クラス内からならprivateメンバ、publicメンバともにアクセス可能

	DrawGraph(m_posX, m_posY, m_handle, false);
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

	SetDrawScreen(DX_SCREEN_BACK);

	Enemy enemy;
	//メンバ関数の呼び出し
	//メンバ変数と同じく　.(ドット)でつないでメンバ関数を呼び出す
	enemy.init();

	//publicメンバにはクラス外からアクセスできる
	//privateメンバにはクラス外からアクセスできない
	//クラス外？　そのクラスのメンバ関数内はクラス内、それ以外はクラス外
	//ここはEnemyクラスの外


	// ゲームループ
	while (ProcessMessage() != -1)
	{
		//このフレームの開始時刻を覚えておく
		LONGLONG start = GetNowHiPerformanceCount();
		
		// 描画を行う前に画面をクリアする
		ClearDrawScreen();

		//

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