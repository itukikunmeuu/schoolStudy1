#include <DxLib.h>
#include "Input.h"
#include "SceneManager.h"
#include "TitleScene.h"
#include "GamePlayingScene.h"

TitleScene::TitleScene(SceneManager& manager) ://manager_(manager)�@�e�N���X�̏������͂ł��Ȃ�
	Scene(manager)                             //�������t���R���X�g���N�^���Ăяo��
{
	m_handle = LoadGraph(L"./image/title.png");
	m_updateFunc = &TitleScene::FadeInUpdate;
	m_drawFunc = &TitleScene::FadeDraw;
}

TitleScene::~TitleScene()
{
	DeleteGraph(m_handle);
}

void TitleScene::Update(Input& input)
{
	(this->*m_updateFunc)(input);

}

void TitleScene::Draw()
{
	(this->*m_drawFunc)();
}

void TitleScene::FadeInUpdate(Input& input)
{
	m_frame++;
	if (m_frame >= 60)
	{//�J�ڏ����@���̏���
		m_updateFunc = &TitleScene::NormalUpdate;
		m_drawFunc=& TitleScene::NormalDraw;
	}
}

void TitleScene::NormalUpdate(Input& input)
{
	if (input.IsTriggered("OK"))
	{
		m_updateFunc = &TitleScene::FadeOutUpdate;
		m_drawFunc = &TitleScene::FadeDraw;

	}
}

void TitleScene::FadeOutUpdate(Input&input)
{
	m_frame--;
	if (m_frame <= 0)
	{
		m_updateFunc = &TitleScene:: NormalUpdate;
		m_drawFunc = &TitleScene::NormalDraw;
	}

}

void TitleScene::FadeDraw()
{
	DrawString(10, 100, L"TitleScene", 0xffffff);
	DrawGraph(100, 100, m_handle, true);

	int alpha = 255*((float)m_frame / 60.0f);
	SetDrawBlendMode(DX_BLENDMODE_MULA, alpha);
	DrawBox(0, 0, 640, 480, 0x000000, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void TitleScene::NormalDraw()
{
	DrawString(10, 100, L"TitleScene", 0xffffff);
	DrawGraph(100, 100, m_handle, true);
}

