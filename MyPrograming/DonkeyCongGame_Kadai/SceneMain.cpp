#include<DxLib.h>
#include<cassert>
#include "Pad.h"
#include "Rect.h"

#include "SceneMain.h"

#include "Player.h"

//登場する敵


#include "Game.h"

namespace
{
	//画面がワイプするのにかかるフレーム数
	constexpr int kWipeFrame = 30;
}

SceneMain::SceneMain():
	m_shakeFrame(0),
	m_wipeFrame(0)
{
	//ゲーム画面描画先の生成
	//画面サイズと同じ大きさのグラフィックデータを生成する
	m_gameScreenHandle = MakeScreen(Game::kScreenWidth, Game::kScreenHeight, true);

	//グラフィックのロード
	m_playerHandle = LoadGraph("data/Player_.png");
	assert(m_playerHandle != -1);
	m_enemyHandle = LoadGraph("data/Enemy_.png");
	assert(m_enemyHandle != -1);

	//プレイヤーメモリの確保
	m_pPlayer = new Player{ this };
	m_pPlayer->SetHandle(m_playerHandle);
	
	//背景のメモリの確保

	//敵の準備
	//m_pEnemy(vector何もしなければサイズは0)

	//resize関数でkEnemyMaxだけデータを保存できるようにする
	
}

SceneMain::~SceneMain()
{
	//MakeScreenで生成したグラフィックを削除する
	DeleteGraph(m_playerHandle);
	DeleteGraph(m_enemyHandle);
	DeleteGraph(m_bgHandle);

	//プレイヤーのメモリ開放
	delete m_pPlayer;
	m_pPlayer = nullptr;
	

	//背景のメモリ開放

	//メモリが確保されている敵を探して開放していく
}

void SceneMain::Init()
{
	assert(m_pPlayer);//m_pPlayer == nullptrの場合とまる

	m_pPlayer->Init();
}

void SceneMain::End()
{
}

void SceneMain::Update()
{
	m_pPlayer->Update();

	Rect playerRect = m_pPlayer->GetColRect();


	//画面揺れのフレームカウントダウン
	m_wipeFrame--;
}

void SceneMain::Draw() const
{
	//バックバッファに直接書き込むのではなく
	//自分で生成したグラフィックデータに対して書き込む
	SetDrawScreen(m_gameScreenHandle);

	//描画先スクリーンをクリアする
	ClearDrawScreen();

	//デバック表示
	DrawString(8, 8, "SceneMain", 0xffffff);

	Vec2 PlayerPos = m_pPlayer->GetPos();
	DrawFormatString(8, 24, 0xffffff,
		"プレイヤーの座標(%.2f,%.2f)", PlayerPos.x, PlayerPos.y);

	//ゲーム画面をバックバッファに描画する
	int screenX = 0;
	int screenY = 0;
	if (m_shakeFrame > 0)
	{
		//画面揺れ
		screenX = GetRand(8) - 4;
		screenY = GetRand(8) - 4;
	}

	//毎フレーム加算されてkWipeFrame(30)まで変化する
	float wipeRate = static_cast<float>(m_wipeFrame) / static_cast<float>(kWipeFrame);
	int wopeHeight = Game::kScreenHeight * wipeRate;

	//画面の上から1ラインずつ描画を行っている
	for (int y = 0; y < Game::kScreenHeight; y++)
	{
		int x = y;
		DrawRectGraph(0, y,
			x, y, Game::kScreenWidth, 1,
			m_gameScreenHandle, true, false);
	}
	
}

Vec2 SceneMain::GetNearEemyPos(Vec2 pos) const
{
	//敵がいない場合は適当な座標を返す
	Vec2 result{ 0,0 };
	//最初の敵チェック済みフラグ
	bool isFirst = true;

	clsDx();
	//一番近い敵キャラクターの座標をresultに入れる
	///for(const auto& enemy : m_pEmemy)

	//すべての敵のチェックを行ったのでこいつが一位で確定
	return result;
}

void SceneMain::CreateEnemyLeft()
{
}

void SceneMain::CreateEnemyRight()
{
}

void SceneMain::CreateEnemyToPlayer()
{
}
