#pragma once
class Input;
class Scene;
/// <summary>
/// 各シーンの遷移をコントロールするクラス
/// </summary>
class SceneManager
{
private:
	Scene* m_pScene = nullptr;
public:
	~SceneManager();
	/// <summary>
	/// 持っているシーンのUpdate関数を呼び出す
	/// </summary>
	/// <param name="input">入力クラス</param>
	void Update(Input& input);
	/// <summary>
	/// 持っているシーンの描画Draw関数を呼び出す
	/// </summary>
	void Draw();

	/// <summary>
	/// 現在実行中のシーンを引数で指定されたシーンに切り替える
	/// </summary>
	/// <param name="nextScene">次のシーン</param>
	void ChangeScene(Scene* nextScene);
};

