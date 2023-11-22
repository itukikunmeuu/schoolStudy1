#pragma once
/// <summary>
/// アプリケーション全体を管理するクラス
/// シングルトンクラス
/// </summary>
class Application
{
private:
	Application() {};//シングルトンのためにコンストラクタをプライベートにする
	// コピー＆代入の禁止
	Application(const Application& app) = delete;//明示的にコピーコンストラクタをprivateに宣言
	//private: クラス名(const　クラス名& ref)=delete;
	                                             //これをすることでコピーコンストラクタが勝手に走るのを防ぐ
	void operator =(const Application& app) = delete;//代入演算子もついでに廃止

	/// <summary>
	/// 後処理を行う
	/// </summary>
	void Terminate();
public:
	/// <summary>
	/// Applicationのシングルトンインスタンスを返す
	/// </summary>
	/// <returns>Applicationインスタンスの参照を返す</returns>
	static Application& GetInstance();

	bool Init();
	void Run();

};

