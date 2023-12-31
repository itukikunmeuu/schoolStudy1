#pragma once
#include "Scene.h"

/// <summary>
/// タイトルシーンクラス
/// </summary>
class TitleScene : public Scene
{
public:
	TitleScene(SceneManager& manager);
	~TitleScene();

	virtual void Update(Input& input);
	virtual void Draw();

private:
	int m_handle=0;
	int m_frame=0;
	//更新メンバ関数ポインタ
	void (TitleScene::* m_updateFunc)(Input&);
	//描画メンバ関数ポインタ
	using DrawFunc_t = void(TitleScene::*)();
	DrawFunc_t m_drawFunc;

	//更新関数
	void FadeInUpdate(Input& input);//フェードイン状態
	void NormalUpdate(Input& input);//通常状態

	void FadeOutUpdate(Input& input);
	

	//描画関数
	void FadeDraw();//フェード中描画
	void NormalDraw();//非フェード中描画
};

