#include "KeyConfigScene.h"
#include "PauseScene.h"
#include <DxLib.h>
#include "../Input.h"
#include "../Application.h"
#include "SceneManager.h"

namespace
{
	constexpr int kAppeaInterval = 60;
}

KeyConfigScene::KeyConfigScene(SceneManager& mgr) : Scene(mgr)
{
	m_updateFunc = &KeyConfigScene::AppearUpdate;
	m_drawFunc = &KeyConfigScene::ExpandDraw;
}

void KeyConfigScene::Update(Input& input)
{
	(this->*m_updateFunc)(input);
}

void KeyConfigScene::Draw()
{
	(this->*m_drawFunc)();
}

void KeyConfigScene::AppearUpdate(Input&)
{
	m_frame++;
	if (kAppeaInterval <= m_frame)
	{
		m_updateFunc = &KeyConfigScene::NormalUpdate;
		m_drawFunc = &KeyConfigScene::NormalDraw;
	}
}

void KeyConfigScene::NormalUpdate(Input& input)
{
	if (input.IsTriggered("pause"))
	{
		m_updateFunc = &KeyConfigScene::DisappearUpdate;
		m_drawFunc = &KeyConfigScene::ExpandDraw;
		m_frame = ;
	}
	else if()
	{
		+

	}
}

void KeyConfigScene::DisappearUpdate(Input&)
{
	m_frame--;
	if (m_frame == 0)
	{
		m_manager.PopScene();
	}
}

void KeyConfigScene::ExpandDraw()
{
	Application& app = Application::GetInstance();
	const auto& size = app.GetWindowSize();

	int halfHeight = (size.h - 100) / 2;
	int centerY = size.h / 2;

	float rate = static_cast<float>(m_frame) / kAppeaInterval;	// åªç›ÇÃéûä‘ÇÃäÑçá(0.0Å`1.0)
	int currentHalfHeight = rate * halfHeight;

	SetDrawBlendMode(DX_BLENDMODE_MUL, 255);
	// ÇøÇÂÇ¡Ç∆à√Ç¢ãÈå`Çï`âÊ
	DrawBox(50, centerY - currentHalfHeight, size.w - 50, centerY + currentHalfHeight,
		0x888888, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	DrawString(100, 100, L"Pause Scene", 0xffffff);

	DrawBox(50, centerY - currentHalfHeight, size.w - 50, centerY + currentHalfHeight,
		0xffffff, false);
}

void KeyConfigScene::NormalDraw()
{
	Application& app = Application::GetInstance();
	const auto& size = app.GetWindowSize();
	SetDrawBlendMode(DX_BLENDMODE_MUL, 255);
	// ÇøÇÂÇ¡Ç∆à√Ç¢ãÈå`Çï`âÊ
	DrawBox(50, 50, size.w - 50, size.h - 50,
		0x888888, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	DrawString(100, 100, L"Pause Scene", 0xffffff);

	DrawBox(50, 50, size.w - 50, size.h - 50,
		0xffffff, false);

	DrawCommandList();
}

void KeyConfigScene::DrawCommandList()
{
}
