#include <DxLib.h>
#include "Game.h"
#include "SceneMain.h"
#include "Pad.h"

#include "Player.h"

namespace
{
	//移動速度
	constexpr float kSpeed = 3.0f;

	//キャラクターのサイズ
	constexpr int kGraphWidth = 32;
	constexpr int kGraphHeight = 32;

	//半分のサイズ
	constexpr int kGraphHalfWidth = kGraphWidth / 2.0f;
	constexpr int kGraphHalfHeight = kGraphHeight / 2.0f;

	//キャラクターアニメーション
	constexpr int kUseFrame[] = { 0,1,2,1 };

	//アニメーション1コマのフレーム数
	constexpr int kAnimeFrameNum = 12;

	constexpr int kAnimFrameCycle = _countof(kUseFrame) * kAnimeFrameNum;
									// _countof()で配列のサイズを取得できる
									// _countof(kUseFrame)
	//ダメージ演出フレーム数
	constexpr int kDamageFrame = 60;

}

Player::Player(SceneMain* pMain) :
	m_pMain(pMain),
	m_handle(-1),
	m_pos(Game::kScreenWidth / 2,Game::kScreenHeight / 2),
	m_dir(kDirDown),
	m_walkAnimeFrame(kAnimeFrameNum),
	m_damageFrame(0)
{
}

Player::~Player()
{
}

void Player::Init()
{
}

void Player::Update()
{
	//ダメージ演出の進行
	m_damageFrame--;
	if (m_damageFrame < 0) m_damageFrame = 0;

	//パッドの十字キーを使用してプレイヤーを移動させる
	int pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	bool isMove = false; //移動中かどうか

	//移動量を持つようにする
	Vec2 move{ 0.0f,0.0f }; //引数ありコンストラクタは{} ()でもできるが{}のほうがいい

	if (pad & PAD_INPUT_LEFT)
	{
		move.x--;
		///*m_dir = kDirLeft;*/
		isMove = true;
	}
	if (pad & PAD_INPUT_RIGHT)
	{
		move.x++;
		///*m_dir = kDirRight;*/
		isMove = true;
	}
		//正規化
		move.Normalize();
		//長さの変更
		move *= kSpeed;
		//座標にベクトルを足す
		m_pos += move;

		// 縦軸の移動制限
		if (m_pos.y < kGraphHalfHeight)
			m_pos.y = kGraphHalfHeight;
		else if (Game::kScreenHeight - kGraphHalfHeight < m_pos.y)
			m_pos.y = Game::kScreenHeight - kGraphHalfHeight;
		// 横軸の移動制限
		if (m_pos.x < kGraphHalfWidth)
			m_pos.x = kGraphHalfWidth;
		else if (Game::kScreenWidth - kGraphHalfWidth < m_pos.x)
			m_pos.x = Game::kScreenWidth - kGraphHalfWidth;

		//当たり判定の更新
		m_colRect.SetCenter(m_pos.x, m_pos.y, kGraphWidth, kGraphHeight);

		//攻撃,移動関係
		////if (isMove)
		////{
		////	//歩きモーション
		////	m_walkAnimeFrame++;
		////	if (kAnimFrameCycle <= m_walkAnimeFrame)m_walkAnimeFrame = 0;
		////}
		////else
		////{
		////	m_walkAnimeFrame = kAnimeFrameNum;
		////}

	

}

void Player::Draw() const
{
	//ダメージ演出　2フレーム感覚で表示日表示切替
	//0：表示される
	//1：表示される
	//2：非表示
	//3：非表示
	//4：表示させる　...
	//%４することで01230123012301230123...に変換する
	if (m_damageFrame % 4 >= 2) return;

	int animeEle = m_walkAnimeFrame / kAnimeFrameNum;

	int srcX = kGraphWidth * kUseFrame[animeEle];
	int srcY = kGraphHeight * m_dir;

	DrawRectRotaGraph(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y),
		srcX, srcY,
		kGraphWidth, kGraphHeight,
		1.0, 0.0,
		m_handle, true, false);
#ifdef  _DEBUG
	m_colRect.Draw(0x0000ff, false);
#endif //_DEBUG

}

void Player::OnDamage()
{
	//ダメージ演出支柱は再度食らわない
	if (0 < m_damageFrame)return;
	//演出フレーム数を設定する
	m_damageFrame = kDamageFrame;
}
