#pragma once
#include<array>
#include<map>
#include<string>



class Input
{

private:


public:
	Input();
	/// <summary>
	/// 情報の入力を更新する
	/// </summary>
	void Update();
	/// <summary>
	/// 指定のコマンドが押された瞬間なのか
	/// </summary>
	/// <param name="command"></param>
	/// <returns>true:押された瞬間 / false:押されていないかおしっぱか</returns>
	bool IsTriggered(const char* command) const;
};

