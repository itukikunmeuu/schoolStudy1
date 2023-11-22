#pragma once
#include <string>

// �}�l�[�W�����Ăׂ�悤��
class FileManager;

class File
{
	friend FileManager;

public:
	File(FileManager& manager);
	virtual ~File();

	int GetHandle() const;
	virtual void Delete() = 0;

protected:
	FileManager& m_manager;
	int m_handle;
	int m_count;
	bool m_isEternal;
	std::wstring m_path;
};

