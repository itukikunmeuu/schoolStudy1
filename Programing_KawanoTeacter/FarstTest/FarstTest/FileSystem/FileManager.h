#pragma once

#include <unordered_map>	// �}�b�v�p(�t�@�C���p�X�e�[�u���p)
#include <string>			// �t�@�C���p�X���o���Ƃ��悤
#include <memory>			// File��shared_ptr��ێ����Ă����悤

class File;

/// <summary>
/// �t�@�C���̃}�b�v�����A�t�@�C�����Ǘ�����
/// </summary>
class FileManager
{
public:
	// �t�@�C���p�X�e�[�u��
	std::unordered_map<std::wstring, std::shared_ptr<File>>
		m_fileTable;

public:
	std::shared_ptr<File> LoadGraphic(const std::wstring& path);
	void Delete(const std::wstring& path);
};

