#pragma once
/// <summary>
/// アプリケーション全体を管理するクラス
/// </summary>
class Application
{
private:
	Application(){}
public:
	/// <summary>
	/// Appricationのシングルトンインスタンスの参照を返す
	/// </summary>
	/// <returns>Appricationインスタンス</returns>
	static Application& GetInstance() {
		static Application instance;
		return instance;
	}
	void Init();
	void Run();
};

