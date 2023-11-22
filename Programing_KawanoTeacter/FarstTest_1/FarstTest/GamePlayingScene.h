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

  
    //�X�V�֐�
    void FadeInUpdate(Input& input);//�t�F�[�h�C�����
    void NormalUpdate(Input& input);//�ʏ���

    void FadeOutUpdate(Input& input);

    //�`��֐�
    void FadeDraw();//�t�F�[�h���`��
    void NormalDraw();//��t�F�[�h���`��
};

