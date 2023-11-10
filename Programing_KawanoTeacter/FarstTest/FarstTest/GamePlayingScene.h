#pragma once
#include "Scene.h"
class GamePlayingScene : public Scene
{
public:
    GamePlayingScene(SceneManager& manager);
    ~GamePlayingScene();
    virtual void Update(Input& input);
    virtual void Draw();
private:
    int m_handle=0;
    int m_frame=0;

    using UpdateFunc_t = void(GamePlayingScene::*)(Input&);
    using DrawFunc_t = void(GamePlayingScene::*)();

    UpdateFunc_t m_updateFunc = nullptr;
    DrawFunc_t m_drawFunc = nullptr;

  
    //更新関数
    void FadeInUpdate(Input& input);//フェードイン状態
    void NormalUpdate(Input& input);//通常状態

    void FadeOutUpdate(Input& input);

    //描画関数
    void FadeDraw();//フェード中描画
    void NormalDraw();//非フェード中描画
};

