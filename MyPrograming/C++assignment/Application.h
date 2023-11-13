#pragma once

struct Size
{
	int w;
	int h;
};

/// <summary>
/// アプリケーション全体を管理するクラス
/// シングルトンクラス
/// </summary>
class Application
{
private:
	Size m_windowSize;

	Application();//シングルトンのためprivateに
	//コピー＆代入の禁止
	Application(const Application& app) = delete; //コピーコンストラクタの廃止
	void operator =(const Application& app) = delete; //代入コンストラクタの廃止

	/// <summary>
	/// 後処理を行う
	/// </summary>
	void Terminate();
public:
	/// <summary>
	/// Applicationのシングルトンクラスを返す
	/// </summary>
	/// <returns>Applicationインスタンスの参照を返す</returns>
	static Application& GetInstance()
	{
		static Application instance; //自分自身の政敵オブジェクトを作ります
		return instance;
	}

	bool Init();
	void Run();

	const Size& GetWindowSize() const;
};

