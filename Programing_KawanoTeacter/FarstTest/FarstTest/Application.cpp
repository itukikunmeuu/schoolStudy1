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
    static Application instance;//�������g�̐ÓI�I�u�W�F�N�g�����
    return instance;

}

bool Application::Init()
{
    ChangeWindowMode(true); // �E�B���h�E���[�h�ɂ��܂�
    SetWindowText(L"�������A�N�V�����Q�[��");
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
        input.Update(); // ���͂��X�V
        manager.Update(input);
        manager.Draw();
        ScreenFlip();
    }
    Terminate();
}
