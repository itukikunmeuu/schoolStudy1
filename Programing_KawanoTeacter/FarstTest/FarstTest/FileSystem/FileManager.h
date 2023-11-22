#pragma once

#include <unordered_map>	// マップ用(ファイルパステーブル用)
#include <string>			// ファイルパスを覚えとくよう
#include <memory>			// Fileのshared_ptrを保持しておくよう

class File;

/// <summary>
/// ファイルのマップを内包し、ファイルを管理する
/// </summary>
class FileManager
{
public:
	// ファイルパステーブル
	std::unordered_map<std::wstring, std::shared_ptr<File>>
		m_fileTable;

public:
	std::shared_ptr<File> LoadGraphic(const std::wstring& path);
	void Delete(const std::wstring& path);
};

