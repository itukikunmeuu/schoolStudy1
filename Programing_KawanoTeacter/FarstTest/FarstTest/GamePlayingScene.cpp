#include <DxLib.h>
#include "Input.h"
#include "SceneManager.h"
#include "GamePlayingScene.h"
#include "GameOverScene.h"

GamePlayingScene::GamePlayingScene(SceneManager& manager) :
	Scene(manager)
{
	m_handle = LoadGraph(L"./image/gameplaying.png");
	m_updateFunc = &GamePlayingScene::FadeInUpdate;
	m_drawFunc = &GamePlayingScene::FadeDraw;
}

GamePlayingScene::~GamePlayingScene()
{
	DeleteGraph(m_handle);
}

void GamePlayingScene::Update(Input& input)
{
	(this->*m_updateFunc)(input);
}

void GamePlayingScene::Draw()
{
	
	(this->*m_drawFunc)();
}

void GamePlayingScene::FadeInUpdate(Input&)
{
	m_frame--;
	if (m_frame <= 0)
	{
		m_updateFunc = &GamePlayingScene::NormalUpdate;
		m_drawFunc = &GamePlayingScene::NormalDraw;
	}
}

void GamePlayingScene::NormalUpdate(Input& input)
{
	if (input.IsTriggered("OK"))
	{
		m_updateFunc = &GamePlayingScene::FadeOutUpdate;
		m_drawFunc = &GamePlayingScene::FadeDraw;
	}
}

void GamePlayingScene::FadeOutUpdate(Input& input)
{
	m_frame++;
	if (m_frame >= 60)
	{
		m_manager.ChangeScene(new GamePlayingScene(m_manager));
	}
	
}

void GamePlayingScene::FadeDraw()
{
	DrawString(10, 100, L"GamePlayingScene", 0xffffff);
	DrawGraph(100, 100, m_handle, true);
	int alpha = 255*(static_cast<float>(m_frame)/60.0f);
	SetDrawBlendMode(DX_BLENDMODE_MULA, alpha);
	DrawBox(0, 0, 640, 480, 0x000000, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void GamePlayingScene::NormalDraw()
{
	DrawString(10, 100, L"GamePlayingScene", 0xffffff);
	DrawGraph(100, 100, m_handle, true);
}
