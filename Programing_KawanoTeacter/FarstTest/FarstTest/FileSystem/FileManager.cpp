#include "FileManager.h"
#include <DxLib.h>
#include "ImageFile.h"

std::shared_ptr<File> FileManager::LoadGraphic(const std::wstring& path)
{
    // �����A���[�h�ς݂̃t�@�C�����������炻�̃t�@�C����Ԃ�
    if (m_fileTable.find(path) != m_fileTable.end())
    {
        return m_fileTable.at(path);
    }
    int handle = LoadGraph(path.c_str());

    return ;
}

void FileManager::Delete(const std::wstring& path)
{
}
