#include "Application.h"

#include <DxLib.h>
#include <cassert>

namespace
{
	constexpr int kScreenWidth = 640;
	constexpr int kScreenHeight = 480;
}

///int MyLoadGraph(const wchar_t* path)
///{
	///int handle = LoadGraph(path);
	///assert(handle != -1);
	///return handle;
///}
Application::Application()
{
	m_windowSize = Size{ kScreenHeight,kScreenWidth };
}

void Application::Terminate()
{
	DxLib_End();
}

bool Application::Init()
{
	ChangeWindowMode(true);//ウィンドウズモードにします
	SetGraphMode(m_windowSize.w, m_windowSize.h, 1);
	//SetWindowText(L"ごっついアクションゲーム");
	if (DxLib_Init() == -1)
	{
	return false;
	}
	SetDrawScreen(DX_SCREEN_BACK);

	return true;
}

void Application::Run()
{
}

///const Size& Application::GetWindowSize() const
///{
///	// TODO: return ステートメントをここに挿入します
///}
