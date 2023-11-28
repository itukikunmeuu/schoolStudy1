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
	m_bgHandle = LoadGraph("data/Bg_.png");
	assert(m_bgHandle != -1);

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
	DeleteGraph(m_gameScreenHandle);

	//メモリ削除
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


	////画面揺れのフレームカウントダウン
	//m_wipeFrame--;
}

void SceneMain::Draw() const
{

	//描画先スクリーンをクリアする
	///ClearDrawScreen();

	m_pPlayer->Draw();

	//デバック表示
	DrawString(8, 8, "SceneMain", 0xffffff);

	Vec2 PlayerPos = m_pPlayer->GetPos();
	DrawFormatString(8, 24, 0xffffff,
		"プレイヤーの座標(%.2f,%.2f)", PlayerPos.x, PlayerPos.y);
	
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
