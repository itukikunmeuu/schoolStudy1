#pragma once
#include <array>
#include<map>
#include<string>

enum class InputType {
	keybd,
	pad,
};
class Input
{
	friend KeyConfigScene;//キーコンフィグからは丸見え


private:
	//コマンド名と入力をペアにしたテーブル
	//キーボードの時はkeybd&key_INPUT〇〇で
	
	std::array<char, 256> m_keyState;
	std::array<char, 256> m_lastKeyState;

	//コマンド名とキーコードをペアにしたテーブル
	std::map<std::string, int>comandTable_;
public:
	Input();
	/// <summary>
	/// 入力の情報を更新する
	/// </summary>
	void Update();
	/// <summary>
	/// 指定のコマンドが押された瞬間なのか
	/// </summary>
	/// <param name="command">コマンド文字列</param>
	/// <returns>true:押された瞬間 / false:押されていないか押しっぱ</returns>
	bool IsTriggered(const char* command) const;
};

