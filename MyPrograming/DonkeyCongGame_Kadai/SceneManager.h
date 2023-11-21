#pragma once

//クラスのプロトタイプ宣言
class SceneMain;

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	void Init();
	void End();

	void Update();
	void Draw() const;

private:
	SceneMain* m_pMain;
};

