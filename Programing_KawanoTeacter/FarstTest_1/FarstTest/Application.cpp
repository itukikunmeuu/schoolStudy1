#include "Application.h"
#include "SceneManager.h"
#include "TitleScene.h"
#include "Input.h"

#include <DxLib.h>
#include <cassert>

int MyLoadGraph(const wchar_t* path)
{
    int handle = LoadGraph(path);
    assert(handle != -1);
    return handle;
}

void Application::Terminate()
{
    DxLib_End();
}

Application& Application::GetInstance()
{
    static Application instance;//自分自身の静的オブジェクトを作る
    return instance;

}

bool Application::Init()
{
    ChangeWindowMode(true); // ウィンドウモードにします
    SetWindowText(L"ごっついアクションゲーム");
    if (DxLib_Init() == -1)
    {
        return false;
    }
    SetDrawScreen(DX_SCREEN_BACK);

    return true;
}

void Application::Run()
{
    SceneManager manager;
    manager.ChangeScene(new TitleScene(manager));
    Input input;
    while (ProcessMessage() != -1)
    {
        ClearDrawScreen();
        input.Update(); // 入力を更新
        manager.Update(input);
        manager.Draw();
        ScreenFlip();
    }
    Terminate();
}
